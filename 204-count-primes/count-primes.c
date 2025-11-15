int countPrimes(int n) {
    if (n <= 2) return 0;
    
    bool prime[n];
    for (int i = 0; i < n; i++) prime[i] = true;
    
    prime[0] = prime[1] = false;
    
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i]) count++;
    }
    
    return count;
}
