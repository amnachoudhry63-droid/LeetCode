#include <stdio.h>

char findTheDifference(char* s, char* t) {
    char result = 0;
    
    // XOR all characters from string s
    for (int i = 0; s[i] != '\0'; i++) {
        result ^= s[i];
    }
    
    // XOR all characters from string t
    for (int i = 0; t[i] != '\0'; i++) {
        result ^= t[i];
    }
    
    // The result will be the added character
    return result;
}
