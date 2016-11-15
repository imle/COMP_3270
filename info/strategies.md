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


## Strategy 3 - (Self Designed)

Recursively divide and conquer by calling the function on a smaller and smaller
subset of the original array until the array size is less than or equal to 1
and finally compare the two values and return the smaller (and the two indices)
recursively.