int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Initialize the result array
    result[0] = 1;
    
    // Left products
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Right products and final result
    int rightProduct = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        rightProduct *= nums[i + 1];
        result[i] *= rightProduct;
    }
    
    return result;
}
