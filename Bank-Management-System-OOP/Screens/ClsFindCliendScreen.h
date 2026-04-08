#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsBankClient.h"
#include "ClsInputValidate.h"

using namespace std;

class ClsFindCliendScreen : public ClsScreen
{

private:

    static void _PrintClient(ClsBankClient Client)
    {
        int s = 3;

        cout << "\n" << setw(s) << "" << "---------------------- Client Card ----------------------";
        cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
        cout << "\n" << setw(s) << "" << "First Name  : " << Client.FirstName;
        cout << "\n" << setw(s) << "" << "Last Name   : " << Client.LastName;
        cout << "\n" << setw(s) << "" << "Full Name   : " << Client.Get_FullName();
        cout << "\n" << setw(s) << "" << "Email       : " << Client.Email;
        cout << "\n" << setw(s) << "" << "Phone       : " << Client.Phone;
        cout << "\n" << setw(s) << "" << "Acc. Number : " << Client.Get_AccountNumber();
        cout << "\n" << setw(s) << "" << "Pin Code    : " << Client.PinCode;
        cout << "\n" << setw(s) << "" << "==========================================================";
        cout << "\n" << setw(s) << "" << " Currencies      |        Balance ";
        cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
        cout << "\n" << setw(s) << "" << "(SAR)            : " << Client.BalanceSAR;
        cout << "\n" << setw(s) << "" << "(USD)            : " << Client.BalanceUSD;
        cout << "\n" << setw(s) << "" << "(YRN)            : " << Client.BalanceYRN;
        cout << "\n" << setw(s) << "" << "(YRO)            : " << Client.BalanceYRO;
        cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
        cout << "\n" << setw(s) << "" << "Account Balance in (YER) : " << Client.Get_AccountBalance();
        cout << "\n" << setw(s) << "" << "==========================================================\n";
    }
public:

    static void ShowFindClientScreen()
    {

        if (!CheckAccessRight(ClsUser::enPermissions::pFindClients))
        {
            return;
        }

        string Title = "\t\tFind Client Screen";

        _DrawScreenHeader(Title);

        string AccountNumber;

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = ClsInputValidate::ReadString();
        while (!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount is not found, Choose another one: ";
            AccountNumber = ClsInputValidate::ReadString();
        }

        if (ClsBankClient::IsClientExist(AccountNumber))
        {

            ClsBankClient FindClient = ClsBankClient::Find(AccountNumber);
            _PrintClient(FindClient);

            cout << "\t\t\t\tFind Client Successfullt :-)" << endl;
        }
       


    }
};

