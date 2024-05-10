# Notes
## 1956-C
The final matrix is like:
```
1 2 3 ... n
2 2 3 ... n
3 3 3 ... n
. . . ... .
n n n ... n
```
In the matrix, we have `n ^ 2 - (n - 1) ^ 2` elements equal to `n`, so we have `n ^ 2 - (n - 1) ^ 2` elements greater than or equal to `n`.
 
We have `(n - 1) ^ 2 - (n - 2) ^ 2` elements equal to `n - 1`, so we have `n ^ 2 - (n - 2) ^ 2` elements greater than or equal to `n - 1`.

Define `f(x)` as the number of elements greater than or equal to `x`, then the final result is `sum(f(x) for x in range(1, n + 1))`.

We want to prove that `f(x) <= n ^ 2 - (x - 1) ^ 2`.

To prove it, we restate the problem as: for a `n x n` matrix, each time you can make exactly `x - 1` elements smaller than x, and `n - (x - 1)` elements greater than or equal to x in one row or in one column. Then finally you can have at most `n ^ 2 - (x - 1) ^ 2` elements greater than or equal to x.

To make it more general and easy to handle: for a `m x n` matrix, each time you can make exactly `x` elements smaller than t, and `m - x` elements greater than or equal to t in one row, or you can make `y` elements smaller than t, and `n - y` elements greater than or equal to t in one column. Then finally you can have at most `m * n - x * y` elements greater than or equal to t.

Prove by induction.
