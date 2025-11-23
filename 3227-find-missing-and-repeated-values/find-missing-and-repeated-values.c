int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    long long n = gridSize;
    long long totalCount = n * n;  // numbers are from 1 to n^2
    
    // Expected sums for 1..n^2
    long long expectedSum = totalCount * (totalCount + 1) / 2;
    long long expectedSqSum = totalCount * (totalCount + 1) * (2 * totalCount + 1) / 6;

    // Actual sums from the grid
    long long actualSum = 0;
    long long actualSqSum = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            long long x = grid[i][j];
            actualSum += x;
            actualSqSum += x * x;
        }
    }

    // Let a = repeated, b = missing
    // We know:
    // 1) actualSum - expectedSum = a - b
    // 2) actualSqSum - expectedSqSum = a^2 - b^2 = (a - b)(a + b)
    long long diff = actualSum - expectedSum;             // a - b
    long long sqDiff = actualSqSum - expectedSqSum;       // (a - b)(a + b)

    long long sum_ab = sqDiff / diff;                     // a + b

    long long a = (diff + sum_ab) / 2;                    // ( (a-b) + (a+b) ) / 2
    long long b = a - diff;                               // from a - b = diff

    int* ans = (int*)malloc(2 * sizeof(int));
    ans[0] = (int)a;  // repeated
    ans[1] = (int)b;  // missing
    *returnSize = 2;
    return ans;
}
