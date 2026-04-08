#pragma once
#include<iostream>
#include "ClsDate.h"
using namespace std;

class ClsPeriod
{

private:

    enum eDateCompare
    {
        Befor = -1, Equal = 0, After = 1
    };

    ClsDate _StartDate;
    ClsDate _EndDate;

public:

    ClsPeriod()
    {
        

    }

    ClsPeriod(ClsDate StartDate, ClsDate EndDate)
    {
        this->_StartDate = StartDate;
        this->_EndDate = EndDate;
    }

    static bool IsOverlapPeriods(ClsPeriod Period1, ClsPeriod Period2)
    {

        if (
            ClsDate::CompareTwoDates(Period2._EndDate, Period1._StartDate) == ClsDate::eDateCompare::Befor
            ||
            ClsDate::CompareTwoDates(Period2._StartDate, Period1._EndDate) == ClsDate::eDateCompare::After
            )
            return false;
        else
            return true;

    }

    bool IsOverLapWith(ClsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    static int PreiodLenghInDays(ClsPeriod Period, bool IncludeEndDate = false)
    {
        return (ClsDate::GetDifferenceDays(Period._StartDate, Period._EndDate, IncludeEndDate));
    }

    static bool IsDateInPeriod(ClsDate Date, ClsPeriod Period)
    {
        return !(ClsDate::CompareTwoDates(Date, Period._StartDate) == eDateCompare::Befor

            ||

            ClsDate::CompareTwoDates(Date, Period._EndDate) == eDateCompare::After);
    }

    bool IsDateInPeriod(ClsDate Date)
    {
        return IsDateInPeriod(Date, *this);
    }

    static int CountOverlapDays(ClsPeriod Period1, ClsPeriod Period2)
    {
        int Period1Length = PreiodLenghInDays(Period1, true);
        int Period2Length = PreiodLenghInDays(Period2, true);
        int OverLapDays = 0;

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length)
        {
            while (ClsDate::IsDate1BeforDate2(Period1._StartDate, Period1._EndDate))
            {
                if (IsDateInPeriod(Period1._StartDate, Period2))
                    OverLapDays++;

                Period1._StartDate = ClsDate::IncreaseDateByOneDay(Period1._StartDate);
            }
        }
        else
        {
            while (ClsDate::IsDate1BeforDate2(Period2._StartDate, Period2._EndDate))
            {
                if (IsDateInPeriod(Period2._StartDate, Period1))
                    OverLapDays++;

                Period2._StartDate = ClsDate::IncreaseDateByOneDay(Period2._StartDate);
            }
        }

        return OverLapDays;

    }

    int CountOverlapDays(ClsPeriod Period2)
    {
        return CountOverlapDays( Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        _StartDate.Print();


        cout << "Period End: ";
        _EndDate.Print();


    }
};