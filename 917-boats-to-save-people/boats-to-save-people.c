

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);  // Sorting in ascending order
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    // Sort the array in ascending order based on weights
    qsort(people, peopleSize, sizeof(int), compare);
    
    int left = 0, right = peopleSize - 1;
    int boats = 0;

    while (left <= right) {
        // If the lightest and heaviest person can fit in the same boat
        if (people[left] + people[right] <= limit) {
            left++;  // Move the left pointer
        }
        right--;  // Always move the right pointer to assign the heaviest person to a boat
        boats++;   // Increase the boat count
    }

    return boats;
}
