int minimumDistance(int* nums, int numsSize) {
    // Dictionary (hashmap) to store the indices of each number
    // We will use a 2D array where each row corresponds to a different number's indices.
    // Maximum possible values for nums[i] are assumed to be between 1 and 1000.
    
    // Array to store the indices for each number
    int **indices = (int**)malloc(sizeof(int*) * 1001); // For numbers from 0 to 1000
    for (int i = 0; i < 1001; i++) {
        indices[i] = (int*)malloc(sizeof(int) * numsSize);
    }

    // Fill the indices array
    int numCounts[1001] = {0}; // Count the occurrences of each number
    for (int i = 0; i < numsSize; i++) {
        indices[nums[i]][numCounts[nums[i]]] = i;  // Store index of this number
        numCounts[nums[i]]++;
    }

    int minDistance = INT_MAX; // Initialize the minimum distance as the maximum possible value
    
    // Now we check for each number that appears at least 3 times
    for (int num = 0; num <= 1000; num++) {
        if (numCounts[num] >= 3) {
            // If the number appears at least 3 times, calculate the distances for all triplets of indices
            for (int i = 0; i < numCounts[num] - 2; i++) {
                for (int j = i + 1; j < numCounts[num] - 1; j++) {
                    for (int k = j + 1; k < numCounts[num]; k++) {
                        int idx1 = indices[num][i];
                        int idx2 = indices[num][j];
                        int idx3 = indices[num][k];
                        int dist = abs(idx1 - idx2) + abs(idx2 - idx3) + abs(idx3 - idx1);
                        if (dist < minDistance) {
                            minDistance = dist;  // Update the minimum distance
                        }
                    }
                }
            }
        }
    }

    // Free the allocated memory
    for (int i = 0; i < 1001; i++) {
        free(indices[i]);
    }
    free(indices);

    // If we never updated the minimum distance, return -1, indicating no good tuples
    return (minDistance == INT_MAX) ? -1 : minDistance;
}