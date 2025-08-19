void palindromes3Digits() {
    cout << "3-digit palindromes: ";
    for (int i = 100; i <= 999; i++) { if (i / 100 == i % 10) cout << i << " "; }
    cout << endl;
}
