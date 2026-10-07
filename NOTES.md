---

### File 2: Put this into `NOTES.md`

Create a separate file named `NOTES.md` in the same directory, and put this inside:

```markdown
# Personal Study Notes & Key Takeaways

A log of recurring ideas, edge cases, and algorithmic observations discovered while working through the CSES set.

---

### Principles & Rules of Thumb
- **64-bit bounds:** Always check intermediate multiplications and prefix sums. Watch for overflow before taking modulo arithmetic (`1e9 + 7`).
- **Fast I/O:** Default to `cin.tie(NULL); ios_base::sync_with_stdio(false);` when $N \ge 10^5$.
- **Binary Search on Answer:** Check monotonicity whenever the problem asks to minimize a maximum or maximize a minimum.
- **Coordinate Compression:** Useful whenever coordinates are up to $10^9$ but array size $N \le 2 \times 10^5$.

---

### Topic Cheat Sheet

| Topic | Key Techniques / Gotchas |
| :--- | :--- |
| **Introductory** | Base edge cases ($N=1$), parity arguments, simulation limits. |
| **Searching & Sorting** | Two pointers, multiset mechanics, coordinate compression. |
| **DP** | State definition, space optimization (rolling arrays), order of evaluation. |
| **Graphs** | 1-based indexing, cycle checks, Dijkstra with priority queue, tree rerooting. |
| **Range Queries** | Segment Trees vs Fenwick Trees (BIT), lazy propagation overhead. |

---

### Problem-Specific Log

- **Weird Algorithm:** Sequence can exceed $2^{31}-1$; `long long` required for $n$.