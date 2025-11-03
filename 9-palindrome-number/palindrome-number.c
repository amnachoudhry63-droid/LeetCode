bool isPalindrome(int x) {
    // If x is negative or ends with 0 but isn't 0, it can't be a palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    
    int rev = 0;
    int temp = x;
    
    // Reverse the second half of the number
    while (temp > rev) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }

    // For odd length numbers, we can discard the middle digit by rev / 10
    return (temp == rev || temp == rev / 10);
}
