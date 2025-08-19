void bubbleSort() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) { cout << "Enter element " << i + 1 << ": "; cin >> arr[i]; }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
