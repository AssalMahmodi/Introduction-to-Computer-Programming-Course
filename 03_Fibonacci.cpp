long long fibonacci() {
    int n;
    cout << "Enter n for Fibonacci: ";
    cin >> n;
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << "Fibonacci number " << n << " is " << b << endl;
    return b;
}
