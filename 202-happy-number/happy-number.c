bool isHappy(int n) {
    int sum_of_squares(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }

    int slow = n, fast = n;
    while (fast != 1 && sum_of_squares(fast) != 1) {
        slow = sum_of_squares(slow);
        fast = sum_of_squares(sum_of_squares(fast));
        if (slow == fast) {
            return false;
        }
    }
    return true;
}
