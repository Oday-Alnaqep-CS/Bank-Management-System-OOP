#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsUpdateClient.h"
#include "ClsInputValidate.h"
#include "ClsClientListScreen.h"
#include "ClsAddClientsScreen.h"
#include "ClsDeleteClienScreen.h"
#include "ClsFindCliendScreen.h"
#include "ClsTransactionScreen.h"
#include "ClsManageUsersScreen.h"
#include "ClsCurrencyExchangeMainScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"


using namespace std;

class ClsMainMenueScreen : protected ClsScreen
{

private:
    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8 , eCurrecyExchange = 9, eExit = 10
    };

	static short _ReadMianMenueOption()
	{

		cout << "\n" << setw(50) << "" << "Choose what do you want to do from [ 1 to 10 ] ? ";
		
       short Choice = ClsInputValidate::ReadIntNumberBetween(1, 10,"Enter Number Between [ 1 to 10 ] ? ");
		return Choice;
	}

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //cout << "\nList Client Menue Will be here...\n";
        ClsClientListScreen::ShowClientScreen();

    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdding Client Menue Will be here...\n";
        ClsAddClientsScreen::ShowAddClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Menue Will be here...\n";
        ClsDeleteClienScreen::DeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Menue Will be here...\n";
        ClsUpdateClient::ShowUpdateClientscreen();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Menue Will be here...\n";

        ClsFindCliendScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        ClsTransactionScreen::ShowTransactionMainMenue();
    }  
    
    static void _ShowManageUsersMenue()
    {
        //cout << "\nUsers Menue Will be here...\n";
        ClsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowEndScreen()
    {
        //cout << "\nEnd Screen Will be here...\n";
        CurrentUser = ClsUser::Find("", "");
      
    }

    static void _ShowLoginRegister()
    {
        //cout << "\nLogin Register Screen Will be here...\n";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrecyExchange()
    {
        //cout << "\nCurrency Exchange Scrreb Will be here...\n";
        ClsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            break;
        }

        case enMainMenueOptions::eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenue();
            break;
        }

        case enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegister();
            break;
        }

        case enMainMenueOptions::eCurrecyExchange:
        {
            system("cls");
            _ShowCurrecyExchange();
            break;

        }

        case enMainMenueOptions::eExit:
        {
            system("cls");
            _ShowEndScreen();
            break;
        }
        }
    }



public: 

	static void ShowMainMenue()
	{
        enMainMenueOptions Choice;

		do
		{
			system("cls");
			int s = 50;

			ClsScreen::_DrawScreenHeader("\t\tMain Menu Screen");
         
			cout << "\n" << setw(s) << "" << "===================================================";
			cout << "\n" << setw(s) << "" << "\t\t MAIN MENUE SCREEN";
			cout << "\n" << setw(s) << "" << "===================================================";
			cout << "\n" << setw(s) << "" << "[1] Show Client List.";
			cout << "\n" << setw(s) << "" << "[2] Add New Client.";
			cout << "\n" << setw(s) << "" << "[3] Delete Client.";
			cout << "\n" << setw(s) << "" << "[4] Update Client Info.";
			cout << "\n" << setw(s) << "" << "[5] Find Client.";
			cout << "\n" << setw(s) << "" << "[6] Transactions.";
			cout << "\n" << setw(s) << "" << "[7] Manage Users.";
			cout << "\n" << setw(s) << "" << "[8] Login Register.";
			cout << "\n" << setw(s) << "" << "[9] Currency Exchange.";
			cout << "\n" << setw(s) << "" << "[10] Logout.";
			cout << "\n" << setw(s) << "" << "===================================================";
		
            Choice = (enMainMenueOptions)_ReadMianMenueOption();

            _PerfromMainMenueOption(Choice);

		} while (Choice != enMainMenueOptions::eExit);
	}


};

