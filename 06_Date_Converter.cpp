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
