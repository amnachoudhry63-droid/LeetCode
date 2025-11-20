#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int i = 0, j = 0;
    
    // Traverse both strings
    while (s[i] != '\0' && t[j] != '\0') {
        // If characters match, move to the next character in s
        if (s[i] == t[j]) {
            i++;
        }
        // Always move to the next character in t
        j++;
    }
    
    // If we've reached the end of s, then s is a subsequence of t
    return s[i] == '\0';
}
