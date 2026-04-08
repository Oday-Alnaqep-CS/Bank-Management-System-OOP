#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsListUsersScreen.h"
#include "ClsAddNweUsersScreen.h"
#include "ClsdeleteUserScreen.h"
#include "ClsFnidUserScreen.h"
#include "ClsUpdateUserScreens.h"
using namespace std;

class ClsManageUsersScreen : protected ClsScreen 
{
private:
    enum enManageUsersMenueOption
    {
        eListUsers = 1, eAddNewUser = 2, eDeleteUsre = 3, eUpdateUser = 4
        , eFindUsre = 5, eMainMenue = 6
    };


    static short ReadManageUserMenueOption()
    {
        cout << "\n" << setw(50) << "" << "Choose what do you whant to do from [ 1 to 6 ]...? ";
        short Choice = ClsInputValidate::ReadShortNumberBetween(1, 6,"Enter NUmber Between [ 1 - 6 ]");
        return Choice;
    }

   static  void _GoBackToManageUsereMenue()
   {
       cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Menue...\n";

       system("pause>0");
      
   }

   static void _ShowAllUsersScreen()
   {
      // cout << "\nList Users Menue Will be here...\n";
       ClsListUsersScreen::_ShowUsersScreen();
   }

   static void _ShowAddNewUsersScreen()
   {
      // cout << "\nAdding User Menue Will be here...\n";
       ClsAddNweUsersScreen::ShowAddNewUserScreen();
   }

   static void _ShowDeleteUsersScreen()
   {
       //cout << "\nDelete User Menue Will be here...\n";
       ClsdeleteUserScreen::ShowDeleteUsers();
      
   }

   static void _ShowUpdateUsersScreen()
   {
     //  cout << "\nUpdate User Menue Will be here...\n";
       ClsUpdateUser::ShowUpdateUserScreen();
   }

   static void _ShowFindUsersScreen()
   {
      // cout << "\nFind User Menue Will be here...\n";
       ClsFnidUserScreen::ShowFindUserScreen();

   }

    
   static void _performmanageusersmenueoption( enManageUsersMenueOption  ManageUsersMenueOption)
   {
       switch (ManageUsersMenueOption)
       {
       case enManageUsersMenueOption::eListUsers:

       {
           system("cls");
           _ShowAllUsersScreen();
           _GoBackToManageUsereMenue();
           break;

       }

       case enManageUsersMenueOption::eAddNewUser:

       {
           system("cls");
           _ShowAddNewUsersScreen();
           _GoBackToManageUsereMenue();
           break;

       }

       case enManageUsersMenueOption::eDeleteUsre:

       {

           system("cls");
           _ShowDeleteUsersScreen();
           _GoBackToManageUsereMenue();
           break;

       }

       case enManageUsersMenueOption::eUpdateUser:

       {

           system("cls");
           _ShowUpdateUsersScreen();
           _GoBackToManageUsereMenue();
           break;

       }

       case enManageUsersMenueOption::eFindUsre:

       {

           system("cls");
           _ShowFindUsersScreen();
           _GoBackToManageUsereMenue();
           break;

       }

       case enManageUsersMenueOption::eMainMenue:

       {

       }
           
       }
   }


public:

    static void ShowManageUsersMenue()
    {

        if (!CheckAccessRight(ClsUser::enPermissions::pManageUser))
        {
            cout << "\n\tPress any key to go back to Main Menu...";
            system("pause>0");
            return;
        }


        short Choice = 0;

        while (Choice != 6)
        {

            system("cls");
            _DrawScreenHeader("\t\tManage Users Screen");

            int s = 50;
            cout << "\n" << setw(s) << left << "" << "===================================================";
            cout << "\n" << setw(s) << left << "" << "\t\tManage Users Screen";
            cout << "\n" << setw(s) << left << "" << "===================================================";
            cout << "\n" << setw(s) << left << "" << "\t[1] List Users.";
            cout << "\n" << setw(s) << left << "" << "\t[2] Add New User.";
            cout << "\n" << setw(s) << left << "" << "\t[3] Delete User.";
            cout << "\n" << setw(s) << left << "" << "\t[4] Update User.";
            cout << "\n" << setw(s) << left << "" << "\t[5] Find user.";
            cout << "\n" << setw(s) << left << "" << "\t[6] Main Menue.";
            cout << "\n" << setw(s) << left << "" << "===================================================";

            Choice = ReadManageUserMenueOption();

            
            _performmanageusersmenueoption(enManageUsersMenueOption(Choice));
   
        }
    }


};

