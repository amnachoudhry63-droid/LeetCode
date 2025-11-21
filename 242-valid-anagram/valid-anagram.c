

bool isAnagram(char* s, char* t) {
    // If lengths are different, they can't be anagrams
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[26] = {0};  // Array to store the count of each letter (assuming only lowercase letters)

    // Increment count for characters in s and decrement for characters in t
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;  // Increment count for character in s
        count[t[i] - 'a']--;  // Decrement count for character in t
    }

    // If all counts are 0, then t is an anagram of s
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}
