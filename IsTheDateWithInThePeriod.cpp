#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

stPeriod ReadPeriods() {
    stPeriod Period;
    cout << "Enter Start Date:\n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year)
        ? true
        : ((Date1.Year == Date2.Year)
            ? (Date1.Month < Date2.Month
                ? true
                : (Date1.Month == Date2.Month
                    ? Date1.Day < Date2.Day
                    : false))
            : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) &&
        (Date1.Month == Date2.Month) &&
        (Date1.Day == Date2.Day);
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool IsDateInPeriod(stPeriod Period, stDate Date) {

    return CompareDates(Date, Period.StartDate) == enDateCompare::After
        &&
        CompareDates(Date, Period.EndDate) == enDateCompare::Before;
}

int main() {

    cout << "Enter Period 1 :";
    stPeriod Period1 = ReadPeriods();


    cout << "Enter Period 2 :";
    stPeriod Period2 = ReadPeriods();

    system("pause>0");
    return 0;
}
