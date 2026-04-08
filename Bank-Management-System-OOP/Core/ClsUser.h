#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClsPerson.h"
#include "ClsString.h"
#include "CLsDate.h"
#include "clsUtil.h"

using namespace std;

class ClsUser : public ClsPerson
{

private:
    enum enMode
    {
        EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
    };

    enMode _Mode;


    string _UserName;
    string _Password;
    int _Permissions;


    bool _MarkedForDelete = false;

   
    struct stLoginRegisterRecord;
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#||#")
    {
        stLoginRegisterRecord LoginRegisterRecord;


        vector <string> LoginRegisterDataLine = ClsString::SplitString(Line, Seperator);

        if (LoginRegisterDataLine.size() < 4)
            return stLoginRegisterRecord();

        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = ClsUtil::DeccryptText(LoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;

    }


    string _PrepareLogInRecord(string Seperator = "#||#")
    {
        string LoginRecord = "";
        LoginRecord += ClsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;
        LoginRecord += ClsUtil::EncryptText(Password) + Seperator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }

   
    static ClsUser _ConvertLineToUserObject(string Line, string Seperator = "#||#")
    {
        vector<string> vUserData = ClsString::SplitString(Line, Seperator);


        if (vUserData.size() < 7)
        {

            return _GetEmptyUserObject();

        }

        try
        {

            return ClsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
                vUserData[3], vUserData[4], ClsUtil::DeccryptText(vUserData[5]) , stoi(vUserData[6]));

        }
        catch (...)
        {

            return _GetEmptyUserObject();

        }
    }


    static string _ConverUserObjectToLine(ClsUser& User, string Seperator = "#||#")
    {
        string sUserRecord = "";
        sUserRecord += User.FirstName + Seperator;
        sUserRecord += User.LastName + Seperator;
        sUserRecord += User.Email + Seperator;
        sUserRecord += User.Phone + Seperator;
        sUserRecord += User.UserName + Seperator;
        sUserRecord += ClsUtil::EncryptText(User.Password) + Seperator;
        sUserRecord += to_string(User.Permissions);

        return sUserRecord;
    }


    static vector<ClsUser> _LoadUserDataFromFile()
    {

        vector<ClsUser> _vUserData;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line == "") continue;
                ClsUser Client = _ConvertLineToUserObject(Line);
                _vUserData.push_back(Client);

            }

            MyFile.close();

        }
        return _vUserData;
    }


    static void _SaveUserDataToFile(vector<ClsUser>& vClient)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);
        string DattLine;

        if (MyFile.is_open())
        {
            for (ClsUser& C : vClient)
            {

                if (C.MarkedForDelet() == false)
                {
                    DattLine = _ConverUserObjectToLine(C);
                    MyFile << DattLine << endl;

                }

            }

            MyFile.close();

        }
    }


    void _AddDataLineToFile(string stDataLine)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;
            MyFile.close();

        }

    }


    void _Update()
    {

        vector<ClsUser> _vUser = _LoadUserDataFromFile();

        for (ClsUser& C : _vUser)
        {
            if (C.Get_UserName() == Get_UserName())
            {
                C = *this;
                break;
            }
        }

        _SaveUserDataToFile(_vUser);

    }


    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));

    }


    void _Delete()
    {
        vector <ClsUser> _vUser = _LoadUserDataFromFile();

        for (ClsUser& C : _vUser)
        {
            if (C.Get_UserName() == _UserName)
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveUserDataToFile(_vUser);

        *this = _GetEmptyUserObject();

    }

    static ClsUser _GetEmptyUserObject()
    {
        return ClsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

  
public:

    enum enPermissions
    {
        All = -1, pListClients = 1, pAddnewClients = 2, pDeleteClients = 4, pUpdateClients = 8
        , pFindClients = 16, pTransAction = 32, pManageUser = 64 , pLogInRegister = 128 , pCurrencyExchange = 256
    };

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions = 0;

    };

    ClsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
        string UserName, string Password, int permissions) :
        ClsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = permissions;
    }

    bool IsEmpty()
    {
        return _Mode == enMode::EmptyMode;
    }


    bool MarkedForDelet()
    {
        return _MarkedForDelete;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string Get_UserName()
    {
        return _UserName;
    }

    _declspec( property( get = Get_UserName, put = SetUserName ) ) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string Get_Password()
    {
        return _Password;
    }

    _declspec( property( get = Get_Password, put = SetPassword ) ) string Password;

    void SetPermiisions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int Get_Permissions()
    {
        return _Permissions;
    }

    _declspec( property( get = Get_Permissions, put = SetPermiisions ) ) int Permissions;

    string Get_FullName()
    {
        return FirstName + " " + LastName;
    }

    static ClsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line.empty()) continue;
                ClsUser User = _ConvertLineToUserObject(Line);
                if (User.Get_UserName() == UserName)
                {

                    MyFile.close();
                    return User;

                }

            }

            MyFile.close();

        }

        return _GetEmptyUserObject();

    }

    static ClsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line.empty()) continue;
                ClsUser User = _ConvertLineToUserObject(Line);
                if (User.Get_UserName() == UserName && User.Get_Password() == Password)
                {

                    MyFile.close();
                    return User;

                }

            }

            MyFile.close();

        }

        return _GetEmptyUserObject();

    }

    static bool IsUserExist(string UserName)
    {
        ClsUser User = ClsUser::Find(UserName);

        return ( !User.IsEmpty() );
    }


    bool Delete()
    {
        _Delete();
        return true;
    }


    enum enSaveResults
    {
        svFalidEmptyOpject = 0, svSucceeded = 1, SaveFaileUserNameExists = 3
    };


    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:

        {

            if (IsEmpty())
            {

                return enSaveResults::svFalidEmptyOpject;

            }
            break;
        }


        case enMode::UpdateMode:

        {

            _Update();

            return enSaveResults::svSucceeded;

            break;
        }


        case enMode::AddNewMode:

        {

            if (ClsUser::IsUserExist(_UserName))
            {

                return enSaveResults::SaveFaileUserNameExists;

            }
            else
            {

                _AddNew();

                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }
            break;
        }

        }

        return enSaveResults::svFalidEmptyOpject;
    }

 
    static ClsUser Get_AddNewUserObject(string UserName)
    {
        return ClsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }


    static vector<ClsUser> Get_UsersList()
    {
        return _LoadUserDataFromFile();
    }


    bool CheckAccessPermission(enPermissions Permissions)
    {
        if (this->Permissions == enPermissions::All)

            return true;

        if (( Permissions & this->Permissions ) == Permissions)
            return true;

        else
            return false;
    }


    void RegisterLogIn()
    {

        string sDataLine = _PrepareLogInRecord();

        fstream MyFile;

        MyFile.open("LogInRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << sDataLine << endl;

            MyFile.close();

        }
    }

   static vector<stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector<stLoginRegisterRecord> vLogInRegisterRecord;

        fstream MyFile;
        MyFile.open("LogInRegister.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;

            stLoginRegisterRecord LogInRegisterRecord;


            while (getline(MyFile, Line))
            {

                LogInRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLogInRegisterRecord.push_back(LogInRegisterRecord);

            }

            MyFile.close();
        }

        return vLogInRegisterRecord;
    }


};


