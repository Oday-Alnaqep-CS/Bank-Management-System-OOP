#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsUser.h"
#include "ClsInputValidate.h"

using namespace std;

class ClsUpdateUser : public ClsScreen
{

private:
    static void _ReadUpdateUserInfo(ClsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = ClsInputValidate::ReadString();

        cout << "Enter LastName : ";
        User.LastName = ClsInputValidate::ReadString();

        cout << "Enter Email    : ";
        User.Email = ClsInputValidate::ReadString();

        cout << "Enter Phone    : ";
        User.Phone = ClsInputValidate::ReadString();

        cout << "Enter Password: ";
        User.Password = ClsInputValidate::ReadString();

        cout << "Enter Permission: ";
        User.SetPermiisions(_ReadPermissionToSet());

    }

    static void _PrintUser(ClsUser User)
    {
        cout << " \n" << "" << "\t   User Card:" << endl;
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

    static int _ReadPermissionToSet()
    {
        int Permission = 0;
        char Answer = 'n';

        cout << "\nAo you want to give full access? (y/n)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Clients? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pAddnewClients;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pDeleteClients;
        }

        cout << "\nUpdate Clients? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pFindClients;
        }

        cout << "\nTransaction? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pTransAction;
        }

        cout << "\nManage User? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pManageUser;
        }

        return Permission;

    }

public:

    static void ShowUpdateUserScreen()
    {
        string Title = "\t\tUpdate User Screen";

        _DrawScreenHeader(Title);

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = ClsInputValidate::ReadString();
        while (!ClsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, Choose another one: ";
            UserName = ClsInputValidate::ReadString();
        }

        ClsUser User = ClsUser::Find(UserName);
        _PrintUser(User);

        cout << "\n\nUpdate User Info:" << endl;
        cout << "=============================";

        _ReadUpdateUserInfo(User);

        ClsUser::enSaveResults SaveResults;
        SaveResults = User.Save();

        switch (SaveResults)
        {
        case ClsUser::enSaveResults::svSucceeded:
            cout << "\UserName Updated Successfully :-) ";
            _PrintUser(User);
            break;
        case ClsUser::enSaveResults::svFalidEmptyOpject:
            cout << "\nError: UserName was not found because it's Empty.";
            break;
        }
    }

};

