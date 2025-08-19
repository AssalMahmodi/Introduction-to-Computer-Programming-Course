long long factorial() {
    int n;
    cout << "Enter a number for factorial: ";
    cin >> n;
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    cout << "Factorial of " << n << " is " << result << endl;
    return result;
}
