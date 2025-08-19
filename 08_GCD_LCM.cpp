void gcdAndLcm() {
    int a, b;
    cout << "Enter two numbers for GCD and LCM: ";
    cin >> a >> b;
    int a_copy = a, b_copy = b;
    while (b != 0) { int r = a % b; a = b; b = r; }
    int gcd = a;
    int lcm = (a_copy / gcd) * b_copy;
    cout << "GCD: " << gcd << ", LCM: " << lcm << endl;
}
