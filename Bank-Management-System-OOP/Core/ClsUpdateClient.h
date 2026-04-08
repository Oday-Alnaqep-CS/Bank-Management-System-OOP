#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

using namespace std;

class ClsUpdateClient : public ClsScreen
{
private :

   static void ReadClientInfo(ClsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = ClsInputValidate::ReadString();

        cout << "Enter LastName : ";
        Client.LastName = ClsInputValidate::ReadString();

        cout << "Enter Email    : ";
        Client.Email = ClsInputValidate::ReadString();

        cout << "Enter Phone    : ";
        Client.Phone = ClsInputValidate::ReadString();

        cout << "Enter PinCode  : ";
        Client.PinCode = ClsInputValidate::ReadString();

        cout << "Enter Balance [SAR] : ";
        Client.BalanceSAR = ClsInputValidate::ReadDoubleNumber();

        cout << "Enter Balance [USD] : ";
        Client.BalanceUSD = ClsInputValidate::ReadDoubleNumber();

        cout << "Enter Balance [YRN] : ";
        Client.BalanceYRN = ClsInputValidate::ReadDoubleNumber();

        cout << "Enter Balance [YRO] : ";
        Client.BalanceYRO = ClsInputValidate::ReadDoubleNumber();
    }

   static void _PrintClient(ClsBankClient Client)
   {
       cout << " \n" << setw(30) << "" << "\t\tClient Card:" << endl;
       cout << setw(30) << "" << "===================================" << endl;
       cout << setw(30) << "" << "First Name  : " << Client.FirstName << endl;
       cout << setw(30) << "" << "Last Name   : " << Client.LastName << endl;
       cout << setw(30) << "" << "Full Name   : " << Client.Get_FullName() << endl;
       cout << setw(30) << "" << "Email       : " << Client.Email << endl;
       cout << setw(30) << "" << "Phone       : " << Client.Phone << endl;
       cout << fixed << setprecision(0);
       cout << setw(30) << "" << "Acc. Number : " << Client.Get_AccountNumber() << endl;
       cout << setw(30) << "" << "Pin Code    : " << Client.PinCode << endl;
       cout << setw(30) << "" << "Balance SAR : " << Client.BalanceSAR << endl;
       cout << setw(30) << "" << "Balance USD : " << Client.BalanceUSD << endl;
       cout << setw(30) << "" << "Balance YRN : " << Client.BalanceYRN << endl;
       cout << setw(30) << "" << "Balance YRO : " << Client.BalanceYRO << endl;
       cout << setw(30) << "" << "Account Balance in YER : " << Client.Get_AccountBalance() << endl;
       cout << setw(30) << "" << "===================================" << endl;


   }

public:

    static void ShowUpdateClientscreen()
    {

        if (!CheckAccessRight(ClsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        string Title = "\t\tUpdate Client Screen";

        _DrawScreenHeader(Title);

        string AccountNumber = "";

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = ClsInputValidate::ReadString();
        while (!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount is not found, Choose another one: ";
            AccountNumber = ClsInputValidate::ReadString();
        }

        ClsBankClient Client = ClsBankClient::Find(AccountNumber);
         _PrintClient(Client);

        cout << "\n\nUpdate Client Info:" << endl;
        cout << "=============================";

        ReadClientInfo(Client);

        ClsBankClient::enSaveResults SaveResults;
        SaveResults = Client.Save();

        switch (SaveResults)
        {
        case ClsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Updated Successfully :-) ";
            _PrintClient(Client);
            break;
        case ClsBankClient::enSaveResults::svFalidEmptyOpject:
            cout << "\nError: Account was not found because it's Empty.";
            break;
        }

        system("pause");
    }

};

