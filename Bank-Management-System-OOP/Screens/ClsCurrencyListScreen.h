#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsCurrency.h"

using namespace std;

class ClsCurrencyListScreen : protected ClsScreen
{

private:

    static void _PrintCurrencyRecordLine(ClsCurrency Currency)
    {

        cout << "|  " << setw(30) << left << Currency.Country();
        cout << "|  " << setw(8) << left << Currency.CurrencyCode();
        cout << "|  " << setw(45) << left << Currency.CurrecyName();
        cout << "|  " << setw(10) << left << Currency.Rate();

    }



public:

    static void ShowCurrencyListScreen()
    {
        vector <ClsCurrency> vCurrency = ClsCurrency::Get_Currencylist();
        string Title = "\t\tCurrency List Scrren";
        string SubTitle = "\t\t (" + to_string(vCurrency.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n__________________________________________________________________________";
        cout << "______________________________\n\n";

        cout << "|  " << left << setw(30) << "Country";
        cout << "|  " << left << setw(8) << "Code";
        cout << "|  " << left << setw(45) << "Name";
        cout << "|  " << left << setw(10) << "Rate/(1$)";


        cout << "\n\n__________________________________________________________________________";
        cout << "______________________________\n";

        if (vCurrency.size() == 0)
            cout << "\t\t\t\t No Currncies Avalible IN System!.\n";

        else

            for (ClsCurrency& Currncy : vCurrency)
            {
                _PrintCurrencyRecordLine(Currncy);
                cout << endl;
            }



        cout << "__________________________________________________________________________";
        cout << "______________________________\n";


    }
};

