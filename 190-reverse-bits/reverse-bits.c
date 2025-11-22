

int reverseBits(int n) {
    int reversed = 0;
    
    // Iterate through all the 32 bits of n
    for (int i = 0; i < 32; i++) {
        // Shift reversed left by 1 to make space for the new bit
        reversed <<= 1;
        
        // Get the least significant bit of n
        int bit = n & 1;
        
        // Add this bit to the reversed result
        reversed |= bit;
        
        // Shift n right by 1 to process the next bit
        n >>= 1;
    }
    
    return reversed;
}

