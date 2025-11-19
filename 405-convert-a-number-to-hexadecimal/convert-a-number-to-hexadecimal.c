

char* toHex(int num) {
    static char hexDigits[] = "0123456789abcdef";
    static char result[9];  // Maximum of 8 hex digits + null terminator
    int i = 7;  // Position to start filling result from the right
    unsigned int n = (num < 0) ? (unsigned int)num : num;  // Handle negative numbers using two's complement

    // If the number is zero, return "0"
    if (n == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Convert integer to hexadecimal
    while (n > 0) {
        result[i--] = hexDigits[n % 16];
        n /= 16;
    }

    // Shift the result to the left to remove leading zeros
    return &result[i + 1];
}
