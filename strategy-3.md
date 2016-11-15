## Strategy 3 - [\(Reverse of Kadane's Algorithm\)](https://en.wikipedia.org/wiki/Maximum_subarray_problem)

Walk through the array and find the first negative value, set the starting point
to this index and the end point to the same. Add the next value to it. If the
sum of the two numbers is less than 0, then increment the end point and change
the current smallest sum to the most recently calculated one. If the sum were
greater than or equal to 0, do not change anything but step through the array
until a new negative number is found and perform the same steps, only changing
the value of smallest if the current sum is smaller.

### Pseudo-code

    algorithm-3 (A: Array [l ... r] of integer)
    1       smallest_ending_here := 0
    2       ind_l_ending_here := nil
    3       smallest := 0
    4       ind_l := nil
    5       ind_r := nil
    6       has_negative := false
    7       for i := 1 to (n-1)
    8           if A[i] < 0
    9               has_negative := true
    10              break
    11          if A[i] < smallest
    12              smallest := A[i]
    13              ind_l := i
    14              ind_r := i
    15      if !has_negative
    16          return (smallest, ind_l, ind_r)
    17      for i := 1 to (n-1)
    18          smallest_ending_here = smallest_ending_here + A[i]
    19          if smallest_ending_here > 0
    20              smallest_ending_here = 0
    21              ind_l_ending_here = i + 1
    22          if smallest > smallest_ending_here
    23              smallest := smallest_ending_here
    24              ind_l := ind_l_ending_here
    25              ind_r := i
    26          if smallest > A[i]
    27              smallest := A[i]
    28      return (smallest, ind_l, ind_r)


### Time Complexity

| Step   | Cost | Runs  | Total |
| ------:| ----:|:-----:| -----:|
| **1**  | 1    | 1     | 1     |
| **2**  | 1    | 1     | 1     |
| **3**  | 1    | 1     | 1     |
| **4**  | 1    | 1     | 1     |
| **5**  | 1    | 1     | 1     |
| **6**  | 1    | 1     | 1     |
| **7**  | 1    | n + 1 | n + 1 |
| **8**  | 4    | n     | 4n    |
| **9**  | 1    | n     | n     |
| **10** | 1    | n     | n     |
| **11** | 5    | n     | 5n    |
| **12** | 4    | n     | 4n    |
| **13** | 2    | n     | 2n    |
| **14** | 2    | n     | 2n    |
| **15** | 2    | 1     | 2     |
| **16** | 1    | 1     | 1     |
| **17** | 1    | n + 1 | n + 1 |
| **18** | 6    | n     | 6n    |
| **19** | 2    | n     | 2n    |
| **20** | 1    | n     | n     |
| **21** | 3    | n     | 3n    |
| **22** | 3    | n     | 3n    |
| **23** | 2    | n     | 2n    |
| **24** | 2    | n     | 2n    |
| **25** | 2    | n     | 2n    |
| **26** | 5    | n     | 5n    |
| **27** | 4    | n     | 4n    |
| **28** | 1    | 1     | 1     |


T(n)  = 1 + 1 + 1 + 1 + 1 + 1 + n + 1 + 4n + n + n + 5n + 4n + 2n + 2n + 2
        + 1 + n + 1 + 6n + 2n + n + 3n + 3n + 2n + 2n + 2n + 5n + 4n + 1

T(n) = 12 + 51n