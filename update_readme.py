#!/usr/bin/env python3
"""
CSES Repository Progress Tracker & README Updater
Automatically scans solution directories, calculates progress metrics,
and updates the tracker section in README.md.
"""

import os
import re
import sys
import subprocess
from pathlib import Path

# Ensure UTF-8 output encoding across Windows / Linux / macOS
if sys.stdout and hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8")

CATEGORIES = [
    ("01", "Introductory Problems", "01-Introductory-Problems", 24),
    ("02", "Sorting and Searching", "02-Sorting-and-Searching", 35),
    ("03", "Dynamic Programming", "03-Dynamic-Programming", 23),
    ("04", "Graph Algorithms", "04-Graph-Algorithms", 36),
    ("05", "Range Queries", "05-Range-Queries", 25),
    ("06", "Tree Algorithms", "06-Tree-Algorithms", 16),
    ("07", "Mathematics", "07-Mathematics", 37),
    ("08", "String Algorithms", "08-String-Algorithms", 21),
    ("09", "Geometry", "09-Geometry", 16),
    ("10", "Advanced Techniques", "10-Advanced-Techniques", 25),
    ("11", "Additional Problems", "11-Additional-Problems", 142),
]

TOTAL_TARGET = 400
EXTENSIONS = {".cpp", ".cc", ".cxx", ".c"}
README_PATH = Path(__file__).resolve().parent / "README.md"


def count_solutions(folder: str, include_untracked: bool = False) -> int:
    """
    Count solution files in the given folder.
    By default in a git repository, counts git-tracked solutions to exclude
    uncommitted empty scratch files or temporary stubs.
    """
    if not os.path.isdir(folder):
        return 0

    if not include_untracked:
        try:
            result = subprocess.run(
                ["git", "ls-files", folder],
                capture_output=True,
                text=True,
                check=True,
                cwd=Path(__file__).resolve().parent,
            )
            tracked = [
                f
                for f in result.stdout.splitlines()
                if os.path.splitext(f)[1].lower() in EXTENSIONS
            ]
            return len(tracked)
        except Exception:
            pass

    return sum(
        1
        for f in os.listdir(folder)
        if os.path.splitext(f)[1].lower() in EXTENSIONS and not f.startswith(".")
    )


def generate_bar(solved: int, total: int, length: int = 20) -> str:
    """Generate an ASCII progress bar."""
    pct = solved / total if total > 0 else 0
    filled = max(1 if solved > 0 else 0, int(round(pct * length)))
    filled = min(length, filled)
    return "■" * filled + "□" * (length - filled)


def build_tracker_content(include_untracked: bool = False) -> str:
    """Build the markdown content for the tracker block."""
    total_solved = 0
    rows = []

    for num, name, folder, cat_total in CATEGORIES:
        count = count_solutions(folder, include_untracked=include_untracked)
        total_solved += count

        if count == 0:
            status = "⏳ Pending"
        elif count >= cat_total:
            status = "✅ Completed"
        else:
            status = "🔄 In Progress"

        rows.append(f"| {num} | [{name}]({folder}/) | {count} / {cat_total} | {status} |")

    pct = (total_solved / TOTAL_TARGET) * 100 if TOTAL_TARGET > 0 else 0
    bar = generate_bar(total_solved, TOTAL_TARGET)

    rows.append(
        f"| **Total** | **All Categories** | **{total_solved} / {TOTAL_TARGET}** | **{pct:.1f}%** |"
    )

    table_rows = "\n".join(rows)

    return f"""### 📊 Completion Progress

```text
Progress : [{bar}] {total_solved} / {TOTAL_TARGET} Solved ({pct:.1f}%)
Target   : Complete CSES Problem Set
Status   : Compiling without warnings... mostly
```

### 🗂️ Problem Tracker

| # | Category | Solved / Total | Status |
| :-: | :--- | :-: | :-: |
{table_rows}"""


def update_readme(include_untracked: bool = False) -> bool:
    """Update the tracker section of README.md between the start/end markers."""
    if not README_PATH.is_file():
        print(f"Error: Could not find README.md at {README_PATH}", file=sys.stderr)
        return False

    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    new_section = build_tracker_content(include_untracked=include_untracked)

    pattern = re.compile(
        r"<!-- TRACKER:START -->.*?<!-- TRACKER:END -->",
        re.DOTALL,
    )

    if not pattern.search(content):
        print(
            "Error: Markers '<!-- TRACKER:START -->' and '<!-- TRACKER:END -->' not found in README.md",
            file=sys.stderr,
        )
        return False

    replacement = f"<!-- TRACKER:START -->\n{new_section}\n<!-- TRACKER:END -->"
    updated = pattern.sub(replacement, content)

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(updated)

    print(f"Successfully updated {README_PATH.name} with latest progress stats.")
    return True


if __name__ == "__main__":
    include_all = "--all" in sys.argv or "--include-untracked" in sys.argv
    success = update_readme(include_untracked=include_all)
    sys.exit(0 if success else 1)
