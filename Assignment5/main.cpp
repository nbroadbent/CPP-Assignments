// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 5
// main.cpp

#include "compteCheque.h"
#include "compteEpargne.h"
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// Function prototypes.
void cancel();
int askInitialOption();
int askKindOfAccount();
int askKindOfTransaction();
int askAmount();
int askInterest();
int askFee();

int main()
{
    vector<Compte*> comptes;

    cout << "----------My Bank----------" << endl << endl;


    while (true)
    {
        cout << "What would you like to do?" << endl;

        int response = askInitialOption();

        if (response == 1)
        
		cout << endl << "What kind of account would you like to create?" << endl;
            	response = askKindOfAccount();
		
		// still need to create account here
		if (response == 1)
		{
			// Ask initial balance.
			int amount = askAmount();

			// Ask fee.
			int fee = askFee();

			// Create chequing acount.
                	comptes.push_back(new CompteCheque(amount, fee));
		}
		else if (response == 2)
		{
			// Ask initial balance.
			int amount = askAmount();

			// Ask interest.
			int interest = askInterest();

			// Create savings account.
                	comptes.push_back(new CompteEpargne(amount, interest));
		}
		else
		{
                	cancel();
		}
        }
        else if (response == 2)
        {
            if (comptes.empty())
            {
                cout << "No accounts exist!" << endl << endl;
            }
            else
            {
		// Select an account.
                cout << endl << "Select an account to make a transacton." << endl;
                for (size_t i = 0; i < comptes.size(); i++)
                {
                    cout << i + 1 << ") " << "Account type: " << comptes.at(i)->getAccountType() << ","
                         << " Balance: " << comptes.at(i)->getBalance() << endl;
                }
                cout << comptes.size() + 1 << ") Back" << endl;
                cout << "Option: ";
		int account;
                cin >> account;

                if (0 < account && account - 1 < comptes.size())
		{
			// Select transaction type.
			cout << endl << "Account type: " << comptes.at(account - 1)->getAccountType() << ","
                         			<< " Balance: " << comptes.at(account - 1)->getBalance() << endl;
			cout << "Credit or Debit?" << endl;
			response = askKindOfTransaction();

			// Perform option.
			if (response == 1)
			{
				// Ask amount.
				response = askAmount();

				// Credit.
                        	comptes.at(account - 1)->credit(response);

				// Add interest if it's a saving's account (assuming interest is
				// calculated on current balance each time a deposit is made).
				if (comptes.at(account - 1)->getAccountType() == "savings")
				{
				    CompteEpargne* tmp = dynamic_cast<CompteEpargne*>(comptes.at(account - 1));
				    tmp->credit(tmp->calculateInterest());
				}
				cout << "Current balance: $" << comptes.at(account - 1)->getBalance() << endl << endl;
			}
			else if (response == 2)
			{
				// Ask amount.
				response = askAmount();

				// Debit.
				comptes.at(account - 1)->debit(response);
				cout << "Current balance: $" << comptes.at(account - 1)->getBalance() << endl << endl;
			}
			else
			{
                        	cancel();
			}
		}
		else
		{
                    cancel();
		}
            }
        }
	else
	{
		break;
	}
    }
    return 0;
}

void cancel()
{
	cout << "Transaction cancelled." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause... just like a real bank ;)
	cout << endl;
}

int askInitialOption()
{
	int response;

	cout << "1) Create a new account" << endl;
	cout << "2) View existing accounts" << endl;
	cout << "3) Exit" << endl;
	cout << "Option: ";
	cin >> response;

	while (response != 1 && response != 2 && response != 3)
	{
		cout << "Invalid response. What would you like to do?" << endl;
		cout << "1) Create a new account" << endl;
		cout << "2) View or modify an existing account" << endl;
		cout << "3) Exit" << endl;
		cout << "Option: ";
		cin >> response;
	}
	return response;
}

int askKindOfAccount()
{
    int response;

	cout << "1) Chequing Account" << endl;
	cout << "2) Savings Account" << endl;
	cout << "3) Cancel" << endl;
	cout << "Option: ";
	cin >> response;

	while (response != 1 && response != 2 && response != 3)
	{
		cout << "Invalid response. What kind of account would you like to create?" << endl;
		cout << "1) Chequing Account" << endl;
		cout << "2) Savings Account" << endl;
		cout << "3) Cancel" << endl;
		cout << "Option: ";
		cin >> response;
	}

	return response;
}

int askKindOfTransaction()
{
	int response;
	cout << "1) Credit" << endl;
	cout << "2) Debit" << endl;
	cout << "3) Cancel" << endl;
	cout << "Option: ";
	cin >> response;

	while (response != 1 && response != 2 && response != 3)
	{
		cout << "Invalid response. Credit or Debit?" << endl;
		cout << "1) Credit" << endl;
		cout << "2) Debit" << endl;
		cout << "3) Cancel" << endl;
		cout << "Option: ";
		cin >> response;
	}

	return response;
}

int askAmount()
{
	int amount;
    	cout << "Amount ($): ";
	cin >> amount;
	return amount;
}

int askInterest()
{
	int interest;
    	cout << "Interest (%): ";
	cin >> interest;
    	cout << endl;
	return interest;
}

int askFee()
{
	int fee;
 	cout << "Transaction fee ($): ";
	cin >> fee;
    	cout << endl;
	return fee;
}
