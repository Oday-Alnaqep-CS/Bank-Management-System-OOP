#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"


class ClsDeleteClienScreen : public ClsScreen
{

private:

    static void _PrintClient(ClsBankClient Client)
    {
        cout <<  "" << "\t\tClient Card:" << endl;
        cout <<  "" << "===================================" << endl;
        cout <<  "" << "First Name  : " << Client.FirstName << endl;
        cout <<  "" << "Last Name   : " << Client.LastName << endl;
        cout <<  "" << "Full Name   : " << Client.Get_FullName() << endl;
        cout <<  "" << "Email       : " << Client.Email << endl;
        cout <<  "" << "Phone       : " << Client.Phone << endl;
        cout <<  "" << "Acc. Number : " << Client.Get_AccountNumber() << endl;
        cout <<  "" << "Pin Code    : " << Client.PinCode << endl;
        cout << fixed << setprecision(0);
        cout <<  "" << "Balance SAR : " << Client.BalanceSAR << endl;
        cout <<  "" << "Balance USD : " << Client.BalanceUSD << endl;
        cout <<  "" << "Balance YRN : " << Client.BalanceYRN << endl;
        cout <<  "" << "Balance YRO : " << Client.BalanceYRO << endl;
        cout <<  "" << "Account Balance in YER : " << Client.Get_AccountBalance() << endl;
        cout <<  "" << "===================================" << endl;


    }

public:

  
    static void DeleteClient()
    {

        if (!CheckAccessRight(ClsUser::enPermissions::pDeleteClients))
        {
            return;
        }

        string Title = "\t\tDelete Client Screen";

        _DrawScreenHeader(Title);

        string AccountNumber;

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = ClsInputValidate::ReadString();
        while (!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount is not found, Choose another one: ";
            AccountNumber = ClsInputValidate::ReadString();
        }

        ClsBankClient DeleteClient = ClsBankClient::Find(AccountNumber);
        _PrintClient(DeleteClient);

        cout << "\nAre you sure you want to delete this Client y/n?  ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (DeleteClient.Delete())
            {
                cout << "\nClient Deleted Successfully :-) ";
               _PrintClient(DeleteClient);
            }
            else
            {
                cout << "\nError Client was not Deleted.";
            }

        }
        else
        {
            cout << "\nError Client was not Deleted.";
        }

    }

};

