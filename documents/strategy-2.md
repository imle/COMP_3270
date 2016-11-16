# Strategy 2 - (Self Designed)

Pass over the array one time and add the index of any negative integers into
an array. Iterate over these indices using the process from strategy 1 using
the indices that are in the array since adding a positive number as the last
or first number in the series will not yield a lower result.

## Pseudo-code

    algorithm-2 (A: Array [1 ... n] of integer)
    1       negatives := []
    2       m = 0
    3       for i := 1 to (n-1)
    4           if A[i] < 0
    5               negatives.append(i)
    6               m = m + 1
    7           if A[i] < smallest
    8               smallest := A[i]
    9               ind_l := i
    10              ind_r := i
    11      smallest := nil
    12      ind_l := nil
    13      ind_r := nil
    14      current := 0
    15      for i := 1 to (m-1)
    16          for j := i to (m-1)
    17              for k := negatives[i] to negatives[j]
    18                  current := current + A[k]
    19              if smallest = nil or smallest > current
    20                  smallest := current
    21                  ind_l := i
    22                  ind_r := j
    23              current := 0
    24      return (smallest, ind_l, ind_r)


## Time Complexity

This strategies time complexity is difficult to calculate since the size of `m` is relative
to the amount of negative integers in `A`. Since this can be anywhere from 0 to `n`, I calculated
the worst case. This will likely be different from the curve actually calculated since the average
case (on a random set of integers) will likely have `n/2` negative numbers in it. Due to this,
I have included the upper and lower bounds below.

Ω(n) = n
O(n) = n^3

| Step   | Cost | Runs                     | Total                      |
| ------:| ----:|:------------------------:|:--------------------------:|
| **1**  | 1    | 1                        | 1                          |
| **2**  | 1    | 1                        | 1                          |
| **3**  | 1    | n                        | n                          |
| **4**  | 4    | n - 1                    | 4n - 4                     |
| **5**  | 1    | n - 1                    | n - 1                      |
| **6**  | 3    | n - 1                    | 3n - 3                     |
| **7**  | 5    | n - 1                    | 5n - 5                     |
| **8**  | 4    | n - 1                    | 4n - 4                     |
| **9**  | 2    | n - 1                    | 2n - 2                     |
| **10** | 2    | n - 1                    | 2n - 2                     |
| **11** | 1    | 1                        | 1                          |
| **12** | 1    | 1                        | 1                          |
| **13** | 1    | 1                        | 1                          |
| **14** | 1    | 1                        | 1                          |
| **15** | 1    | n                        | n                          |
| **16** | 1    | n(n + 1)/2 - 1           | n(n + 1)/2 - 1             |
| **17** | 1    | 2*n^3 - 3*n^2 + n        | 2*n^3 - 3*n^2 + n          |
| **18** | 6    | 2*n^3 - 7/2*n^2 + 3/2n   | 6 (2*n^3 - 7/2*n^2 + 3/2n) |
| **19** | 5    | 2*n^3 - 3*n^2 + n        | 5 (2*n^3 - 3*n^2 + n)      |
| **20** | 2    | 2*n^3 - 3*n^2 + n        | 2 (2*n^3 - 3*n^2 + n)      |
| **21** | 2    | 2*n^3 - 3*n^2 + n        | 2 (2*n^3 - 3*n^2 + n)      |
| **22** | 1    | 2*n^3 - 3*n^2 + n        | 2*n^3 - 3*n^2 + n          |
| **23** | 1    | 2*n^3 - 3*n^2 + n        | 2*n^3 - 3*n^2 + n          |
| **24** | 1    | 1                        | 1                          |

### Worst Case
T(n) = 1/2 * (72*n^3 - 113*n^2 + 89*n - 28)

### Expected Average Case
T(n) = 1/2 * (72*(n/2)^3 - 113*(n/2)^2 + 89*(n/2) - 28)