#pragma once
#include <iostream>
#include <iomanip>
#include "ClsBankClient.h"
#include "ClsScreen.h"
#include "clsUtil.h"

using namespace std;

class ClsTotalBalanceScreen : protected ClsScreen
{

private:

    static void _PrintClientRecordline(ClsBankClient Client)
    {
        cout << "| " << setw(20) << left << Client.Get_AccountNumber();
        cout << "| " << setw(30) << left << Client.Get_FullName();
        cout << "| " << setw(15) << left << Client.BalanceYRO;
        cout << "| " << setw(15) << left << Client.BalanceYRN;
        cout << "| " << setw(15) << left << Client.BalanceSAR;
        cout << "| " << setw(15) << left << Client.BalanceUSD;
        cout << "| " << setw(15) << left << Client.Get_AccountBalance();
    }


public:

    static void ShowTotalBalance()
    {

        vector <ClsBankClient> vClient = ClsBankClient::Get_ClientsList();

        string Title = "\t\t Balance List Screen";
        string SubTitle = "\t\t   (" + to_string(vClient.size()) + ") Client(s).";

        _DrawScreenHeader(Title,SubTitle);

        cout << "\n__________________________________________________";
        cout << "____________________________________________________";
        cout << "__________________________________________\n" << endl;

        cout << "| " << left << setw(20) << "Account Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(15) << "Balance YRO";
        cout << "| " << left << setw(15) << "Balance YRN";
        cout << "| " << left << setw(15) << "Balance SAR";
        cout << "| " << left << setw(15) << "Balance USD";
        cout << "| " << left << setw(25) << "Total Balance In YRN";

        cout << "\n__________________________________________________";
        cout << "____________________________________________________";
        cout << "__________________________________________" << endl;

        if (vClient.size() == 0)
            cout << "\nNo Info Avalible in the system!";

        double Total = ClsBankClient::Get_TotalBalance();

        for (ClsBankClient C : vClient)
        {
            _PrintClientRecordline(C);
            cout << endl;

        }

        cout << "__________________________________________________";
        cout << "____________________________________________________";
        cout << "__________________________________________" << endl;

        cout << "\n\n\t\t\tTotal Balance: " << fixed << setprecision(2) << Total << endl;
        cout << "\t\t\t(" << ClsUtil::NumberToText(Total) << ")" << endl;
    }
};

