#pragma once
#include <iostream>
#include "ClsUser.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

using namespace std;

class ClsdeleteUserScreen : public ClsScreen
{
private:

    static void _PrintUser(ClsUser User)
    {
        cout << " \n" << "" << "\t   Client Card:" << endl;
        cout << " " << "" << "===================================" << endl;
        cout << " " << "" << "First Name  : " << User.FirstName << endl;
        cout << " " << "" << "Last Name   : " << User.LastName << endl;
        cout << " " << "" << "Full Name   : " << User.Get_FullName() << endl;
        cout << " " << "" << "Email       : " << User.Email << endl;
        cout << " " << "" << "Phone       : " << User.Phone << endl;
        cout << " " << "" << "User Name   : " << User.Get_UserName() << endl;
        cout << " " << "" << "Password    : " << User.Get_Password() << endl;
        cout << " " << "" << "Permission  : " << User.Get_Permissions() << endl;

    }

public:

    static void ShowDeleteUsers()
    {

        string Title = "\t\tDelete User Screen";

        _DrawScreenHeader(Title);

        cout << "\nPlease Enter UserName: ";
        string UserName = ClsInputValidate::ReadString();
        while (!ClsUser::IsUserExist(UserName))
        {
            cout << "\nUserName was not found, Enter another one: ";
            UserName = ClsInputValidate::ReadString();
        }


        ClsUser DeleteUser = ClsUser::Find(UserName);
        _PrintUser(DeleteUser);

        cout << "\nAre you sure you want to delete this User y/n?  ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (DeleteUser.Delete())
            {
                cout << "\nUser Deleted Successfully :-) ";
                _PrintUser(DeleteUser);
            }
            else
            {
                cout << "\nError User was not Deleted.";
            }

        }
        else
        {
            cout << "\nError User was not Deleted.";
        }

    }

};

