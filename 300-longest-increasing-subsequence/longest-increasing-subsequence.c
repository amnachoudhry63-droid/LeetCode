int binarySearch(int* dp, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dp[mid] == target) return mid;
        else if (dp[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left; // Return the position where we can insert the target
}

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    // dp will store the smallest tail of all increasing subsequences of length i + 1
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int length = 0; // Length of the LIS found so far
    
    for (int i = 0; i < numsSize; i++) {
        int pos = binarySearch(dp, length, nums[i]);
        dp[pos] = nums[i]; // Replace or append the element to dp
        if (pos == length) length++; // If we're appending to the end, increment the length of LIS
    }
    
    free(dp);
    return length;
}