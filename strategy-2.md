## Strategy 2 - (Self Designed)

Pass over the array one time and add the index of any negative integers into
an array. Iterate over these indices using the process from strategy 1 using
the indices that are in the array since adding a positive number as the last
or first number in the series will not yield a lower result.

### Pseudo-code

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


### Time Complexity

| Step   | Cost | Runs             | Total               |
| ------:| ----:|:----------------:| -------------------:|
| **1**  | 1    | 1                | 1                   |
| **2**  | 1    | 1                | 1                   |
| **3**  | 1    | n + 1            | n + 1               |
| **4**  | 4    | n                | 4n                  |
| **5**  | 1    | n                | n                   |
| **6**  | 3    | n                | 3n                  |
| **7**  | 5    | n                | 5n                  |
| **8**  | 4    | n                | 4n                  |
| **9**  | 2    | n                | 2n                  |
| **10** | 2    | n                | 2n                  |
| **11** | 1    | 1                | 1                   |
| **12** | 1    | 1                | 1                   |
| **13** | 1    | 1                | 1                   |
| **14** | 1    | 1                | 1                   |
| **15** | 1    | n                | n                   |
| **16** | 1    | n(n + 1) / 2     | n(n + 1) / 2        |
| **17** | 1    | **?**            | 1                   | ?
| **18** | 6    | **?**            | 6                   | ?
| **19** | 5    | n(n + 1) / 2 - 1 | 5(n(n + 1) / 2 - 1) |
| **20** | 2    | n(n + 1) / 2 - 1 | 2(n(n + 1) / 2 - 1) |
| **21** | 2    | n(n + 1) / 2 - 1 | 2(n(n + 1) / 2 - 1) |
| **22** | 1    | n(n + 1) / 2 - 1 | n(n + 1) / 2 - 1    |
| **23** | 1    | n(n + 1) / 2 - 1 | n(n + 1) / 2 - 1    |
| **24** | 1    | 1                | 1                   |



http://stackoverflow.com/questions/18486543/what-is-the-complexity-of-this-nested-triple-for-loop