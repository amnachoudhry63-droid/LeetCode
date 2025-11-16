int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for(int i = 0; i < numsSize; i++){
        int idx = abs(nums[i]) - 1;
        if(nums[idx] > 0)
            nums[idx] = -nums[idx];
    }

    int* result = (int*)malloc(numsSize * sizeof(int));
    int k = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0)
            result[k++] = i + 1;
    }

    *returnSize = k;
    return result;
}
