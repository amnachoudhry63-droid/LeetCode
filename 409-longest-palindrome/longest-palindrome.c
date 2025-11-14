int longestPalindrome(char* s) {
    int count[128] = {0};  // Array to count frequency of each character
    int length = 0;
    int oddFound = 0;

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }

    // Calculate the length of the longest palindrome
    for (int i = 0; i < 128; i++) {
        if (count[i] % 2 == 0) {
            length += count[i];  // Add all pairs
        } else {
            length += count[i] - 1;  // Add the largest even number
            oddFound = 1;  // Mark that we found an odd frequency
        }
    }

    // If there was any odd frequency, we can add one character in the middle
    if (oddFound) {
        length++;
    }

    return length;
}
