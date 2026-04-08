#pragma once
#include <iostream>
#include <iomanip>
#include "ClsUser.h"
#include "Global.h"
#include "ClsDate.h"

using namespace std;

class ClsScreen
{

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        int s = 50;

        cout << "\n" << setw(s) << "" << "___________________________________________________" << endl;
        cout << "\n" << setw(s) << "" << Title;
        if (SubTitle != "")
        {

            cout << "\n" << setw(s) << "" << SubTitle;
        }
        cout << "\n" << setw(s) << "" << "___________________________________________________" << endl;

        
        cout << "\n" << setw(s) << "" << "User: " << CurrentUser.UserName ;
        cout << "\n" << setw(s) << "" << "Date: " << ClsDate::DateToString(ClsDate()) << endl;

    }

    static bool CheckAccessRight(ClsUser::enPermissions Permission)
    {
        int s = 50;

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\n" << setw(s) << "" << "___________________________________________________" << endl;
            cout << "\n" << setw(s) << "" << "\tAccess Deneid! Contact Your Admain" << endl;
            cout << "\n" << setw(s) << "" << "___________________________________________________" << endl;
          
            return false;
        }
        else
        {
            return true;
        }

        
    }

};

