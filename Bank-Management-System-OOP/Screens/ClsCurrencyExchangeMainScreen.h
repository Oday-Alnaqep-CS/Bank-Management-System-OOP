#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsCurrencyListScreen.h"
#include "ClsFindCurrencyScreen.h"
#include "ClsUpdateCurrencyRate.h"
#include "ClsCurrencyCalculatorScreen.h"


using namespace std;

class ClsCurrencyExchangeMainScreen :protected ClsScreen
{

private:
    enum enCurrenciesMainMenueOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short ReadCurrenciesMainMenueOptions()
    {
        cout << setw(50) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = ClsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");
        ShowCurrenciesMenue();
    }

    static void _ShowCurrenciesListScreen()
    {
       // cout << "\nCurriencies List Screen Will Be Here.\n";
        ClsCurrencyListScreen::ShowCurrencyListScreen();
        
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen Will Be Here.\n";
        ClsFindCurrencyScreen::ShowFindCurrency();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        //cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
        ClsUpdateCurrencyRate::ShowUpdateCurrencyRate();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "\nCurrency Calculator Screen Will Be Here.\n";
        ClsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
    {

        switch (CurrenciesMainMenueOptions)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:

    static void ShowCurrenciesMenue()
    {

        if (!CheckAccessRight(ClsUser::enPermissions::pCurrencyExchange))
        {
            system("pause");
            return;
        }

        int S = 50;
        system("cls");
        _DrawScreenHeader("\t\t  Currancy Exhange Main Screen");

        cout << setw(S) << left << "" << "===================================================\n";
        cout << setw(S) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(S) << left << "" << "===================================================\n";
        cout << setw(S) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(S) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(S) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(S) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(S) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(S) << left << "" << "===================================================\n";

        _PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)ReadCurrenciesMainMenueOptions());
    }

};

