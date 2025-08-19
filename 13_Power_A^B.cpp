void powerAB() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    long long res = 1;
    for (int i = 0; i < b; i++) res *= a;
    cout << a << "^" << b << " = " << res << endl;
}
