#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsScreen.h"

using namespace std;

class ClsClientListScreen : public ClsScreen
{
private:
    static void _PrintClientRecordLine(ClsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.Get_AccountNumber();
        cout << "| " << setw(20) << left << Client.Get_FullName();
        cout << "| " << setw(10) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(12) << left << Client.PinCode;
        cout << "| " << setw(10) << left << Client.BalanceSAR;
        cout << "| " << setw(10) << left << Client.BalanceUSD;
        cout << "| " << setw(10) << left << Client.BalanceYRN;
        cout << "| " << setw(10) << left << Client.BalanceYRO;
        cout << "| " << setw(10) << left << Client.Get_AccountBalance();

    }


public:

    static void ShowClientScreen()
    {

        if (!CheckAccessRight(ClsUser::enPermissions::pListClients))
        {
            return;
        }

        vector <ClsBankClient> vClients = ClsBankClient::Get_ClientsList();

        string Title = "\t\tClient List Screen";
        string SubTitle = "\t\t  (" + to_string(vClients.size()) + ") Client(s)\n";

        _DrawScreenHeader(Title, SubTitle);

      
        cout << "\n" << "______________________________________________________________";
        cout << "_______________________________________________________________________";
        cout << "____________________\n" << endl;

        cout << "| " << left << setw(15) << "Account Numbre";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(10) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Pin Code";
        cout << "| " << left << setw(10) << "SAR";
        cout << "| " << left << setw(10) << "USD";
        cout << "| " << left << setw(10) << "YRN";
        cout << "| " << left << setw(10) << "YRO";
        cout << "| " << left << setw(10) << "Balance in [YRN]";


        cout << "\n" << "______________________________________________________________";
        cout << "_______________________________________________________________________";
        cout << "____________________" << endl;


        if (vClients.size() == 0)

            cout << "\nNo Clients Availible in the System! ";

        else

            for (ClsBankClient& C : vClients)
            {
                _PrintClientRecordLine(C);
                cout << endl;
            }

        cout << "" << "______________________________________________________________";
        cout << "_______________________________________________________________________";
        cout << "____________________" << endl;
    
    }
};

