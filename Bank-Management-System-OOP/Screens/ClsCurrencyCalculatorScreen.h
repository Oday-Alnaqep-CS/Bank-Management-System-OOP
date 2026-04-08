#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsCurrency.h"
#include "ClsInputValidate.h"

class ClsCurrencyCalculatorScreen :protected ClsScreen

{
private:

    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = ClsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static ClsCurrency _GetCurrency(string Message)
    {

        string CurrencyCode;
        cout << Message << " ";

        CurrencyCode = ClsInputValidate::ReadString();

        while (!ClsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = ClsInputValidate::ReadString();
        }

        ClsCurrency Currency = ClsCurrency::FindByCode(CurrencyCode);
        return Currency;

    }


    static  void _PrintCurrencyCard(ClsCurrency Currency, string Title = "Currency Card:")
    {
        int s = 1;
        cout << "\n" << setw(s) << "" << "-----------" << Title << "------------";
        cout << "\n" << setw(s) << "" << "--------------------------------------";
        cout << "\n" << setw(s) << "" << "Country     : " << Currency.Country();
        cout << "\n" << setw(s) << "" << "Code        : " << Currency.CurrencyCode();
        cout << "\n" << setw(s) << "" << "Name        : " << Currency.CurrecyName();
        cout << "\n" << setw(s) << "" << "Rate(1$) =  : " << Currency.Rate();
        cout << "\n" << setw(s) << "" << "=======================================\n";
        cout << endl;

    }

    static void _PrintCalculationsResults(float Amount, ClsCurrency Currency1, ClsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

    }


public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");

            _DrawScreenHeader("\tUpdate Currency Screen");

            ClsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
            ClsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;

        }


    }
};

