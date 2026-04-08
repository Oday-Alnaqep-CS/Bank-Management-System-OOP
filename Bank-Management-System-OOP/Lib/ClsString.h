#pragma once	  
#include<iostream>
#include<vector>
#include <string>
#include <cctype>
using namespace std;

class ClsString
{
private:
	string _String;
	
public:
	
	ClsString()
	{
		_String = "";
	
	}

	ClsString(string Value)
	{
		_String = Value;
	}

	void SetValue(string Value)
	{
		_String = Value;
	
	}

	string GetValue()
	{
		return _String;
	}

	__declspec (property (get = GetValue, put = SetValue)) string Value;

	static size_t Length(string S1)
	{
		return S1.length();
	}

	size_t Length()
	{
		return Length(_String);
	}

	static vector<string> SplitString(string S1, string Delim)
	{
		vector<string> vclients;
		string word;
		size_t pos = 0;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			word = S1.substr(0, pos);
			if (!word.empty()) vclients.push_back(word);
			S1.erase(0, pos + Delim.length());
		}
		if (!S1.empty()) vclients.push_back(S1);
		return vclients;
	}

	vector<string> SplitString(string Delim)
	{
		return SplitString(_String,Delim);
	}

	static string UppreFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;

	}

	void UppreFirstLetterOfEachWord()
	{
		_String =  UppreFirstLetterOfEachWord(_String);
	}

	static string LowerrFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void LowerrFirstLetterOfEachWord()
	{
		_String = LowerrFirstLetterOfEachWord(_String);
	}

	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	
	void UpperAllString()
	{
		_String =  UpperAllString(_String);
	}

	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void LowerAllString()
	{
		_String = LowerAllString(_String);
	}

	static char InvertLetterCase(char Ch1)
	{
		return (isupper(Ch1) ? tolower(Ch1) : toupper(Ch1));
	}

	void InvertLetterCase()
	{
		_String = InvertLetterCase(_String[0]);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3};

	static size_t CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{

		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;
		}

		return Counter;

	}

	static size_t CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (size_t i = 0 ; i < S1.length();i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountCapitalLetters()
	{
		 CountCapitalLetters(_String);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_String);
	} 

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (char Ch : S1)
		{
			if (MatchCase)
			{
				if (Ch == Letter) Counter++;
			}
			else
			{
				if (tolower(Ch) == tolower(Letter)) Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_String, Letter, MatchCase);
	}

	static bool IsVowels(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'o' || Ch1 == 'i' || Ch1 == 'u');
	}
    
	static short CountAllVowels(const string S1)
	{
		short Counter = 0;
		for (char Ch : S1)
			if (IsVowels(Ch)) Counter++;
		return Counter;
	}

	short CountAllVowels()
	{
		return CountAllVowels(_String);
	}

	static void PrintAllVowelsInString(const string& S1)
	{
		for (char Ch : S1)
			if (IsVowels(Ch))
				cout << Ch << " ";
		cout << endl;
	}

	void PrintAllVowelsInString()
	{
		PrintAllVowelsInString(_String);
	}

	static void PrintEachWoridInString(string S1)
	{
		string Delim = " ";
		size_t pos = 0;
		string word;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			word = S1.substr(0, pos);
			if (word != "")
			{
				cout << word << endl;
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			cout << S1 << endl;
		}
	}

	void PrintEachWoridInString()
	{
		PrintEachWoridInString(_String);
	}

	short CountEachWorldInString(string S1)
	{
		string Delim = " ";
		size_t pos = 0;
		short Counter = 0;
		string Word;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			Word = S1.substr(0, pos);
			if (Word != "")
			{
				Counter++;
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			Counter++;
		}
		return Counter;
	}

	short CountEachWorldInString()
	{
		return CountEachWorldInString(_String);
	}

	static string TrimLeft(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void  TrimLeft()
	{
		_String = TrimLeft(_String);
	}

	static string TrimRight(string S1)
	{
		if (S1.empty())
			return "";

		for (int i = (int)S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		
		}
		return "";
	}

	void TrimRight()
	{
		_String = TrimRight(_String);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}

	void Trim()
	{
		_String = Trim(_String);
	}

	static string JoinString(vector<string> vString, const string& Delim)
	{
		string S1 = "";
		for (string& S : vString)
		{
			S1 += S + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	void JoinString(vector<string> vString)
	{
		_String = JoinString(vString, " ");
	}

	static string JoinString(string arrString[], short Length, const string& Delim)
	{
		string S1 = "";
		for (int i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	string JoinString(string arrString[], short Length)
	{
		return JoinString(arrString, Length, " ");
	}

	static string ReversWordInString(string S1, string Delim)
	{
		vector<string> vString;
		string S2 = "";
		vString = SplitString(S1,Delim);
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}

	void  ReversWordInString(string Delim)
	{
		_String =  ReversWordInString(_String,Delim);
	}

	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string Replace)
	{
		size_t pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), Replace);
			pos = S1.find(StringToReplace);
		}
		return S1;
	}

	string ReplaceWordInStringUsingBuiltInFunction(string StringToReplace, string Replace)
	{
		return ReplaceWordInStringUsingBuiltInFunction(_String, StringToReplace, Replace);
	}

	static string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string Replace, bool MatchCase = false)
	{
		vector<string> vString = SplitString(S1," ");
		for (string& S : vString)
		{
			if (MatchCase)
			{
				if (S == StringToReplace) S = Replace;
			}
			else
			{
				if (LowerAllString(S) == LowerAllString(StringToReplace)) S = Replace;
			}
		}
		return JoinString(vString, " ");
	}

	string ReplaceWordInStringUsingSplit(string StringToReplace, string Replace, bool MatchCase = false)
	{
		return ReplaceWordInStringUsingSplit(_String, StringToReplace, Replace, MatchCase);
	}

	static string RemovePunctionsFromString(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}

	void RemovePunctionsFromString()
	{
		_String = RemovePunctionsFromString(_String);
	}













};