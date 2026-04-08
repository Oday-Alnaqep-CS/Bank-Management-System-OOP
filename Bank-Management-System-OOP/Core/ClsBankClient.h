#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "ClsPerson.h"
#include "ClsString.h"
#include "ClsDate.h"

using namespace std;

class ClsBankClient : public ClsPerson
{
private:
    string _ClientsFileName = "Clients.txt";
    double _USD_TO_YRO = 538.0;
    double _SAR_TO_YRO = 141.0;
    double _YRN_TO_YRO = 3.8;

    enum enMode
    {
        EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
    };


    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    double _BalanceSAR = 0.0;
    double _BalanceUSD = 0.0;
    double _BalanceYRN = 0.0;
    double _BalanceYRO = 0.0;
    bool   _MarkedForDelete = false;

  
    static ClsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#||#")
    {
        vector<string> vClientData = ClsString::SplitString(Line, Seperator);

    
        if (vClientData.size() < 10)
        {

            return _GetEmptyClientObject();

        }

        try
        {

            return ClsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], 
                vClientData[3], vClientData[4], vClientData[5],  stod(vClientData[6]), stod(vClientData[7]),
                stod(vClientData[8]), stod(vClientData[9]));

        }
        catch (...)
        {
         
            return _GetEmptyClientObject();

        }
    }

    
    static string _ConverClientObjectToLine(ClsBankClient Client, string Seperator = "#||#")
    {
        string SClientRecord = "";
        SClientRecord += Client.FirstName + Seperator;
        SClientRecord += Client.LastName + Seperator;
        SClientRecord += Client.Email + Seperator;
        SClientRecord += Client.Phone + Seperator;
        SClientRecord += Client.Get_AccountNumber() + Seperator;
        SClientRecord += Client.GetPinCode() + Seperator;
        SClientRecord += to_string(Client.Get_BalanceSAR()) + Seperator;
        SClientRecord += to_string(Client.Get_BalanceUSD()) + Seperator;
        SClientRecord += to_string(Client.Get_BalanceYRN()) + Seperator;
        SClientRecord += to_string(Client.Get_BalanceYRO()); // áÇ äÎÒä ÇáÅÌãÇáí ÇáãÍÓæÈ

        return SClientRecord;
    }


    static vector<ClsBankClient> _LoadClientDataFromFile()
    {

        vector<ClsBankClient> vClientData;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line == "") continue; 
                ClsBankClient Client = _ConvertLineToClientObject(Line);
                vClientData.push_back(Client);

            }

            MyFile.close();

        }
        return vClientData;
    }


    static void _SaveClientDataToFile(vector<ClsBankClient>& vClient)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);
        string DattLine;

        if (MyFile.is_open())
        {
            for (ClsBankClient& C : vClient)
            {

                if (C.MarkedForDeleted() == false)
                {
                    DattLine = _ConverClientObjectToLine(C);
                    MyFile << DattLine << endl;

                }

            }

            MyFile.close();

        }
    }


    void _Update()
    {

        vector<ClsBankClient> _vClients = _LoadClientDataFromFile();

        for (ClsBankClient& C : _vClients)
        {
            if (C.Get_AccountNumber() == Get_AccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientDataToFile(_vClients);

    }


    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));

    }


    void _Delete()
    {
        vector <ClsBankClient> _vClient;

        _vClient = _LoadClientDataFromFile();

        for (ClsBankClient& C : _vClient)
        {
            if (C.Get_AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveClientDataToFile(_vClient);

        *this = _GetEmptyClientObject();

    }

    void _AddDataLineToFile(string stDataLine)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;
            MyFile.close();

        }

    }


    static ClsBankClient _GetEmptyClientObject()
    {
        return ClsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0, 0, 0, 0);
    }


    struct stTrnsferLogRecord;

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#||#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = ClsString::SplitString(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;

    }

    string _PrepareTransferLogRecord(float Amount, ClsBankClient Destination, string UserName, string Seperator = "#||#")
    {
        string TransferLogRecord = "";

        TransferLogRecord += ClsDate::GetSystemDateTimeString() + Seperator;
        TransferLogRecord += Get_AccountNumber() + Seperator;
        TransferLogRecord += Destination.Get_AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(Get_AccountBalance()) + Seperator;
        TransferLogRecord += to_string(Destination.Get_AccountBalance()) + Seperator;
        TransferLogRecord += UserName;

        return TransferLogRecord;

    }

    void _RegisterTransderLog(float Amount, ClsBankClient Destination, string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(Amount, Destination, UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }



public:

    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;

    };

    enum eCurrency
    {
        YRO = 1, YRN = 2, USD = 3, SAR = 4
    };


    ClsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
        string AccountNumber, string PinCode, double SAR, double USD,
        double YRN, double YRO) : ClsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _BalanceSAR = SAR;
        _BalanceUSD = USD;
        _BalanceYRN = YRN;
        _BalanceYRO = YRO;
    }

    bool IsEmpty()
    {
        return _Mode == enMode::EmptyMode;
    }


    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }


    string Get_AccountNumber()
    {
        return _AccountNumber;
    }


    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    
    void Set_BalanceSAR(double BalanceSAR)
    {
        _BalanceSAR = BalanceSAR;
    }
    double Get_BalanceSAR()
    {
        return _BalanceSAR;
    }
    __declspec(property(get = Get_BalanceSAR, put = Set_BalanceSAR)) double BalanceSAR;


    void Set_BalanceUSD(double BalanceUSD)
    {
        _BalanceUSD = BalanceUSD;
    }
    double Get_BalanceUSD()
    {
        return _BalanceUSD;
    }
    __declspec(property(get = Get_BalanceUSD, put = Set_BalanceUSD)) double BalanceUSD;


    void Set_BalanceYRO(double BalanceYRO)
    {
        _BalanceYRO = BalanceYRO;
    }
    double Get_BalanceYRO()
    {
        return _BalanceYRO;
    }
    __declspec(property(get = Get_BalanceYRO, put = Set_BalanceYRO)) double BalanceYRO;


    void Set_BalanceYRN(double BalanceYRN)
    {
        _BalanceYRN = BalanceYRN;
    }
    double Get_BalanceYRN()
    {
        return _BalanceYRN;
    }
    __declspec(property(get = Get_BalanceYRN, put = Set_BalanceYRN)) double BalanceYRN;


    string Get_FullName()
    {
        return FirstName + " " + LastName;
    }
   

    double Get_AccountBalance()
    {
       
        double TotalInYER = _BalanceYRO;
        TotalInYER += (_BalanceSAR * _SAR_TO_YRO);
        TotalInYER += (_BalanceUSD * _USD_TO_YRO);
        TotalInYER += (_BalanceYRN * _YRN_TO_YRO);

        return TotalInYER;
    }


    static ClsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line == "") continue;
                ClsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.Get_AccountNumber() == AccountNumber)
                {

                    MyFile.close();
                    return Client;

                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();

    }


    static ClsBankClient Find(string AccountNumber,string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line == "") continue;
                ClsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.Get_AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {

                    MyFile.close();
                    return Client;

                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();

    }


    static bool IsClientExist(string AccountNumber)
    {
        ClsBankClient Client = ClsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }


    bool Delete()
    {
        _Delete();
        return true;
    }


    enum enSaveResults
    {
        svFalidEmptyOpject = 0, svSucceeded = 1, SaveFaileAccountNumerExists = 3
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
        }
        break;

        case enMode::UpdateMode:

        {

            _Update();

            return enSaveResults::svSucceeded;


        }
        break;

        case enMode::AddNewMode:

        {

            if (ClsBankClient::IsClientExist(_AccountNumber))
            {

                return enSaveResults::SaveFaileAccountNumerExists;

            }
            else
            {

                _AddNew();

                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }

        }
        break;

        }

        return enSaveResults::svFalidEmptyOpject;
    }


    static ClsBankClient Get_AddNewClient(string AccountNumber)
    {
        return ClsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0, 0, 0, 0);
    }
    
    
    static vector<ClsBankClient> Get_ClientsList()
    {
        return _LoadClientDataFromFile();
    }


    static double Get_TotalBalance()
    {

        vector <ClsBankClient> vClients = ClsBankClient::Get_ClientsList();

        double TotalBalance = 0;

        for (ClsBankClient CLient : vClients)
        {

            TotalBalance += CLient.Get_AccountBalance();

        }

        return TotalBalance;
    }

    bool Deposit(double Amount, int Currency)
    {

        vector<ClsBankClient> _vClients = _LoadClientDataFromFile();

        for (ClsBankClient& C : _vClients)
        {
            if (C.Get_AccountNumber() == _AccountNumber)
            {

                switch (Currency)
                {

                case eCurrency::YRO: C.BalanceYRO += Amount; break;

                case eCurrency::YRN: C.BalanceYRN += Amount; break;

                case eCurrency::USD: C.BalanceUSD += Amount; break;

                case eCurrency::SAR: C.BalanceSAR += Amount; break;

                }
                C.Get_AccountBalance();

                _SaveClientDataToFile(_vClients);
                *this = C;
                return true;
            }
        }
        return false;
    }

    bool _Withdraw(double Amount, int Currency)
    {
        switch (Currency)
        {
        case eCurrency::YRO: return Amount <= _BalanceYRO;
        case eCurrency::USD: return Amount <= _BalanceUSD;
        case eCurrency::SAR: return Amount <= _BalanceSAR;
        case eCurrency::YRN: return Amount <= _BalanceYRN;
        default: return false;
        }
    }

    bool WithDraw(double Amount, int Currency)
    {
        if (!_Withdraw(Amount, Currency))
        {
            cout << "\nInsufficient balance!\n";
            return false;
        }

        vector<ClsBankClient> _vClients = _LoadClientDataFromFile();

        for (ClsBankClient& C : _vClients)
        {
            if (C.Get_AccountNumber() == _AccountNumber)
            {
                switch (Currency)
                {
                case eCurrency::YRO: C.BalanceYRO -= Amount; break;
                case eCurrency::USD: C.BalanceUSD -= Amount; break;
                case eCurrency::SAR: C.BalanceSAR -= Amount; break;
                case eCurrency::YRN: C.BalanceYRN -= Amount; break;
                }

                _SaveClientDataToFile(_vClients);
                *this = C;
                return true;
            }
        }

        return false;
    }

    bool Transfer(double Amount, ClsBankClient& DestinationClient, int Currency)
    {
        WithDraw(Amount, Currency);
        DestinationClient.Deposit(Amount, Currency);
        _RegisterTransderLog(Amount, DestinationClient, CurrentUser.UserName);
        return true;
    }

   static vector <stTrnsferLogRecord> GetTransfersLogList()
    {

        vector <stTrnsferLogRecord> vTrnsferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;

            stTrnsferLogRecord TransferLogRecord;

            while (getline(MyFile, Line))
            {
                TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
                vTrnsferLogRecord.push_back(TransferLogRecord);
            }
            MyFile.close();
        }
        return vTrnsferLogRecord;
    }
};
