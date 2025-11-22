char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result = (char**)malloc(numsSize * sizeof(char*));
    *returnSize = 0;

    if (numsSize == 0) {
        return result;
    }

    int start = 0;

    for (int i = 1; i <= numsSize; i++) {
        if (i == numsSize || nums[i] != nums[i-1] + 1) {
            result[*returnSize] = (char*)malloc(50 * sizeof(char));
            if (i - start == 1) {
                sprintf(result[*returnSize], "%d", nums[start]);
            } else {
                sprintf(result[*returnSize], "%d->%d", nums[start], nums[i-1]);
            }
            (*returnSize)++;
            start = i;
        }
    }

    return result;
}
