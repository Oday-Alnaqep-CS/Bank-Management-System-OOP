#pragma warning (disable : 4996)
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "ClsString.h"

using namespace std;


class ClsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:
    ClsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    ClsDate(string Date)
    {
        vector<string> vDate;
        vDate = ClsString::SplitString(Date, "/");

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

    ClsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    ClsDate(short DayOrderInYear, short Year)
    {
        ClsDate Date1 = GetDateFromDayOrderInYear(DayOrderInYear, Year);
        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Date1.Year;
    }

    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year, Hour, Miunet, Second;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Miunet = now->tm_min;
        Second = now->tm_sec;

        return ( to_string(Day) + "/" + to_string(Month) + "/" +
            to_string(Year) + " - " + to_string(Hour) + ":" +
            to_string(Miunet) + ":" + to_string(Second) );

    }

    void SetDay(short Day)
    {
        _Day = Day;
    }

    short GetDay()
    {
        return _Day;
    }

    __declspec(property(get = GetDay, put = SetDay)) short Day;

    void SetMonth(short Month)
    {
        _Month = Month;
    }

    short GetMonth()
    {
        return _Month;
    }

    __declspec(property(get = GetMonth, put = SetMonth)) short Month;

    void SetYear(short Year)
    {
        _Year = Year;
    }

    short GetYear()
    {
        return _Year;
    }

    __declspec(property(get = GetYear, put = SetYear)) short Year;

    void Print()
    {
        cout << DateToString() << endl;
    }

    static ClsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        short Day, Month, Year;

        Day = now->tm_mday;
        Month = now->tm_mon + 1;
        Year = now->tm_year + 1900;

        return ClsDate(Day, Month, Year);
    
    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static bool IsLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }

    static short NUmberOfDayInYear(short Year)
    {
        return IsLeapYear(Year) ? 366 : 365;
    }
     
    short NUmberOfDayInYear()
    {
        return NUmberOfDayInYear(_Year);
    }

    static short NumberOfHourInYear(short Year)
    {
        return NUmberOfDayInYear(Year) * 24;
    }

    short NumberOfHourInYear()
    {
        return NumberOfHourInYear(_Year);
    }

    static short NumberOfMinuteInYear(short Year)
    {
        return NumberOfHourInYear(Year) * 60;
    }

    short NumberOfMinuteInYear()
    {
        return NumberOfMinuteInYear(_Year);
    }

    static short NumberOfSecondInYear(short Year)
    {
        return NumberOfMinuteInYear(Year) * 60;
    }

    short NumberOfSecondInYear()
    {
        return NumberOfSecondInYear(_Year);
    }

    static short NumberOfDayInMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;

        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (Month == 2) return IsLeapYear(Year) ? 29 : 28;
        return days[Month - 1];
    }

    short NumberOfDayInMonth()
    {
        return NumberOfDayInMonth(_Month, _Year);
    }

    static short numberOfHourInMonth(short Month, short Year)
    {
        return NumberOfDayInMonth(Month, Year) * 24;
    }

    short numberOfHourInMonth()
    {
        return numberOfHourInMonth(_Month, _Year);
    }

    static short numberOfMinuteInMonth(short Month, short Year)
    {
        return numberOfHourInMonth(Month, Year) * 60;
    }

    short numberOfMinuteInMonth()
    {
        return numberOfMinuteInMonth(_Month, _Year);
    }

    static short numberOfSecondInMonth(short Month, short Year)
    {
        return numberOfMinuteInMonth(Month, Year) * 60;
    }

    short numberOfSecondInMonth()
    {
        return numberOfSecondInMonth(_Month, _Year);
    }

    static 	short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;
        //Gregorin

        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 10)) % 7;
    }

    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string Monthshortname(short MonthNumber)
    {
        string MonthsName[] = { "Jan","Feb","Mar"
            ,"Ape","May","Jun","Jul","Aug","Sep",
            "Oct","nov","Dec"
        };
        return MonthsName[MonthNumber - 1];
    }

    string Monthshortname()
    {
        return Monthshortname(_Month);
    }

    static string Dayshortname(short DayOfWeekOrder)
    {
        string DaysName[] = { "Sat","Sun","Mon","Tue","Wed","Thu","Fri" };
        return DaysName[DayOfWeekOrder];
    }

    string Dayshortname()
    {
        return Dayshortname(DayOfWeekOrder());
    }

    static string DayShortName(short Day, short Month, short Year)
    {
        return Dayshortname(DayOfWeekOrder(Day, Month, Year));
    }

    string DayShortname()
    {
        string DaysName[] = { "Sat","Sun","Mon","Tue","Wed","Thu","Fri" };
        return DaysName[DayOfWeekOrder(_Day, _Month, _Year)];
    }

    static void PrintMonthsCliender(short Month, short Year) 
    {

        // Index of the day from 0 to 6
        int Curent = DayOfWeekOrder(1, Month, Year);
        int DaysInMonth = NumberOfDayInMonth(Month, Year);

        printf("\n  _______________ %s _______________\n", Monthshortname(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");


        short i;
        for (i = 0; i < Curent; i++) {
            printf("     ");
        }

        for (short j = 1; j <= DaysInMonth; j++) {
            printf("%5d", j);

            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }
        printf("\n  ___________________________________\n");
    }

    void PrintMonthsCliender()
    {
        PrintMonthsCliender(_Month, _Year);
    }

    static void PrintYearCliendar(short Year)
   {
       printf("_____________________________________________________");
       printf("               Cliendar _ %d", Year);
       printf("_____________________________________________________");

       for (short i = 1; i <= 12; i++)
         {
           PrintMonthsCliender(i, Year);
         }
   }

    void PrintYearCliendar()
   {
       PrintYearCliendar(_Year);
   }

    static short NumberOfDayFromTheBeginingOfTheYear(short Day, short Month, short Year)
   {
       short TotalDays = 0;
       for (short i = 1; i < Month - 1; i++)
       {
           TotalDays += NumberOfDayInMonth(i, Year);
       }
       TotalDays += Day;
       return TotalDays;
   }

    short NumberOfDayFromTheBeginingOfTheYear()
   {
       short TotalDays = 0;
       for (short i = 1; i < Month - 1; i++)
       {
           TotalDays += NumberOfDayInMonth(i, _Year);
       }
       TotalDays += Day;
       return TotalDays;
   }
   
    static ClsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        ClsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        Date.Year = Year;
        Date.Month = 1;


        while (true)
        {
            MonthDays = NumberOfDayInMonth(Date.Month, Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;
            }
            else
            {
                Date.Day = RemainingDays;
                break;
            }
        }
        return Date;
    }

    void AddDayss(short Days)
    {
        *this = IncreaseDayByXDay(Days, *this);
    }

    void AddDays(short Days)
    {
        short ReminingDays = Days;

        while (ReminingDays > 0)
        {
            short DaysInCurrentMonth = NumberOfDayInMonth(_Month, _Year);
            short RemainingDaysInCurrentMonth = DaysInCurrentMonth - _Day;
            if (ReminingDays > RemainingDaysInCurrentMonth)
            {
                ReminingDays -= (RemainingDaysInCurrentMonth + 1);
                _Day = 1;
                if (_Month == 12)
                {
                    _Month = 1;
                    _Year++;
                }
                else
                {
                    _Month++;
                }
            }
            else
            {
                _Day += ReminingDays;
                break;
            }
        }
    }

    enum eDateCompare
    {
        Befor = -1, Equal = 0, After = 1
    };

    static bool IsDate1BeforDate2(ClsDate Date1, ClsDate Date2)
    {
        return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }
    
    bool IsDate1BeforDate2(ClsDate Date2)
    {
        return IsDate1BeforDate2(*this, Date2);
    }

    static bool IsDate1AfterDate2(ClsDate Date1, ClsDate Date2)
    {
        return  (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day > Date2.Day : false)) : false);
    }

    bool IsDate1AfterDate2(ClsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(ClsDate Date1, ClsDate Date2)
    {
        return  (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
    }

    bool IsDate1EqualDate2(ClsDate Date2)
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static eDateCompare CompareTwoDates(ClsDate Date1, ClsDate Date2)
    {
        return IsDate1BeforDate2(Date1, Date2) ? Befor 
            : (IsDate1AfterDate2(Date1, Date2) ? After 
                : Equal);
    }

    eDateCompare CompareTwoDates(ClsDate Date2)
    {
        return CompareTwoDates(*this, Date2);
    }
    
    static string DateToString(ClsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

     string DateToString()
    {
        return DateToString(*this);
    }

    static bool IsLastDayInMonth(ClsDate Date)
    {
        return (Date.Day == NumberOfDayInMonth(Date.Month, Date.Year));
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(_Month);
    }

    static ClsDate AddOneDay(ClsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Month = 1;
                Date.Day = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }
        return Date;
    }

    void AddOneDay()
    {
        *this = AddOneDay(*this);
    }

    static void SwapDates(ClsDate& Date1, ClsDate& Date2)
    {
        ClsDate TempDate;
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    void SwapDates(ClsDate& Date2)
    {
        SwapDates(*this, Date2);
    }

    static int GetDifferenceDays(ClsDate Date1, ClsDate Date2, bool IncludeEndDay = false)
    {
        short Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;

    }

    int GetDifferenceDays(ClsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceDays(*this, Date2, IncludeEndDay);
    }

    static short CalculateMyAgeInDays(ClsDate DateOfBirth)
    {
        return GetDifferenceDays(DateOfBirth,
            ClsDate::GetSystemDate(), true);
    }

    static ClsDate IncreaseDateByOneDay(ClsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }
        return Date;
    }

    void IncreaseDateByOneDay()
    {
        *this = IncreaseDateByOneDay(*this);
    }

    static ClsDate IncreaseDayByXDay(short Days, ClsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    void IncreaseDayByXDay(short Days)
    {
        *this = IncreaseDayByXDay(Days, *this);
    }

    static ClsDate IncreaseDateByOneWeek(ClsDate& Date)
    {
        for (short i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }

    static ClsDate IncreaseDateByXWeek(short Weeks, ClsDate& Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeek(short Weeks)
    {
        *this = IncreaseDateByXWeek(Weeks, *this);
    }

    static ClsDate IncreaseDateByOneMonth(ClsDate Date)
    {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

        short NumberOfDaysInMonth = NumberOfDayInMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInMonth)
        {
            Date.Day = NumberOfDaysInMonth;

        }
        return Date;
    }

    void IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    static ClsDate IncreaseDateByXMonth(short Months, ClsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void IncreaseDateByXMonth(short Months)
        {
            *this = IncreaseDateByXMonth(Months, *this);
        }

    static ClsDate IncreaseDateByOneYear(ClsDate Date)
    {
        Date.Year++;
        return Date;
    }

    void IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }

    static ClsDate IncreaseDateByXyear(short Years, ClsDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    void IncreaseDateByXyear(short Years)
    {
        *this = IncreaseDateByXyear(Years, *this);
    }
      
    static ClsDate IncraeseDateByXYearsFaster(short Years, ClsDate Date)
    {
        Date.Year += Years;
        return Date;
    }

    void IncraeseDateByXYearsFaster(short Years)
    {
        *this = IncraeseDateByXYearsFaster(Years, *this);
    }

    static ClsDate IncreaseDateByOneDecad(ClsDate Date)
    {
        Date.Year += 10;
        return Date;
    }

    void IncreaseDateByOneDecad()
    {
        *this = IncreaseDateByOneDecad(*this);
    }

    static  ClsDate IncraeseDateByXDecade(short Decade, ClsDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
   
    void IncraeseDateByXDecade(short Decade)
    {
        *this = IncraeseDateByXDecade(Decade, *this);
    }

    static  ClsDate IncraeseDateByXDecadeFaster(short Decade, ClsDate Date)
    {
        Date.Year += Decade * 10;
        return Date;
    }

    void IncraeseDateByXDecadeFaster(short Decade)
    {
        *this = IncraeseDateByXDecadeFaster(Decade, *this);
    }

    static  ClsDate IncreaseDateByOneCentury(ClsDate Date)
    {
        Date.Year += 100;
        return Date;
    }

    void IncreaseDateByOneCentury()
    {
        *this = IncreaseDateByOneCentury(*this);
    }

    static  ClsDate IncreaseDateByXCentury(short Century, ClsDate Date)
    {
        for (short i = 1; i <= Century * 10; i++)
        {
            Date = IncreaseDateByOneDecad(Date);
        }
        return Date;
    }

    void IncreaseDateByXCentury(short Century)
    {
        *this = IncreaseDateByXCentury(Century, *this);
    }

    static  ClsDate IncreaseDateByOneMillennium(ClsDate Date)
    {
        Date.Year += 1000;
        return Date;
    }

    void IncreaseDateByOneMillennium()
    {
        *this = IncreaseDateByOneMillennium(*this);

    }

    static  ClsDate DecreaseDateByOneDay(ClsDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Day = 31;
                Date.Month = 12;
                Date.Year--;
            }
            else
            {
                Date.Month--;
                Date.Day = NumberOfDayInMonth(Date.Month, Date.Year);
            }
        }
        else
        {
            Date.Day--;
        }
        return Date;
    }

    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static  ClsDate DecreaseDayByXDay(short Days, ClsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    void DecreaseDayByXDay(short Days)
    {
        *this = DecreaseDayByXDay(Days, *this);
    }

    static  ClsDate DecreaseDateByOneWeek(ClsDate Date)
    {
        for (short i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    void DecreaseDateByOneWeek()
    {
        *this = DecreaseDateByOneWeek(*this);
    }

    static  ClsDate DecreaseDateByXWeek(short Weeks, ClsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void DecreaseDateByXWeek(short Weeks)
    {
        *this = DecreaseDateByXWeek(Weeks, *this);
    }

    static  ClsDate DecreaseDateByOneMonth(ClsDate Date)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        short NumberOfDaysInMonth = NumberOfDayInMonth(Date.Month, Date.Year);
        (Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInMonth)
        {
            Date.Day = NumberOfDaysInMonth;

        }
        return Date;
    }

    void DecreaseDateByOneMonth()
    {
        *this = DecreaseDateByOneMonth(*this);
    }

    static  ClsDate DecreaseDateByXMonth(short Months, ClsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void DecreaseDateByXMonth(short Months)
    {
        *this = DecreaseDateByXMonth(Months, *this);
    }

    static  ClsDate DecreaseDateByOneYear(ClsDate Date)
    {
        Date.Year--;
        return Date;
    }

    void DecreaseDateByOneYear()
    {
        *this = DecreaseDateByOneYear(*this);
    }

    static  ClsDate DecreaseDateByXyear(short Years, ClsDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    void DecreaseDateByXyear(short Years)
    {
        *this = DecreaseDateByXyear(Years, *this);
    }

    static  ClsDate DecraeseDateByXYearsFaster(short Years, ClsDate Date)
    {
        Date.Year -= Years;
        return Date;
    }

    void DecraeseDateByXYearsFaster(short Years)
    {
        *this = DecraeseDateByXYearsFaster(Years, *this);
    }

    static  ClsDate DecreaseDateByOneDecad(ClsDate Date)
    {
        Date.Year -= 10;
        return Date;
    }

    void DecreaseDateByOneDecad()
    {
        *this = DecreaseDateByOneDecad(*this);
    }

    static  ClsDate DecraeseDateByXDecade(short Decade, ClsDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    void DecraeseDateByXDecade(short Decade)
    {
        *this = DecraeseDateByXDecade(Decade, *this);
    }

    static  ClsDate DecraeseDateByXDecadeFaster(short Decade, ClsDate Date)
    {
        Date.Year -= Decade * 10;
        return Date;
    }

    void DecraeseDateByXDecadeFaster(short Decade)
    {
        *this = DecraeseDateByXDecadeFaster(Decade, *this);
    }

    static  ClsDate DecreaseDateByOneCentury(ClsDate Date)
    {
        Date.Year -= 100;
        return Date;
    }

    void DecreaseDateByOneCentury()
    {
        *this = DecreaseDateByOneCentury(*this);
    }

    static  ClsDate DecreaseDateByXCentury(short Century, ClsDate Date)
    {
        for (short i = 1; i <= Century * 10; i++)
        {
            Date = DecreaseDateByOneDecad(Date);
        }
        return Date;
    }

    void DecreaseDateByXCentury(short Century)
    {
        *this = DecreaseDateByXCentury(Century, *this);
    }

    static  ClsDate DecreaseDateByOneMillennium(ClsDate Date)
    {
        Date.Year -= 1000;
        return Date;
    }

    void DecreaseDateByOneMillennium()
    {
        *this = DecreaseDateByOneMillennium(*this);
    }

    static short IsEndOfWeek(ClsDate Date)
    {
        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
    }

    short IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(ClsDate Date)
    {
        short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        return (DayIndex == 5 || DayIndex == 6);
    }

    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(ClsDate Date)
    {

        //return (!DayIndex == 6 || !DayIndex == 7);
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(ClsDate Date)
    {
        return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }
     
    void DaysUntilTheEndOfWeek()
    {
        DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(ClsDate Date)
    {
        ClsDate EndOfMonthDate;
        EndOfMonthDate.Day = NumberOfDayInMonth(Date.Month, Date.Year);
        EndOfMonthDate.Month = Date.Month;
        EndOfMonthDate.Year = Date.Year;

        return GetDifferenceDays(Date, EndOfMonthDate, true);
    }

    void DaysUntilTheEndOfMonth()
        {
            DaysUntilTheEndOfMonth(*this);
        }

    static short DaysUntilTheEndOfYear(ClsDate Date)
    {
        ClsDate EndOfYearDate;
        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date.Year;

        return GetDifferenceDays(Date, EndOfYearDate, true);
    }

    short  DaysUntilTheEndOfYear()
    {
       return DaysUntilTheEndOfYear(*this);
    }

    static short  CalculateVacationDays(ClsDate DateFrom, ClsDate DateTo)
    {
        short DaysCount = 0;
        while (IsDate1BeforDate2(DateFrom, DateTo))
        {
            if (!IsBusinessDay(DateFrom))
            {
                DaysCount++;
            }
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DaysCount;
    }

    void CalculateVacationDays(ClsDate DateTo)
    {
       CalculateVacationDays(*this, DateTo);
    }

    static ClsDate CalculateVacationReturnDate(ClsDate DateFrom, short VacstionDays)
    {
        short WeekEndCounter = 0;

        if (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        for (short i = 1; i <= VacstionDays + WeekEndCounter; i++)
        {
            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        if (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DateFrom;
    }

    void CalculateVacationReturnDate(short VacstionDays)
    {
         CalculateVacationReturnDate(*this, VacstionDays);
    }

    static short  CalculateBusinessDays(ClsDate DateFrom, ClsDate DateTo)
    {
        short DaysCount = 0;
        while (IsDate1BeforDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
            {
                DaysCount++;
            }
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DaysCount;
    }

    static bool IsValidDate(ClsDate Date)
    {
        if (Date.Day < 1 || Date.Day > 31)
            return false;

        if (Date.Month < 1 || Date.Month > 12)
            return false;

        if (Date.Month == 2)
        {
            if (IsLeapYear(Date.Year))
            {
                if (Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day < 28)
                    return false;
            }
        }
        short DaysInMonth = NumberOfDayInMonth(Date.Month, Date.Year);
        if (Date.Day > DaysInMonth)
            return false;
        return true;
    }

    void IsValidDate()
    {
        IsValidDate(*this);
    }

 


};












































