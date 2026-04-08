#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsMainMenueScreen.h"
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsDepositScreen.h"
#include "ClsWithDrawScreen.h"
#include "ClsTransferScreen.h"
#include "ClsTotalBalanceScreen.h"
#include "ClsTransferLogScreen.h"

using namespace std;

class ClsTransactionScreen : public ClsScreen
{
private:

    enum enTransactionMenueOption {enDeposit = 1 , enWithDraw = 2, enShowTotalBalance = 3, 
      enTransfer = 4, eTransferLog = 5,  MainMenue = 6 };

    static short _ReadTrasactioMenueOption()
    {

        cout << "\n" << setw(50) << "" << "Choose what do you want to do from [ 1 to 6 ] ? ";
    
        short Choice = ClsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number Between [ 1 to 6 ] ? ");
        return Choice;
    }


    static void _ShowDepositListScreen()
    {
        
        //cout << "\n" << "Depoait Screen Will be here...\n ";
        ClsDepositScreen::ShowDepositScreen();

    }


    static void _ShowWithDrawListScreen()
    {

       // cout << "\n" << "WithDraw Screen Will be here... \n ";
        ClsWithDrawScreen::ShowWithDrawScreen();

    }


    static void _ShowTotaBalanceListScreen()
    {

       // cout << "\n" << "TotaBalance Screen Will be here... \n ";
        ClsTotalBalanceScreen::ShowTotalBalance();
    }


    static void _ShowTransferScreen()
    {
         //cout << "\n" << "Transfer Screen Will be here... \n ";
        ClsTransferScreen::ShowTransferScreen();

    }


    static void _ShowTransferActionLogScreen()
    {
        ClsTransferLogScreen::ShowTransferLogScreen();

    }

    static  void _GoBackToTransactionMenueScreen()
    {
        cout << setw(37) << left << "" << "\n\n\tPress any key to go back to Transacion Menue...\n";

        system("pause>0");
        ShowTransactionMainMenue();
    }


    static void _PerfromTransactionMenueOption(enTransactionMenueOption TransactionMenueOption)
    {

        switch (TransactionMenueOption)
        {

        case enTransactionMenueOption::enDeposit:

        {

            system("cls");
            _ShowDepositListScreen();
            _GoBackToTransactionMenueScreen();
            break;

        }

        case enTransactionMenueOption::enWithDraw:

        {

            system("cls");
            _ShowWithDrawListScreen();
            _GoBackToTransactionMenueScreen();
            break;
        }

        case enTransactionMenueOption::enShowTotalBalance:

        {

            system("cls");
            _ShowTotaBalanceListScreen();
            _GoBackToTransactionMenueScreen();
            break;
        }

        case enTransactionMenueOption::enTransfer:

        {

            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenueScreen();
            break;
        }

        case enTransactionMenueOption::eTransferLog:
        {
            system("cls");
            _ShowTransferActionLogScreen();
            _GoBackToTransactionMenueScreen();
            break;
        }

        case enTransactionMenueOption::MainMenue:

        {

            system("cls");
            break;
        }
        }
    }

public:

    static void ShowTransactionMainMenue()
    {

        short Choice = 0;
        while (Choice != 6)
        {

            if (!CheckAccessRight(ClsUser::enPermissions::pTransAction))
            {
                system("pause");
                return;
            }

            system("cls");
            string Title = "\t\tTrnsaction Screen";

            _DrawScreenHeader(Title);

            int s = 50;

            cout << "\n" << setw(s) << "" << "===================================================";
            cout << "\n" << setw(s) << "" << "\t\tTransactoin Menu Screen";
            cout << "\n" << setw(s) << "" << "===================================================";
            cout << "\n" << setw(s) << "" << "[1] Deposit.";
            cout << "\n" << setw(s) << "" << "[2] WithDraw.";
            cout << "\n" << setw(s) << "" << "[3] Total Balance.";
            cout << "\n" << setw(s) << "" << "[4] Transfer.";
            cout << "\n" << setw(s) << "" << "[5] Transfer Log.";
            cout << "\n" << setw(s) << "" << "[6] Main Menue.";
            cout << "\n" << setw(s) << "" << "===================================================";

            Choice = _ReadTrasactioMenueOption();

            _PerfromTransactionMenueOption(enTransactionMenueOption(Choice));
        }
    }
};

