#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    if (Date1.Year < Date2.Year) return true;
    if (Date1.Year > Date2.Year) return false;
    if (Date1.Month < Date2.Month) return true;
    if (Date1.Month > Date2.Month) return false;
    return Date1.Day < Date2.Day;
}

short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }
    return Date;
}
stDate IncreaseDateByXDay(stDate Date,int Size) {
    for(short i=0; i<10; i++){

   Date= IncreaseDateByOneDay(Date);
      
    }
    return Date;
}
stDate IncreaseDateByOneWeek(stDate Date) {
    for (short i = 0; i < 7; i++) {

        Date = IncreaseDateByOneDay(Date);

    }
    
    return Date;
}
stDate IncreaseDateByXWeeks(stDate Date,int Size) {
    for (short i = 0; i < Size; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate IncreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    }
    else {
        Date.Month++;

    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
stDate IncreaseDateByXMonth(stDate Date, int Size) {
    for (short i = 0; i < Size; i++) {
      Date=  IncreaseDateByOneMonth(Date);

    }
    return Date;
}
stDate IncreaseDateByOneYear(stDate Date) {
    Date.Year++;
    return Date;
}
stDate IncreaseDateByXYear(stDate Date, int Size) {
    for (short i = 0; i < Size; i++) {
      Date= IncreaseDateByOneYear(Date);

    }
    return Date;
}
stDate IncreaseDateByXYearFaster(stDate Date, int Size) {

        Date.Year += Size;

    
    return Date;
}
stDate IncreaseDateByOneDecade(stDate Date) {
  
    Date.Year += 10;
    return Date;
}
stDate IncreaseDateByXDecades(stDate Date, int Size) {
    for (short i = 0; i < Size; i++) {//                   or Size*10
      Date=  IncreaseDateByOneDecade(Date); //  Date=  IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXDecadesFaster(stDate Date, int Size) {

       Date.Year += Size*10;

    
    return Date;
}
stDate IncreaseDateByOneCentury(stDate& Date) {
    Date.Year += 100;
  
    return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date) {
    
        Date.Year += 1000;
    
    return Date;
}





void SwapDates(stDate& Date1, stDate& Date2) {
    stDate TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    int SwapFlag = 1;

    if (!IsDate1BeforeDate2(Date1, Date2)) {
        SwapDates(Date1, Date2);
        SwapFlag = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    if (IncludeEndDay) Days++;
    return Days * SwapFlag;
}

short ReadDay() {
    short Day;
    cout << "Please enter a Day: ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
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

string DisplayDates(stDate Date) {
    string S1 = to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year)+"\n";

    return S1;

}

int main() {
    cout << "Enter first date:\n";
    stDate Date1 = ReadFullDate();
    cout << "Date After: \n\n";
    Date1 = IncreaseDateByOneDay(Date1);
    cout<<"Adding one day is: "<<DisplayDates(Date1);

    Date1= IncreaseDateByXDay(Date1, 10);
    cout << "Adding 10 days is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByOneWeek(Date1);
    cout << "Adding one week  is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByXWeeks(Date1,10);
    cout << "Adding 10 week days is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByOneMonth(Date1);
    cout << "Adding one  month  is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByXMonth(Date1,5);
    cout << "Adding 10  months  is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByOneYear(Date1);
    cout << "Adding one  year  is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByXYear(Date1, 10);
    cout << "Adding 10  years  is: " << DisplayDates(Date1);
     
    Date1 = IncreaseDateByXYearFaster(Date1, 10);
    cout << "Adding 10  years  is(faster): " << DisplayDates(Date1);

    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "Adding one  decade  is: " << DisplayDates(Date1);


    Date1 = IncreaseDateByXDecades(Date1, 10);
    cout << "Adding 10  decades  is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByXDecadesFaster(Date1, 10);
    cout << "Adding 10  decades  is (faster) : " << DisplayDates(Date1);

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "Adding one  century  is: " << DisplayDates(Date1);

    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "Adding one  Millennium  is: " << DisplayDates(Date1);








 
    return 0;
}
