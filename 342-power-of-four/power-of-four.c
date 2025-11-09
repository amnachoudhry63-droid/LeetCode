

// Function to check if n is a power of 4
bool isPowerOfFour(int n) {
    // A number is a power of four if it's positive and 
    // it is a power of two and its binary representation
    // has only one '1' bit at an odd position.
    
    // Check if n is greater than 0 and is a power of 2
    if (n > 0 && (n & (n - 1)) == 0) {
        // Check if the only '1' bit is at an odd position
        return (n & 0x55555555) != 0;
    }
    return false;
}
