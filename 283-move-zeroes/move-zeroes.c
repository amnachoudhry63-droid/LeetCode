

void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroIndex = 0;
    
    // Move all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroIndex] = nums[i];
            if (lastNonZeroIndex != i) {
                nums[i] = 0;
            }
            lastNonZeroIndex++;
        }
    }
}

