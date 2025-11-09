

// Function to check if num is a perfect square
bool isPerfectSquare(int num) {
    if (num < 0) return false;  // Negative numbers cannot be perfect squares
    
    int left = 0, right = num;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;  // To avoid overflow
        
        if (square == num) {
            return true;  // Found the perfect square
        } else if (square < num) {
            left = mid + 1;  // We need a larger mid
        } else {
            right = mid - 1;  // We need a smaller mid
        }
    }
    
    return false;  // If we exit the loop without finding a perfect square
}
