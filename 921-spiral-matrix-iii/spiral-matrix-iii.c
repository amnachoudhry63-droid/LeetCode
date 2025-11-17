int** spiralMatrixIII(int rows, int cols, int rStart, int cStart,
                      int* returnSize, int** returnColumnSizes) {
    int total = rows * cols;
    *returnSize = total;

    int **ans = (int **)malloc(total * sizeof(int *));
    *returnColumnSizes = (int *)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    int dr[4] = {0, 1, 0, -1};  // east, south, west, north
    int dc[4] = {1, 0, -1, 0};
    int r = rStart, c = cStart;
    int dir = 0;
    int step = 1;
    int count = 0;

    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        ans[count] = (int *)malloc(2 * sizeof(int));
        ans[count][0] = r;
        ans[count][1] = c;
        count++;
    }

    while (count < total) {
        for (int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < step; i++) {
                r += dr[dir];
                c += dc[dir];

                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans[count] = (int *)malloc(2 * sizeof(int));
                    ans[count][0] = r;
                    ans[count][1] = c;
                    count++;
                    if (count == total) break;
                }
            }
            dir = (dir + 1) % 4;
            if (count == total) break;
        }
        step++;
    }

    return ans;
}
