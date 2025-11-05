

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Allocate memory for the result array (one extra space in case we need a new most significant digit)
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    int carry = 1;  // We are adding 1 initially
    
    // Traverse the digits from last to first
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;  // Add the carry to the current digit
        result[i + 1] = sum % 10;    // The current digit in the result (mod 10)
        carry = sum / 10;             // Update the carry (if sum >= 10)
    }

    // If there's no carry left, we can return the result as it is
    if (carry == 0) {
        *returnSize = digitsSize;
        return result + 1;  // The result array without the extra leading 0
    } else {
        // If there is a carry left, we need to add 1 at the front
        result[0] = 1;  // The new most significant digit
        *returnSize = digitsSize + 1;
        return result;
    }
}
