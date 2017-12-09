// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 5
// compte.cpp

#include "compte.h"
#include <iostream>

using namespace std;

Compte::Compte(double num) : solde(num)
{
    if (solde < 0.0)
    {
        cout << "Error: Balance cannot be less than 0. Setting to 0" << endl << endl;
        solde = 0.0;
    }
}

void Compte::credit(double num)
{
    solde += num;
}

bool Compte::debit(double num)
{

    if ((solde - num) >= 0.0)
    {
        solde -= num;
        return true;
    }

    cout << "Debit amount exceeded account balance" << endl;
    return false;

}

double Compte::getBalance()
{
	return solde;
}

std::string Compte::getAccountType()
{
    return "generic account";
}
