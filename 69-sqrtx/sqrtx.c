int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    
    int left = 0, right = x, mid, sqrt;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        
        // Check if mid is the square root
        if (mid == x / mid) {
            return mid;
        }
        
        // If mid^2 is less than x, move to the right half
        if (mid < x / mid) {
            left = mid + 1;
            sqrt = mid;  // store the last valid sqrt candidate
        }
        // If mid^2 is greater than x, move to the left half
        else {
            right = mid - 1;
        }
    }
    
    return sqrt;
}
