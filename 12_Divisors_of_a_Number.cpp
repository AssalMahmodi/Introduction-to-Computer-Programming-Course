void divisors() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Divisors: ";
    for (int i = 1; i <= n; i++) if (n % i == 0) cout << i << " ";
    cout << endl;
}
