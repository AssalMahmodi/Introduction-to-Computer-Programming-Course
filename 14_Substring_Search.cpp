void substringSearch() {
    char s[200], sub[50];
    cin.ignore();
    cout << "Enter main string: ";
    cin.getline(s, 200);
    cout << "Enter substring: ";
    cin.getline(sub, 50);
    int lenS = strlen(s), lenSub = strlen(sub); bool found = false;
    for (int i = 0; i <= lenS - lenSub; i++) {
        int j = 0; while (j < lenSub && s[i + j] == sub[j]) j++;
        if (j == lenSub) { cout << "Substring found at index: " << i << endl; found = true; break; }
    }
    if (!found) cout << "Substring not found (-1)" << endl;
}
