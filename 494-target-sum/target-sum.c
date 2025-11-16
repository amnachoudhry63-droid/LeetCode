int findTargetSumWays(int* nums, int numsSize, int target) {
    // Calculate the total sum of the array to define the range of possible sums
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    // If the target is out of range, return 0 as it's impossible to achieve the target
    if (target > sum || target < -sum) {
        return 0;
    }

    // DP array to store the number of ways to achieve a certain sum
    int range = 2 * sum + 1;  // To handle negative values, shift by sum
    int* dp = (int*)calloc(range, sizeof(int));  // Initialize all values to 0
    dp[sum] = 1;  // There's one way to get sum 0, which is to not add or subtract any numbers

    // Iterate through each number and update the possible sums
    for (int i = 0; i < numsSize; i++) {
        int* temp = (int*)calloc(range, sizeof(int));  // Temporary array for current updates
        for (int j = 0; j < range; j++) {
            if (dp[j] > 0) {
                // Add current number as a positive value
                if (j + nums[i] < range) {
                    temp[j + nums[i]] += dp[j];
                }
                // Add current number as a negative value
                if (j - nums[i] >= 0) {
                    temp[j - nums[i]] += dp[j];
                }
            }
        }
        // Update dp array with temp
        free(dp);
        dp = temp;
    }

    // The result is the number of ways to reach the target sum
    int result = (target + sum >= 0 && target + sum < range) ? dp[target + sum] : 0;

    // Clean up and return the result
    free(dp);
    return result;
}