#include "data.h"

DATE fill(int day, int month, int year)
{
    DATE date = { day, month, year };
    return date;
};

bool validate(DATE date)
{
    bool valid_day=false, valid_month=false, valid_year=false;

    if(date.year >= 1 && date.year <= 9999)
        valid_year = true;

    if(date.month >= 1 && date.month <= 12)
        valid_month = true;

    if(valid_year &&
            valid_month &&
            date.day >= 1 &&
            date.day <= qty_days_in_month(is_leap(date.year), date.month))
        valid_day = true;

    if(valid_day && valid_month && valid_year)
        return true;

    return false;
};

bool date_gen_from_days(int days, int year, DATE *date)
{
    int qty_days[] = {NULL, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i=1;
    int day, month;

    if (is_leap(date->year))
        qty_days[FEB] = 29;

    while(days > qty_days[i])
    {
        days -= qty_days[i];
        i++;
    }

    day = days;
    month = i;

    *date = fill(day, month, year);

    if (validate(*date))
        return true;

    return false;
}

int qty_days_until_now(DATE date)
{
    int month;
    int sum_days=0;
    int qty_days[] = {NULL, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leap(date.year))
        qty_days[FEB] = 29;

    for(month=JAN; month < date.month; month++)
    {
        sum_days += qty_days[month];
    }

    sum_days += date.day;

    return sum_days;

}

int qty_days_in_month(bool leap_year, int month) {

    int quantity_days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (leap_year)
        quantity_days[FEB] = 29;

    return quantity_days[month];

};

bool is_leap(int year)
{
    if (((year % 4 == 0) && (year % 100!= 0)) || (year % 400 == 0))
        return true;

    return false;
};

bool test_str_date(char str_date[], DATE *date)
{
    int i=0;
    int j = 0;
    int k = 0;
    char date_arr[3][5];
    int day, month, year;

    // validar string format

    if (strlen(str_date) != 10) {
        // invalida
        return false;
    }

    if (str_date[2] != '/' || str_date[5] != '/') {
        // invalida
        return false;
    }

    for(i=0;i<3;i++)
    {
        j=0;
        while(k != 2 && k != 5 && str_date[k] != '\0')
        {
            date_arr[i][j] = str_date[k];
            j++;
            k++;
        }
        date_arr[i][j] = '\0';
        k++;
    }

    day = atoi(date_arr[0]);
    month = atoi(date_arr[1]);
    year = atoi(date_arr[2]);

    // por em uma strutura date
    *date = fill(day, month, year);

    // testar com validate
    // return situation
    return validate(*date);
};

void print_date(DATE date)
{

    printf("%d %d %d", date.day, date.month, date.year);

}
//char* formatar(int format_size) {
//    char *number = malloc (sizeof (char) * 5);;
//    sprintf(number, "%%%d[^\\n]%%c", format_size);
//
    //const char *month_name[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//    puts(number);
//
//    return number;
//}

