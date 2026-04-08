#pragma once
#include <iostream>
#include <iomanip>  
#include <thread>   
#include <chrono>
#include "ClsScreen.h"
#include "ClsMainMenueScreen.h"
#include "ClsUser.h"
#include "Global.h"

using namespace std;

class ClsLoginScreen : protected ClsScreen
{

private:

    static void _ShowSplashScreen()
    {
        int s = 50;
        for (int i = 5; i > 0; i--)
        {
            system("cls");
            cout << "\n\n\n\n";
            cout << "\n" << setw(s) << "" << "==========================================\n";
            cout << "\n" << setw(s) << "" << "\t\t( " << CurrentUser.UserName << " )";
            cout << "\n" << setw(s) << "" << "\tWELCOME TO ODAY BANK SYSTEM\n";
            cout << "\n" << setw(s) << "" << "===========================================\n";
            cout << "\n" << setw(s) << "" << "          Starting the system...           \n";
            cout << "\n" << setw(s) << "" << "          System will start in: " << i << "\n";
            cout << "\n" << setw(s) << "" << "===========================================\n";


            this_thread::sleep_for(chrono::seconds(1));
        }
    }

    static bool _Login()
    {

        bool LoginFaild = false;
        string UserName, Password;
        
        short FaildLoginCount = 0;

        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;
                cout << "\nInvaild UserName/Password\n";
                cout << "You Have " << ( 3 - FaildLoginCount ) << " Trails to login\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\nYou are loced after 3 faild trail(s)!\n";
                return false;
            }

            cout << "\nEnter UserName: ";
            cin >> UserName;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = ClsUser::Find(UserName, Password);

           LoginFaild = CurrentUser.IsEmpty();

          

        } while (LoginFaild);

       // _ShowSplashScreen();
        CurrentUser.RegisterLogIn();
        ClsMainMenueScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\t  Login Screen");
        return _Login();

    }
};

