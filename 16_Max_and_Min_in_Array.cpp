void maxMinN() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) { cout << "Enter element " << i + 1 << ": "; cin >> arr[i]; }
    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < n; i++) { if (arr[i] < mn) mn = arr[i]; if (arr[i] > mx) mx = arr[i]; }
    cout << "Min: " << mn << ", Max: " << mx << endl;
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
