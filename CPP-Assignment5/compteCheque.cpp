// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 5
// compteCheque.cpp

#include "compteCheque.h"
#include <iostream>

using namespace std;

CompteCheque::CompteCheque(double amount, double fee) : Compte(amount), frais(fee)
{
    if (solde < 0.0)
    {
        cout << "Error: Balance cannot be less than 0. Setting to 0" << endl << endl;
        solde = 0.0;
    }
    if (frais < 0.0)
    {
        cout << "Error: Transaction fee cannot be less than 0. Setting to 0" << endl << endl;
        frais = 0.0;
    }
}

CompteCheque::CompteCheque(CompteCheque &cheque)
{
	Compte(cheque.getBalance());
	frais = cheque.getFees();
}

void CompteCheque::credit(double num)
{
    solde += num;
    solde -= frais;

    if (solde < 0.0)
    {
        cout << "Error: Not enough money to pay the transaction fee" << endl;
        solde -= num;
        solde += frais;

    }
}

bool CompteCheque::debit(double num)
{
    if (Compte::debit(num))
    {
        solde -= frais;

        if (solde < 0.0)
        {
            cout << "Error: Not enough money to pay the transaction fee" << endl;
            solde += num;
            solde += frais;
			return false;
        }
		return true;
    }
    return false;
}

double CompteCheque::getFees()
{
	return frais;
}

string CompteCheque::getAccountType()
{
    return "checking";
}
