#pragma once
#include <iomanip>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsUser.h"

using namespace std;

class ClsAddNweUsersScreen : protected ClsScreen
{

private:

    static void _ReadUserInfo(ClsUser& User)
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

        cout << "\nShow LogIn Register? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pLogInRegister;
        }

        cout << "\nCurrency Exchange? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += ClsUser::enPermissions::pCurrencyExchange;

        }
        return Permission;

    }

 
public:

    static void ShowAddNewUserScreen()
    {

        string Title = "\t\tAdd New User Screen";
        _DrawScreenHeader(Title);


        string UserName = "";
        cout << "\nPlease Enter UserName: ";
        UserName = ClsInputValidate::ReadString();
       while (ClsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
         
            UserName = ClsInputValidate::ReadString();

        }

        ClsUser NewUser = ClsUser::Get_AddNewUserObject(UserName);

        cout << "\n\nAdd New User Info:" << endl;
        cout << "=============================";
        _ReadUserInfo(NewUser);

        ClsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case ClsUser::enSaveResults::svSucceeded:
            cout << "\nUser Added Successfully :-)";
            _PrintUser(NewUser);
            break;
        case ClsUser::enSaveResults::svFalidEmptyOpject:
            cout << "\nError: User was not saved because it's Empty.";
            break;
        case ClsUser::enSaveResults::SaveFaileUserNameExists:
            cout << "\nError: User was not saved because it's already used.";
            break;
        }
    }




};





