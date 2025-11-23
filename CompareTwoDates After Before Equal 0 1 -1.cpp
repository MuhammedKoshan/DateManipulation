#include <iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return  (Date1.Year < Date2.Year)
        ? true
        : ((Date1.Year == Date2.Year)
            ? (Date1.Month < Date2.Month
                ? true
                : (Date1.Month == Date2.Month
                    ? Date1.Day < Date2.Day
                    : false))
            : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) &&
        (Date1.Month == Date2.Month) &&
        (Date1.Day == Date2.Day);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2) &&
        !IsDate1EqualDate2(Date1, Date2));
}
short CompareDates(stDate Date1, stDate Date2) {
    if (IsDate1AfterDate2(Date1, Date2)) {
        return 1;

    }
    if (IsDate1BeforeDate2(Date1, Date2)) {
        return -1;
    }

    /*if (IsDate1EqualDate2(Date1, Date2)) {
        return 0;
    }*/

    // we dont have to write it because if the program already comes to here it means the date is equal so we dont have to check

    return 0;  //better choice



}
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
enDateCompare CompareDates2(stDate Date1, stDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2)) {

        return enDateCompare::Before;
    }
    if (IsDate1EqualDate2(Date1, Date2)) {

        return enDateCompare::Equal;

    }
    return enDateCompare::After;

}

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

int main() {

    stDate Date1 = ReadFullDate();


    system("pause>0");
    return 0;
}
