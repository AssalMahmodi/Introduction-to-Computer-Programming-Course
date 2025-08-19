void averageStudents() {
    const int N = 15;
    char name[N][30];
    double avg[N];
    for (int i = 0; i < N; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name[i];
        double sum = 0;
        for (int j = 0; j < 10; j++) {
            double x;
            cout << "Enter score " << j + 1 << " for " << name[i] << ": ";
            cin >> x;
            sum += x;
        }
        avg[i] = sum / 10.0;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (avg[j] > avg[i]) {
                swap(avg[i], avg[j]);
                char temp[30]; strcpy(temp, name[i]); strcpy(name[i], name[j]); strcpy(name[j], temp);
            }
        }
    }
    cout << "Top 3 students: " << endl;
    for (int i = 0; i < 3; i++) cout << name[i] << " " << avg[i] << endl;
}
