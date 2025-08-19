bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) if (n % i == 0) return false;
    return true;
}

void nthPrime() {
    int n;
    cout << "Enter n for nth prime: ";
    cin >> n;
    int count = 0, num = 1;
    while (count < n) {
        num++;
        if (isPrime(num)) count++;
    }
    cout << "The " << n << "th prime number is " << num << endl;
}
