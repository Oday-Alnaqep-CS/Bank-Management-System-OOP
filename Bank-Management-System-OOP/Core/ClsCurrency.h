#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "ClsString.h"

using namespace std;

class ClsCurrency
{

private:

    enum enMode {EmptyMode = 0 , UpdateMode = 1  };

    enMode _Mode;
    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;


    static ClsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData = ClsString::SplitString(Line, Seperator);


        if (vClientData.size() < 4)
        {

            return _GetEmptyCurrencyObject();

        }

        try
        {

            return ClsCurrency(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                stof(vClientData[3]));

        }
        catch (...)
        {

            return _GetEmptyCurrencyObject();

        }
    }


    static string _ConverCurrencyObjectToLine(ClsCurrency Client, string Seperator = "#//#")
    {
        string SClientRecord = "";
        SClientRecord += Client._Country + Seperator;
        SClientRecord += Client._CurrencyCode + Seperator;
        SClientRecord += Client._CurrencyName + Seperator;
        SClientRecord += to_string(Client._Rate) + Seperator;
    

        return SClientRecord;
    }


    static vector<ClsCurrency> _LoadCurencyDataFromFile()
    {

        vector<ClsCurrency> vCurrencyData;
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line == "") continue;
                ClsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                vCurrencyData.push_back(Currency);

            }

            MyFile.close();

        }
        return vCurrencyData;
    }


    static void _SaveCurrencyDataToFile(vector<ClsCurrency>& vClient)
    {

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);
        string DattLine;

        if (MyFile.is_open())
        {
            for (ClsCurrency& C : vClient)
            {

               
                    DattLine = _ConverCurrencyObjectToLine(C);
                    MyFile << DattLine << endl;

                

            }

            MyFile.close();

        }
    }


    void _Update()
    {

        vector<ClsCurrency> _Currency = _LoadCurencyDataFromFile();

        for (ClsCurrency& C : _Currency)
        {
            if (C.CurrencyCode() == _CurrencyCode)
            {
                C = *this;
                break;
            }
        }

        _SaveCurrencyDataToFile(_Currency);

    }


    static ClsCurrency _GetEmptyCurrencyObject()
    {
        return ClsCurrency(enMode::EmptyMode, "", "", "", 0);
    }



public:

    ClsCurrency(enMode Mode, string Currency, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Currency;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    bool IsEmpty()
    {
        return _Mode == enMode::EmptyMode;
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrecyName()
    {
        return _CurrencyName;
    }

    float UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
        return _Rate;
    }

    float Rate()
    {
        return _Rate;
    }

    static  ClsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = ClsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line == "") continue;
                ClsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {

                    MyFile.close();
                    return Currency;

                }

            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();

    }

    static ClsCurrency FindByCountry(string Country)
    {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                if (Line == "") continue;
                ClsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (ClsString::UpperAllString(Currency.Country()) == Country)
                {

                    MyFile.close();
                    return Currency;

                }

            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();

    }

    static bool IsCurrencyExist(string Currency)
    {
        ClsCurrency Curr = ClsCurrency::FindByCode(Currency);
        return (!Curr.IsEmpty());
    }

    static vector<ClsCurrency> Get_Currencylist()
    {
        return _LoadCurencyDataFromFile();
    }

    float ConvertToUSD(float Amount)
    {
        return (float)( Amount / Rate() );
    }

    float ConvertToOtherCurrency(float Amount, ClsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);
        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)( Amount * Currency2.Rate() );
    }






























};

