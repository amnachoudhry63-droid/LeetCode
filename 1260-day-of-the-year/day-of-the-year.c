



int dayOfYear(char* date) {
    // Days in each month for a regular year
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Parse the date string
    int year, month, day;
    sscanf(date, "%4d-%2d-%2d", &year, &month, &day);

    // Calculate the day number by summing the days in the months before the current month
    int dayOfYear = day;
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }

    // If it's a leap year and the month is after February, add an extra day for February
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if (month > 2) {
            dayOfYear++;
        }
    }

    return dayOfYear;
}


