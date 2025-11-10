

int strStr(char *haystack, char *needle) {
    // If needle is an empty string, return 0 according to the problem statement
    if (*needle == '\0') {
        return 0;
    }

    // Loop through the haystack string
    for (int i = 0; haystack[i] != '\0'; i++) {
        // Check if the substring starting at index i matches needle
        int j = 0;
        while (haystack[i + j] == needle[j] && needle[j] != '\0') {
            j++;
        }

        // If the full needle string is found, return the starting index
        if (needle[j] == '\0') {
            return i;
        }
    }

    // If needle is not found, return -1
    return -1;
}
