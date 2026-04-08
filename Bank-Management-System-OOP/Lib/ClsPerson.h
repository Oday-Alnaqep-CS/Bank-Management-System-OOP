#pragma once
#include<iostream>
#include<string>
using namespace std;

class ClsPerson
{

private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:


	ClsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void SteFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SteFirstName)) string FirstName;

	void SteLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SteLastName)) string LastName;

	string GetFullName()
	{
		return  _FirstName + " " + _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email : " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body : " << Body << endl;
	}

	void SendSMS(string TexMessage)
	{
		cout << "\n\nThe following SMS Sent successfully to phone : " << _Phone << endl;
		cout << TexMessage << endl;
	}

};
