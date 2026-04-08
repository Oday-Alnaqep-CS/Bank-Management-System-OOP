#pragma once
#include <iostream>
#include <iomanip>
#include "ClsBankClient.h"
#include "ClsScreen.h"
#include "ClsInputValidate.h"

using namespace std;

class ClsAddClientsScreen : public ClsScreen
{

private:

    static void _ReadClientInfo(ClsBankClient& Client)
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
            cout << " \n"<< "" << "\t   Client Card:" << endl;
            cout << " " << "" << "===================================" << endl;
            cout << " " << "" << "First Name  : " << Client.FirstName << endl;
            cout << " " << "" << "Last Name   : " << Client.LastName << endl;
            cout << " " << "" << "Full Name   : " << Client.Get_FullName() << endl;
            cout << " " << "" << "Email       : " << Client.Email << endl;
            cout << " " << "" << "Phone       : " << Client.Phone << endl;
            cout << fixed << setprecision(0);
            cout << " " << "" << "Acc. Number : " << Client.Get_AccountNumber() << endl;
            cout << " " << "" << "Pin Code    : " << Client.PinCode << endl;
            cout << " " << "" << "Balance SAR : " << Client.BalanceSAR << endl;
            cout << " " << "" << "Balance USD : " << Client.BalanceUSD << endl;
            cout << " " << "" << "Balance YRN : " << Client.BalanceYRN << endl;
            cout << " " << "" << "Balance YRO : " << Client.BalanceYRO << endl;
            cout << " " << "" << "Account Balance in YER : " << fixed << 
                setprecision(0) <<  Client.Get_AccountBalance() << endl;
            cout << " " << "" << "===================================" << endl;
        

    }

public:

    static void ShowAddClientScreen()
    {


        if (!CheckAccessRight(ClsUser::enPermissions::pAddnewClients))
        {
            return;
        }

        string Title = "\t\tAdd New Client Screeb";

        _DrawScreenHeader(Title);


        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = ClsInputValidate::ReadString();
        while (ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is already used, choose another one: ";

            AccountNumber = ClsInputValidate::ReadString();
        }

        ClsBankClient NewClient = ClsBankClient::Get_AddNewClient(AccountNumber);

        cout << "\n\nAdd New Client Info:" << endl;
        cout << "=============================";
        _ReadClientInfo(NewClient);

        ClsBankClient::enSaveResults Results;
        Results = NewClient.Save();

        switch (Results)
        {
        case ClsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Added Successfully :-)";
            _PrintClient(NewClient);
            break;
        case ClsBankClient::enSaveResults::svFalidEmptyOpject:
            cout << "\nError: Account was not saved because it's Empty.";
            break;
        case ClsBankClient::enSaveResults::SaveFaileAccountNumerExists:
            cout << "\nError: Account was not saved because it's already used.";
            break;
        }
    }

};

