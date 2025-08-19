void evenOddBetween() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    if (a > b) swap(a, b);
    int choice;
    cout << "Enter 1 for even numbers, 2 for odd numbers: ";
    cin >> choice;
    cout << "Numbers in range: ";
    for (int i = a; i <= b; i++) {
        if (choice == 1 && i % 2 == 0) cout << i << " ";
        if (choice == 2 && i % 2 != 0) cout << i << " ";
    }
    cout << endl;
}
