# Strategy 1 - (Self Designed)

Iterate over the list of integers starting from the first value in the array
to the last value. Using two loops, start by pointing them both at the first
value and then incrementing the inner loop by one until the end of the array
is reached. When a sum is calculated, compare it to the current value of the
smallest known sum and if it is smaller, overwrite it and update the indices
of the range.

## Pseudo-code

    algorithm-1 (A: Array [1 ... n] of integer)
    1       smallest := A[0]
    2       ind_l := 0
    3       ind_r := 0
    4       current := 0
    5       for i := 1 to (n-1)
    6           for j := i to (n-1)
    7               for k := i to j
    8                   current := current + A[k]
    9               if smallest = nil or smallest > current
    10                  smallest := current
    11                  ind_l := i
    12                  ind_r := j
    13              current := 0
    14      return (smallest, ind_l, ind_r)


## Time Complexity

| Step   | Cost | Runs                   | Total                     |
| ------:| ----:|:----------------------:|:-------------------------:|
| **1**  | 1    | 1                      | 1                         |
| **2**  | 1    | 1                      | 1                         |
| **3**  | 1    | 1                      | 1                         |
| **4**  | 1    | 1                      | 1                         |
| **5**  | 1    | n                      | n                         |
| **6**  | 1    | n(n + 1) / 2 - 1       | n(n + 1)/2 - 1            |
| **7**  | 1    | 2*n^3 - 3*n^2 + n      | 2*n^3 - 3*n^2 + n         |
| **8**  | 6    | 2*n^3 - 7/2*n^2 + 3/2n | 6(2*n^3 - 7/2*n^2 + 3/2n) |
| **9**  | 5    | 2*n^3 - 3*n^2 + n      | 5(2*n^3 - 3*n^2 + n)      |
| **10** | 2    | 2*n^3 - 3*n^2 + n      | 2(2*n^3 - 3*n^2 + n)      |
| **11** | 2    | 2*n^3 - 3*n^2 + n      | 2(2*n^3 - 3*n^2 + n)      |
| **12** | 2    | 2*n^3 - 3*n^2 + n      | 2(2*n^3 - 3*n^2 + n)      |
| **13** | 1    | 2*n^3 - 3*n^2 + n      | 2*n^3 - 3*n^2 + n         |
| **14** | 1    | 1                      | 1                         |


T(n) = 1/2 * (76*n^3 - 119*n^2 + 47*n + 8)