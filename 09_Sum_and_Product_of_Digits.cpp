void sumProductDigits() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int sum = 0, prod = 1, temp = n;
    while (temp > 0) { int d = temp % 10; sum += d; prod *= d; temp /= 10; }
    cout << "Sum of digits: " << sum << ", Product of digits: " << prod << endl;
}

void countWordsLetters() {
    char s[200];
    cin.ignore();
    cout << "Enter a sentence: ";
    cin.getline(s, 200);
    int letters = 0, words = 0; bool inWord = false;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) letters++;
        if (c == ' ' || c == '\t') { if (inWord) { words++; inWord = false; } }
        else inWord = true;
    }
    if (inWord) words++;
    cout << "Words: " << words << ", Letters: " << letters << endl;
}
