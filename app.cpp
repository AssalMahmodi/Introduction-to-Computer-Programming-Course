#include <iostream>
#include <cmath>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

long long factorial() {
    int n;
    cout << "Enter a number for factorial: ";
    cin >> n;
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    cout << "Factorial of " << n << " is " << result << endl;
    return result;
}

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

long long fibonacci() {
    int n;
    cout << "Enter n for Fibonacci: ";
    cin >> n;
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << "Fibonacci number " << n << " is " << b << endl;
    return b;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) if (n % i == 0) return false;
    return true;
}

void nthPrime() {
    int n;
    cout << "Enter n for nth prime: ";
    cin >> n;
    int count = 0, num = 1;
    while (count < n) {
        num++;
        if (isPrime(num)) count++;
    }
    cout << "The " << n << "th prime number is " << num << endl;
}

void isPerfect() {
    int n;
    cout << "Enter a number to check perfect: ";
    cin >> n;
    int sum = 0;
    for (int i = 1; i < n; i++) if (n % i == 0) sum += i;
    if (sum == n) cout << n << " is a perfect number." << endl;
    else cout << n << " is not a perfect number." << endl;
}


bool isLeapShamsi(int year) {
    int mod = (year - ((year > 0) ? 474 : 473)) % 2820 + 474;
    return (((mod * 682) % 2816) < 682);
}

bool isLeapGregorian(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void convertDate() {
    int option;
    cout << "\nChoose conversion type:\n";
    cout << "1. Shamsi → Gregorian\n";
    cout << "2. Gregorian → Shamsi\n";
    cout << "Enter choice (1 or 2): ";
    cin >> option;

    if(option == 1) {
        int shYear, shMonth, shDay;
        cout << "Enter Shamsi date (year month day): ";
        cin >> shYear >> shMonth >> shDay;

        int gy, gm, gd;
        int days = 0;

        int sh_month_days[12] = {31,31,31,31,31,31,30,30,30,30,30,29};
        if(isLeapShamsi(shYear)) sh_month_days[11] = 30;

        for(int i = 0; i < shMonth - 1; i++)
            days += sh_month_days[i];
        days += shDay;

        gy = shYear + 621;
        int g_month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapGregorian(gy)) g_month_days[1] = 29;

        if(days > 79) {
            days -= 79;
        } else {
            gy -= 1;
            if(isLeapGregorian(gy)) g_month_days[1] = 29;
            else g_month_days[1] = 28;
            days += (isLeapGregorian(gy) ? 366 : 365) - 79;
        }

        gm = 0;
        for(int i = 0; i < 12; i++) {
            if(days <= g_month_days[i]) {
                gm = i + 1;
                gd = days;
                break;
            } else {
                days -= g_month_days[i];
            }
        }

        cout << "Gregorian Date: " << gy << "/" << gm << "/" << gd << endl;
    }
    else if(option == 2) {
        int gYear, gMonth, gDay;
        cout << "Enter Gregorian date (year month day): ";
        cin >> gYear >> gMonth >> gDay;

        int shYear, shMonth, shDay;
        int g_month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapGregorian(gYear)) g_month_days[1] = 29;

        int days = 0;
        for(int i = 0; i < gMonth - 1; i++)
            days += g_month_days[i];
        days += gDay;

        shYear = gYear - 621;
        int sh_month_days[12] = {31,31,31,31,31,31,30,30,30,30,30,29};
        if(isLeapShamsi(shYear)) sh_month_days[11] = 30;

        if(days > (isLeapGregorian(gYear) ? 80 : 79)) {
            days -= (isLeapGregorian(gYear) ? 80 : 79);
            shMonth = 0;
            for(int i = 0; i < 12; i++) {
                if(days <= sh_month_days[i]) {
                    shMonth = i + 1;
                    shDay = days;
                    break;
                } else {
                    days -= sh_month_days[i];
                }
            }
        } else {
            shYear -= 1;
            days += 286;
            shMonth = 0;
            for(int i = 0; i < 12; i++) {
                if(days <= sh_month_days[i]) {
                    shMonth = i + 1;
                    shDay = days;
                    break;
                } else {
                    days -= sh_month_days[i];
                }
            }
        }

        cout << "Shamsi Date: " << shYear << "/" << shMonth << "/" << shDay << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }
}


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

void squareStars() {
    int n;
    cout << "Enter size of square: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) cout << "* "; cout << endl; }
}

void palindromes3Digits() {
    cout << "3-digit palindromes: ";
    for (int i = 100; i <= 999; i++) { if (i / 100 == i % 10) cout << i << " "; }
    cout << endl;
}

void divisors() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Divisors: ";
    for (int i = 1; i <= n; i++) if (n % i == 0) cout << i << " ";
    cout << endl;
}

void powerAB() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    long long res = 1;
    for (int i = 0; i < b; i++) res *= a;
    cout << a << "^" << b << " = " << res << endl;
}

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
void help() {
    cout << "0. Factorial: Compute factorial of a number.\n";
    cout << "1. Even/Odd Between: List even or odd numbers in a range.\n";
    cout << "2. Fibonacci: Find nth Fibonacci number.\n";
    cout << "3. Nth Prime: Find the nth prime number.\n";
    cout << "4. Check Perfect Number: Check if a number is perfect.\n";
    cout << "5. Date Converter (Shamsi ↔ Gregorian): Convert dates between calendars.\n";
    cout << "6. Top 3 Student Average: Show top 3 students by average score.\n";
    cout << "7. GCD and LCM: Compute GCD and LCM of two numbers.\n";
    cout << "8. Sum and Product of Digits: Compute sum and product of digits.\n";
    cout << "9. Count Words and Letters: Count words and letters in a sentence.\n";
    cout << "10. Square of Stars: Print a square of stars of given size.\n";
    cout << "11. 3-Digit Palindromes: List all 3-digit palindromes.\n";
    cout << "12. Divisors of a Number: List all divisors of a number.\n";
    cout << "13. Power A^B: Compute a raised to power b.\n";
    cout << "14. Substring Search: Search for a substring in a string.\n";
    cout << "15. Bubble Sort: Sort an array using bubble sort.\n";
    cout << "16. Max and Min in Array: Find maximum and minimum in an array.\n";
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showMenu() {
    // متن خوش آمدگویی با رنگ‌های جذاب
    setColor(14); // زرد
    cout << "===============================" << endl;
    setColor(9); // آبی روشن
    cout << "Welcome" << endl;
    cout << "Principles of Computer Programming Project" << endl;
    cout << "Seyedeh Asal Mahmodi Nezhad Dezfouli" << endl;
    cout << "Professor: Dr. Saeed Ansari" << endl;
    cout << "Summer 2025" << endl;
    cout << "University of Guilan" << endl;
    setColor(14); // زرد
    cout << "===============================" << endl << endl;

    // منوی اصلی با رنگ‌بندی
    setColor(14); // آبی روشن
    cout << "============================" << endl;
    setColor(13); // صورتی
    cout << "        MAIN MENU           " << endl;
    setColor(14);
    cout << "============================" << endl;

    setColor(10); // سبز روشن
    cout << "0. "; setColor(7); cout << "Factorial" << endl;
    setColor(10); cout << "1. "; setColor(7); cout << "Even/Odd Between" << endl;
    setColor(10); cout << "2. "; setColor(7); cout << "Fibonacci" << endl;
    setColor(10); cout << "3. "; setColor(7); cout << "Nth Prime" << endl;
    setColor(10); cout << "4. "; setColor(7); cout << "Check Perfect Number" << endl;
    setColor(10); cout << "5. "; setColor(7); cout << "Date Converter (Shamsi ↔ Gregorian)" << endl;
    setColor(10); cout << "6. "; setColor(7); cout << "Top 3 Student Average" << endl;
    setColor(10); cout << "7. "; setColor(7); cout << "GCD and LCM" << endl;
    setColor(10); cout << "8. "; setColor(7); cout << "Sum and Product of Digits" << endl;
    setColor(10); cout << "9. "; setColor(7); cout << "Count Words and Letters" << endl;
    setColor(10); cout << "10. "; setColor(7); cout << "Square of Stars" << endl;
    setColor(10); cout << "11. "; setColor(7); cout << "3-Digit Palindromes" << endl;
    setColor(10); cout << "12. "; setColor(7); cout << "Divisors of a Number" << endl;
    setColor(10); cout << "13. "; setColor(7); cout << "Power A^B" << endl;
    setColor(10); cout << "14. "; setColor(7); cout << "Substring Search" << endl;
    setColor(10); cout << "15. "; setColor(7); cout << "Bubble Sort" << endl;
    setColor(10); cout << "16. "; setColor(7); cout << "Max and Min in Array" << endl;
    setColor(10); cout << "17. "; setColor(7); cout << "Help (Function Descriptions)" << endl;


    setColor(12); // قرمز
    cout << "-1. "; cout << "Exit" << endl;

    setColor(14);
    cout << "============================" << endl;
    setColor(7); // بازگشت رنگ به سفید پیش‌فرض
}

int main() {
    showMenu();

    int choice;
    while (true) {
    setColor(13);
        cout << "Enter function number (-1 to exit): ";
        setColor(7);
        cin >> choice;
        if (choice == -1) break;
        switch(choice) {
            case 0: factorial(); break;
            case 1: evenOddBetween(); break;
            case 2: fibonacci(); break;
            case 3: nthPrime(); break;
            case 4: isPerfect(); break;
            case 5: convertDate(); break;
            case 6: averageStudents(); break;
            case 7: gcdAndLcm(); break;
            case 8: sumProductDigits(); break;
            case 9: countWordsLetters(); break;
            case 10: squareStars(); break;
            case 11: palindromes3Digits(); break;
            case 12: divisors(); break;
            case 13: powerAB(); break;
            case 14: substringSearch(); break;
            case 15: bubbleSort(); break;
            case 16: maxMinN(); break;
            case 17: help(); break;

            default: cout << "Invalid choice (-1)" << endl;
        }
    }
    return 0;
    getch();
}

