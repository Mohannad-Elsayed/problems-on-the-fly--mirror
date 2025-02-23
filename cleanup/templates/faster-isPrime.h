bool isPrime(long long n) {
  
    if (n <= 1)
        return false;

    if (n == 2  ||
        n == 3  || 
        n == 5  ||
        n == 7  ||
        n == 11 ||
        n == 13 ||
        n == 17 ||
        n == 19 ||
        n == 23 ||
        n == 29
    )
        return true;
        
    if (n % 2  == 0  ||
        n % 3  == 0  || 
        n % 5  == 0  ||
        n % 7  == 0  ||
        n % 11 == 0  ||
        n % 13 == 0  ||
        n % 17 == 0  ||
        n % 19 == 0  ||
        n % 23 == 0  ||
        n % 29 == 0
    )
        return false;
    
    // 30k + 1, 30k + 7
    for (long long i = 30; i * i <= n; i += 30)
        for (long long a : {1, 7, 11, 13, 17, 19, 23, 29})
            if (n%(i+a) == 0)
                return false;

    return true;
}