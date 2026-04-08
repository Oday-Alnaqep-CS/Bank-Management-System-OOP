#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"

using namespace std;

class ClsDepositScreen : public ClsScreen
{

private:

	static void _PrintClient(ClsBankClient Client)
	{
		int s = 3;

		cout << "\n" << setw(s) << "" << "---------------------- Client Card ----------------------";
		cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
		cout << "\n" << setw(s) << "" << "First Name  : " << Client.FirstName;
		cout << "\n" << setw(s) << "" << "Last Name   : " << Client.LastName;
		cout << "\n" << setw(s) << "" << "Full Name   : " << Client.Get_FullName();
		cout << "\n" << setw(s) << "" << "Email       : " << Client.Email;
		cout << "\n" << setw(s) << "" << "Phone       : " << Client.Phone;
		cout << "\n" << setw(s) << "" << "Acc. Number : " << Client.Get_AccountNumber();
		cout << "\n" << setw(s) << "" << "Pin Code    : " << Client.PinCode;
		cout << "\n" << setw(s) << "" << "==========================================================";
		cout << "\n" << setw(s) << "" << " Currencies      |        Balance ";
		cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
		cout << "\n" << setw(s) << "" << "(SAR)            : " << Client.BalanceSAR;
		cout << "\n" << setw(s) << "" << "(USD)            : " << Client.BalanceUSD;
		cout << "\n" << setw(s) << "" << "(YRN)            : " << Client.BalanceYRN;
		cout << "\n" << setw(s) << "" << "(YRO)            : " << Client.BalanceYRO;
		cout << "\n" << setw(s) << "" << "----------------------------------------------------------";
		cout << "\n" << setw(s) << "" << "Account Balance in (YER) : " << Client.Get_AccountBalance();
		cout << "\n" << setw(s) << "" << "==========================================================\n";
	}

	static string _ReadAccountNUmber()
	{
	
		cout << "\nPlease Enter Account Number ? ";
		return ClsInputValidate::ReadString();
	}

	static double _ReadDepositAmount()
	{
		double Amount;
		cout << "\nEnter a Psitive Deposit Amount ? ";
		Amount = ClsInputValidate::ReadDoubleNumber();

		while (Amount <= 0)
		{
			cout << "\nEnter a Positive Depsit Amount ? ";
			cin >> Amount;
		}
		return Amount;
	}

	static int _ReadCurrency()
	{
		cout << "\nChoose Currency for Deposit:\n"; 
		cout << "1. YRO\n2. YRN\n3. USD\n4. SAR\n";
		cout << "Choice: ";
		
		int Currency = ClsInputValidate::ReadIntNumberBetween(1, 4, "Invalid Choice, Enter (1-4): ");
		return Currency;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t\t Deposit Screen");

		string AccountNumber = _ReadAccountNUmber();

		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] dose not found!";
			AccountNumber = _ReadAccountNUmber();
		}

		ClsBankClient Deposit = ClsBankClient::Find(AccountNumber);
		_PrintClient(Deposit);

		int C;
		double Amount = _ReadDepositAmount();
		C = _ReadCurrency();

		cout << "\nAre you sure you want peform this operation ? ";
		char Answer = 'n';
		cin >> Answer;

		
		

		if (Answer == 'y' || Answer == 'Y')
		{
			Deposit.Deposit( Amount, C);

			cout << "\nAmount Deposit Successfully. :-)\n";
			Deposit = ClsBankClient::Find(AccountNumber);			
			_PrintClient(Deposit);
			cout << "\nNew Total Balance In [YRO] = " << ClsBankClient::Get_TotalBalance();
		}
		else
		{

			cout << "\nOperation was cancelled." << endl ;
		}

	}

};

