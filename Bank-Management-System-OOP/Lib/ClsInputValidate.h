#pragma once
#include <iostream>
#include <string>
#include "ClsString.h"
#include "CLsDate.h"
using namespace std;

class ClsInputValidate
{
public:

  
    static bool IsNumberBetween(short Number, short From, short To)
    {
        return Number >= From && Number <= To;
    }

    
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }

    
    static bool IsNumberBetween(float Number, float From, float To)
    {
        return Number >= From && Number <= To;
    }

    
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return Number >= From && Number <= To;
    }

    
    static bool IsDateBetween(const ClsDate& Date, const ClsDate& From, const ClsDate& To)
    {
        if (ClsDate::IsDate1AfterDate2(Date, From) || ClsDate::IsDate1EqualDate2(Date, From)
            && (ClsDate::IsDate1BeforDate2(Date, To) || ClsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        if(ClsDate::IsDate1AfterDate2(Date,To) || ClsDate::IsDate1EqualDate2(Date,To)
            && (ClsDate::IsDate1BeforDate2(Date,From) || ClsDate::IsDate1EqualDate2(Date,From)))
        {
            return true;
        }
        return false;
    }

    
    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Please Enter again:")
    {
        int Number;
        while (!(cin >> Number))
        { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
        }
        return Number;
    }

    
    static int ReadIntNumberBetween( int From, int To, string ErrorMessage = "NUmber Is Not Within range, Please Enter again:")
    {
        int Number = ReadIntNumber();
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage << endl;
            Number = ReadIntNumber();
        }
        return Number;
    }


    static short ReadShorrtNumber(string ErrorMessage = "Invalid Number, Please Enter again:")
    {
        short Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
        }
        return Number;
    }


    static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "NUmber Is Not Within range, Please Enter again:")
    {
        short Number = ReadShorrtNumber();
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage << endl;
            Number = ReadShorrtNumber();
        }
        return Number;
    }


    static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Please Enter again:")
    {
        float Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
        }
        return Number;
    }

    
    static double ReadDoubleNumber(string ErrorMessage = "Invalid Number, Please Enter again:")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
        }
        return Number;
    }

    
    static double ReadDooubleNumberBetween(double From, double To, string ErrorMessage = "NUmber Is Not Within range, Please Enter again:")
    {
        double Number = ReadDoubleNumber();
        while (!IsNumberBetween(Number, From, To))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
            Number = ReadDoubleNumber();
        }
        return Number;
    }

    
    static bool IsValideDate(ClsDate Date)
    {
        return	ClsDate::IsValidDate(Date);
    }

    
    static string ReadString()
    {
        string S1 = "";
        getline(cin >> ws, S1);
        return S1;
    }

};

