<!-- CSES Introduction Card -->
<div class="row g-4 justify-content-center mb-4 font-monospace">
  <div class="col-12 col-md-10">
    <div class="p-4 rounded-4 shadow-sm border bg-white cses-notebook-card font-monospace">

      <div class="cses-terminal-text">

        <!-- Heading -->
        <div class="d-flex flex-wrap align-items-center justify-content-between gap-2 mb-3">
          <h3 class="cses-title-mono mb-0 fs-5 fw-bold font-monospace text-dark">
            ✝️ CSES Problem Set — Surviving C++ One Segfault at a Time
          </h3>
          <span class="small px-2 py-1 rounded bg-light text-muted border border-warning-subtle">
            dev.journal.c++
          </span>
        </div>

        <!-- Discrete Link Buttons -->
        <div class="d-flex flex-wrap gap-2 mb-3">
          <a href="https://github.com/tninanofchirawa/cses" 
             target="_blank" 
             rel="noopener noreferrer" 
             class="btn btn-sm btn-light border text-secondary px-2 py-1 text-decoration-none" 
             style="font-size: 0.8rem;">
            <span class="text-muted me-1">repo:</span>github.com/tninanofchirawa/cses
          </a>
          <a href="https://tninanofchirawa.github.io/personal-website-1/Nd-s/cses.html?ref=cses-handbook" 
             data-target="https://cses.fi/book/book.pdf" 
             class="btn btn-sm btn-light border text-secondary px-2 py-1 text-decoration-none" 
             style="font-size: 0.8rem;">
            <span class="text-muted me-1">book:</span>cses.fi/book.pdf
          </a>
          <a href="https://tninanofchirawa.github.io/personal-website-1/Nd-s/cses.html?ref=problemset-official" 
             data-target="https://cses.fi/problemset/" 
             class="btn btn-sm btn-light border text-secondary px-2 py-1 text-decoration-none" 
             style="font-size: 0.8rem;">
            <span class="text-muted me-1">set:</span>cses.fi/problemset
          </a>
        </div>

        <!-- Punchy, No-Fluff Intro -->
        <p class="mb-3 text-dark font-monospace" style="font-size: 0.92rem; line-height: 1.6;">
          By the grace of Jesus, this is a patient journey. Tackling CSES in C++—where pure discrete mathematics goes to test how many times you can stare at a compiler error before questioning your life choices.
        </p>

        <!-- Notice Box -->
        <div class="cses-note-box mb-3 p-3 rounded-3 border border-warning-subtle bg-light">
          <div class="d-flex align-items-center gap-2 mb-2">
            <span class="badge bg-warning text-dark font-monospace border border-warning-subtle">Notice</span>
            <span class="text-uppercase font-monospace fw-bold small text-secondary">The Joy of the Struggle</span>
          </div>
          <p class="mb-0 font-monospace text-muted small" style="line-height: 1.55;">
            Full implementations live in the GitHub repository, but this archive is structured to prioritize hints before complete solutions. Because true character (and a passing test case) is forged in the confusion, whiteboard sketches, and that sudden breakthrough.
          </p>
        </div>

      </div>

      <!-- Live CSES Completion Progress -->
      <div class="p-3 rounded-3 border bg-light bg-opacity-50 mt-3 font-monospace">
        <div class="d-flex justify-content-between align-items-center mb-2">
          <span class="text-uppercase fw-bold text-dark small">
            CSES Completion Progress
          </span>
          <span class="text-dark fw-bold small" id="progress-stats-text">
            Fetching...
          </span>
        </div>

        <div class="water-bar-container">
          <div id="cses-water-fill" class="water-bar-fill" style="width: 0%; transition: width 0.6s ease;"></div>
        </div>

        <div class="d-flex justify-content-between align-items-center mt-2 small text-muted">
          <span>
            Benchmark Target: Complete CSES Set
          </span>
          <span id="percent-text">0.0%</span>
        </div>
      </div>

    </div>
  </div>
</div>

<!-- Automatic Live Tracker Script -->
<script>
  (async function loadRepoProgress() {
    const USER = 'tninanofchirawa';
    const REPO = 'cses';
    const BRANCH = 'main';
    const TOTAL_BENCHMARK = 400;

    const statsEl = document.getElementById('progress-stats-text');
    const percentEl = document.getElementById('percent-text');
    const barEl = document.getElementById('cses-water-fill');

    try {
      const res = await fetch(`https://api.github.com/repos/${USER}/${REPO}/git/trees/${BRANCH}?recursive=1`);
      if (!res.ok) throw new Error('API fetch error');
      const data = await res.json();

      // Matches any code file inside numbered folders (e.g. 01-Introductory-Problems/...)
      const solutionFiles = (data.tree || []).filter(item => {
        return item.type === 'blob' && /\.(cpp|cc|cxx|c)$/i.test(item.path);
      });

      const solvedCount = solutionFiles.length;
      const percentage = ((solvedCount / TOTAL_BENCHMARK) * 100).toFixed(1);

      if (statsEl) statsEl.textContent = `${solvedCount} / ${TOTAL_BENCHMARK} Solved`;
      if (percentEl) percentEl.textContent = `${percentage}%`;
      if (barEl) barEl.style.width = `${Math.min(percentage, 100)}%`;
    } catch (err) {
      if (statsEl) statsEl.textContent = 'Repo Sync Offline';
      if (percentEl) percentEl.textContent = '--';
    }
  })();
</script>