#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsScreen.h"
#include "ClsInputValidate.h"

using namespace std;

class ClsTransferScreen : protected ClsScreen
{

private:

    static void _PrintClientCard(ClsBankClient Client)
    {

        int s = 3;

        cout << "\n" << setw(s) << "" << "---------------------- Client Card ----------------------";
        cout << "\n" << setw(s) << "" << "----------------------------------------------------------";    
        cout << "\n" << setw(s) << "" << "Full Name   : " << Client.Get_FullName();
        cout << "\n" << setw(s) << "" << "Acc. Number : " << Client.Get_AccountNumber();
        cout << "\n" << setw(s) << "" << "==========================================================";
        cout << "\n" << setw(s) << "" << " Currencies      |        Balance ";
        cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
        cout << "\n" << setw(s) << "" << "(SAR)            : " << Client.BalanceSAR;
        cout << "\n" << setw(s) << "" << "(USD)            : " << Client.BalanceUSD;
        cout << "\n" << setw(s) << "" << "(YRN)            : " << Client.BalanceYRN;
        cout << "\n" << setw(s) << "" << "(YRO)            : " << Client.BalanceYRO;
        cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
        cout << "\n" << setw(s) << "" << "Account Balance in (YER) : " << fixed << setprecision(0) <<
            Client.Get_AccountBalance();
        cout << "\n" << setw(s) << "" << "==========================================================\n";


    }

    static string _ReadAccounNumberTransferFrom()
    {

        string AccT_from;
        cout << "\nPlease Enter Account Number to transfer from: ";
        AccT_from = ClsInputValidate::ReadString();

        while (!ClsBankClient::IsClientExist(AccT_from))
        {
            cout << "\nAccount Number Is not found, Choose another one: ";
            AccT_from = ClsInputValidate::ReadString();

        }

        return AccT_from;
    }

    static string _ReadAccountNumberTransferTo()
    {

        string AccT_to;
        cout << "\nPlease Enter Account Number to transfer to: ";
        AccT_to = ClsInputValidate::ReadString();

        while (!ClsBankClient::IsClientExist(AccT_to))
        {
            cout << "\nAccount Number Is not found, Choose another one: ";
            AccT_to = ClsInputValidate::ReadString();

        }

        return AccT_to;
    }

    static float _ReadAmount(ClsBankClient SourceClient,int Currency)
    {
        float Amount;
        cout << "\nEnter transfer amount: ";
        Amount = ClsInputValidate::ReadFloatNumber();

        while (!SourceClient._Withdraw(Amount, Currency))
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = ClsInputValidate::ReadFloatNumber();
        }
        return Amount;

    }

    static int _ReadCurrency()
    {
        cout << "\nChoose Currency for Transfer:\n";
        cout << "1. YRO\n2. YRN\n3. USD\n4. SAR\n";
        cout << "Choice: ";

        int Currency = (ClsBankClient::eCurrency)ClsInputValidate::ReadIntNumberBetween(1, 4, "Invalid Choice, Enter (1-4): ");
        return Currency;
    }

public:

    static void ShowTransferScreen()
    {

        string Title = "\t\tTransfer Screen";
        _DrawScreenHeader(Title);

        ClsBankClient SourceClient = ClsBankClient::Find(_ReadAccounNumberTransferFrom());

        _PrintClientCard(SourceClient);

        ClsBankClient DestinationClient = ClsBankClient::Find(_ReadAccountNumberTransferTo());

        _PrintClientCard(DestinationClient);

        int Currency = _ReadCurrency();

        double Amount = _ReadAmount(SourceClient,Currency);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,Currency))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }

            SourceClient = ClsBankClient::Find(SourceClient.Get_AccountNumber());
            DestinationClient = ClsBankClient::Find(DestinationClient.Get_AccountNumber());
        }

        _PrintClientCard(SourceClient);
        _PrintClientCard(DestinationClient);

    }




};

