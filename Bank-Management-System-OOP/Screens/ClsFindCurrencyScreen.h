#pragma once
#include <iostream>
#include <iomanip>
#include "ClsCurrency.h"
#include "ClsScreen.h"
#include "ClsInputValidate.h"

using namespace std;

class ClsFindCurrencyScreen :protected ClsScreen
{

private:

    static void _PrintCurrency(ClsCurrency Currency)
    {
        int s = 1;

        cout << "\n" << setw(s) << "" << "----------- Currency Card ------------";
        cout << "\n" << setw(s) << "" << "--------------------------------------";
        cout << "\n" << setw(s) << "" << "OCuntry     : " << Currency.Country();
        cout << "\n" << setw(s) << "" << "Code        : " << Currency.CurrencyCode();
        cout << "\n" << setw(s) << "" << "Name        : " << Currency.CurrecyName();
        cout << "\n" << setw(s) << "" << "Rate(1$) =  : " << Currency.Rate();
        cout << "\n" << setw(s) << "" << "=======================================";
    }

    static void _ShowResult(ClsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency found Successfully :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency was not found :-(\n";
        }
    }

public:

    static void ShowFindCurrency()
    {
        _DrawScreenHeader("\t\tFind Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 0;
        cin >> Answer;

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter Cureency Code: ";
            CurrencyCode = ClsInputValidate::ReadString();
            ClsCurrency Currency = Currency.FindByCode(CurrencyCode);
            _ShowResult(Currency);
        }
        else
        {
            string CountryName;
            cout << "\nPlease Enter Country Name: ";
            CountryName = ClsInputValidate::ReadString();
            ClsCurrency Country = Country.FindByCountry(CountryName);
            _ShowResult(Country);
        }
    }
};

