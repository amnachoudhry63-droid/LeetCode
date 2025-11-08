int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];  // XOR each number with result
    }
    return result;  // The single number will be left
}
