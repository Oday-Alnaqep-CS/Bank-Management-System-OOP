#pragma once
#include <iostream>
#include <iomanip>
#include "ClsCurrency.h"
#include "ClsScreen.h"
#include "ClsInputValidate.h"

using namespace std;

class ClsUpdateCurrencyRate :protected ClsScreen
{
private:

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float Rate = 0;

        Rate = ClsInputValidate::ReadFloatNumber();
        return Rate;
    }

    static void _PrintCurrency(ClsCurrency Currency)
    {
        int s = 1;

        cout << "\n" << setw(s) << "" << "----------- Currency Card ------------";
        cout << "\n" << setw(s) << "" << "--------------------------------------";
        cout << "\n" << setw(s) << "" << "Country     : " << Currency.Country();
        cout << "\n" << setw(s) << "" << "Code        : " << Currency.CurrencyCode();
        cout << "\n" << setw(s) << "" << "Name        : " << Currency.CurrecyName();
        cout << "\n" << setw(s) << "" << "Rate(1$) =  : " << Currency.Rate();
        cout << "\n" << setw(s) << "" << "=======================================";
    }

public:

    static void ShowUpdateCurrencyRate()
    {
        _DrawScreenHeader("\t\tUpdate Currency Screen");

        string CurrencyCode;
        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = ClsInputValidate::ReadString();

        if (!ClsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCUrrency is not found, Chosse another one: ";
            CurrencyCode = ClsInputValidate::ReadString();
        }

        ClsCurrency Currency = Currency.FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this courrency y/n ? ";

        char Answer ;
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            int s = 1;
            cout << "\n" << setw(s) << "" << "-------- Update Currency Rate --------";
            cout << "\n" << setw(s) << "" << "--------------------------------------";

            Currency.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Update Successfully :-)\n";
            _PrintCurrency(Currency);
        }
    }


};

