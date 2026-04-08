#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsUser.h"

using namespace std;

class ClsListUsersScreen : public ClsScreen
{

private:

    static void _PrintUsersRecordLine(ClsUser User)
    {

        cout << "| " << setw(15) << left << User.Get_UserName();
        cout << "| " << setw(20) << left << User.Get_FullName();
        cout << "| " << setw(10) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(12) << left << User.Get_Password();
        cout << "| " << setw(5) << left << User.Get_Permissions();


    }


public:

    static void _ShowUsersScreen()
    {

        vector<ClsUser> vUser = ClsUser::Get_UsersList();

        string Title = "\t\tUsers Screen";
        string SubTitle = "\t\t" + to_string(vUser.size()) + "User(s)";
        _DrawScreenHeader(Title);

        cout << "\n__________________________________________________";
        cout << "__________________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(10) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(5) << "Permissions";

        cout << "\n__________________________________________________";
        cout << "__________________________________________________\n" << endl;


        if (vUser.size() == 0)
            cout << "\nNo User Avalible in the system!...";

        else

            for (ClsUser& U : vUser)
            {
                _PrintUsersRecordLine(U);
                cout << endl;
            }

        cout << "\n__________________________________________________";
        cout << "__________________________________________________\n" << endl;

    }
};

