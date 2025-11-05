char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // Start with the first string as the initial prefix
    char* prefix = strs[0];
    
    // Loop through all the words in the array
    for (int i = 1; i < strsSize; i++) {
        // Compare the prefix with each string
        int j = 0;
        // Find the common prefix between the current prefix and the current string
        while (strs[i][j] == prefix[j] && prefix[j] != '\0') {
            j++;
        }

        // Shorten the prefix to the common part
        prefix[j] = '\0';
        
        // If the prefix becomes empty, return an empty string
        if (prefix[0] == '\0') {
            return "";
        }
    }
    return prefix;
}
