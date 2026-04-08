#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsUser.h"

using namespace std;

class ClsFnidUserScreen : public ClsScreen
{
private:

    static void _PrintUser(ClsUser User)
    {
      

        int s = 1;

        cout << "\n" << setw(s) << "" << "------------- User Card --------------";
        cout << "\n" << setw(s) << "" << "--------------------------------------";
        cout << "\n" << setw(s) << "" << "First Name  : " << User.FirstName;
        cout << "\n" << setw(s) << "" << "Last Name   : " << User.LastName;
        cout << "\n" << setw(s) << "" << "Full Name   : " << User.Get_FullName();
        cout << "\n" << setw(s) << "" << "Email       : " << User.Email;
        cout << "\n" << setw(s) << "" << "Phone       : " << User.Phone;
        cout << "\n" << setw(s) << "" << "User Name   : " << User.Get_UserName();
        cout << "\n" << setw(s) << "" << "Password    : " << User.Get_Password();
        cout << "\n" << setw(s) << "" << "Permission  : " << User.Get_Permissions();
        cout << "\n" << setw(s) << "" << "=======================================";
        cout << endl;
    }

public:

    static void ShowFindUserScreen()
    {

        string Title = "\t\tFind User Screen";

        _DrawScreenHeader(Title);

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = ClsInputValidate::ReadString();

        while (!ClsUser::IsUserExist(UserName))
        {
            cout << "\nError: UserName was not found, Choose another one: ";
            UserName = ClsInputValidate::ReadString();

        }

        if (ClsUser::IsUserExist(UserName))
        {
            ClsUser User = ClsUser::Find(UserName);
            _PrintUser(User);

            cout << "\nFind User Successfully :-)";
        }
   
    }

};

