/* 练习　5-8 */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
    if (month < 1 || month > 12)
        return -1;
    if (day < 1 || day > daytab[leap][month])
        return -1;
    for (i = 1; i < month; ++i)
        day += daytab[leap][i];
    return day;
}


int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return -1;
    }
    if (yearday < 1 || (leap == 0 && yearday > 365) || (leap == 1 && yearday > 366)) {
        *pmonth = -1;
        *pday = -1;
        return -1;
    }
    for (i = 1; yearday >daytab[leap][i]; ++i)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}


