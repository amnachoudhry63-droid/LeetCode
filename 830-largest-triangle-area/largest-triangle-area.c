

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double maxArea = 0.0;
    
    // Helper function to compute the area of a triangle formed by points (x1, y1), (x2, y2), (x3, y3)
    double area(int x1, int y1, int x2, int y2, int x3, int y3) {
        return fabs(0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    }

    // Check all combinations of three points
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                double currentArea = area(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                maxArea = fmax(maxArea, currentArea);  // Keep track of the maximum area
            }
        }
    }

    return maxArea;
}
