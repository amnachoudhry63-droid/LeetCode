int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) return 0;

    int cmp(const void* a, const void* b) {
        int* pa = *(int**)a;
        int* pb = *(int**)b;
        if (pa[1] < pb[1]) return -1;
        if (pa[1] > pb[1]) return 1;
        return 0;
    }

    qsort(points, pointsSize, sizeof(int*), cmp);

    int arrows = 1;
    long long currEnd = points[0][1];
    for (int i = 1; i < pointsSize; ++i) {
        if (points[i][0] > currEnd) {
            arrows++;
            currEnd = points[i][1];
        }
    }
    return arrows;
}
