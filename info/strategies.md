## Strategy 1 - (Self Designed)

Iterate over the list of integers starting from the first value in the array
to the last value. Using two loops, start by pointing them both at the first
value and then incrementing the inner loop by one until the end of the array
is reached. When a sum is calculated, compare it to the current value of the
smallest known sum and if it is smaller, overwrite it and update the indices
of the range.


## Strategy 2 - (Self Designed)

Pass over the array one time and add the index of any negative integers into
an array. Iterate over these indices using the process from strategy 1 using
the indices that are in the array since adding a positive number as the last
or first number in the series will not yield a lower result.


## Strategy 3 - (Reverse of Kadane's Algorithm)
(https://en.wikipedia.org/wiki/Maximum_subarray_problem)

Walk through the array and find the first negative value, set the starting point
to this index and the end point to the same. Add the next value to it. If the
sum of the two numbers is less than 0, then increment the end point and change
the current smallest sum to the most recently calculated one. If the sum were
greater than or equal to 0, do not change anything but step through the array
until a new negative number is found and perform the same steps, only changing
the value of smallest if the current sum is smaller.