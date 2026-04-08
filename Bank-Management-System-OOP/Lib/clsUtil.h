#pragma once
#include <iostream>
#include <string>
#include "CLsDate.h"

using namespace std;

class ClsUtil
{
public: 
    enum enCharType
    {
        smallLetter = 1, CapitalLetter = 2 , Digit = 3, MixChar = 4, specialCharactor = 5
    };


    static void Srand()
    {
        return srand((unsigned)time(NULL));
    }

    
    static int GetRandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    
    static char GetRandomCharectors(enCharType CharType)
    {
        if (CharType == MixChar)
            CharType = (enCharType)GetRandomNumber(1,3);

        switch (CharType)
        {
        case enCharType::smallLetter:
            return char(GetRandomNumber(97, 122));
            break;

        case enCharType::CapitalLetter:
            return char(GetRandomNumber(65, 90));
            break;

        case enCharType::specialCharactor:
            return char(GetRandomNumber(33, 47));
            break;

        case enCharType::Digit:
            return char(GetRandomNumber(48, 57));
            break;

        default:
            return char(GetRandomNumber(60, 95));
            break;
        }
    }

    
    static string  GenerateWords(enCharType Chartype, short Length)
    {
        string Word;
        for (int i = 0; i < Length; i++)
        {
            Word = Word + GetRandomCharectors(Chartype);
        }
        return Word;
    }

    
    static string GenerateKey(enCharType Chartype, short Length)
    {
        string Key = "";

        Key = GenerateWords(Chartype, Length) + "_";
        Key = Key + GenerateWords(Chartype, Length) + "_";
        Key = Key + GenerateWords(Chartype, Length) + "_";
        Key = Key + GenerateWords(Chartype, Length);

        return Key;
    }

    
    static void GenerateKeys(enCharType Chartype, short Length,short NumberOfKyes)
    {
        for (int i = 1; i <= NumberOfKyes; i++)
        {
            cout << "key [" << i << "] : ";
            cout << GenerateKey(Chartype, Length) << endl;
        }
    }

    
    static void FillArrayWithRandomNumbers(int Arr[100], short ArrLength, int From, int To)
    {
        for (int i = 0; i < ArrLength; i++)
            Arr[i] = GetRandomNumber(From, To);
    }

    
    static void FillArrayWithRandomWords(string Arr[100], enCharType CharType, short ArrLength,short WordLength)
    {
        for (int i = 0; i < ArrLength; i++)
            Arr[i] = GenerateWords(CharType, WordLength);
    }

    
    static void FillArrayWithRandomKeys(string Arr[100], enCharType CharType, short ArrLength, short KeysLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Arr[i] = GenerateKey(CharType, KeysLength);
        }
    }

    
    static void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    
    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    
    static void Swap(float& A, float& B)
    {
        float Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    
    static void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    
    static void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    
    static void Swap(string& A, string& B)
    {
        string Temp = "";

        Temp = A;
        A = B;
        B = Temp;
    }

    
    static void Swap(ClsDate& A, ClsDate& B)
    {
        ClsDate::SwapDates(A, B);
    }

    
    static void ShuflleArray(int Arr[100], short ArrLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Swap(Arr[GetRandomNumber(1, ArrLength) - 1], Arr[GetRandomNumber(1, ArrLength) - 1]);
        }

    }

    
    static void ShuflleArray(string Arr[100], short ArrLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Swap(Arr[GetRandomNumber(1, ArrLength) - 1], Arr[GetRandomNumber(1, ArrLength) - 1]);
        }

    }

   
    /* static string Tabs(short Length)
    {
        string t = "";
        for (int i = 0; i < Length; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }*/

    
    static string Tabs(short Length)
    {
        return string(Length, '\t');
    }

    
    static string EncryptText(string Text, short Eencryption = 6)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char(int(Text[i]) + Eencryption);
        }
        return Text;
    }

    
    static string DeccryptText(string Text, short Decryption = 6)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char(int(Text[i]) - Decryption);
        }
        return Text;
    }

    
    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }

};


