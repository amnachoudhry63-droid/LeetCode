

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);  // Compare function for qsort to sort in ascending order
}

double trimMean(int* arr, int arrSize) {
    // Sort the array in ascending order
    qsort(arr, arrSize, sizeof(int), compare);
    
    // Calculate the number of elements to remove (5% of the array size)
    int removeCount = arrSize / 20;  // 5% of the array size
    
    // Calculate the sum of the remaining elements
    long long sum = 0;
    for (int i = removeCount; i < arrSize - removeCount; i++) {
        sum += arr[i];
    }
    
    // Calculate the mean of the remaining elements
    return (double)sum / (arrSize - 2 * removeCount);
}

