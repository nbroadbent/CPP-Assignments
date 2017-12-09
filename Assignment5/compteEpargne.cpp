// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 5
// compteEpargne.cpp

#include "compteEpargne.h"
#include <iostream>

using namespace std;

CompteEpargne::CompteEpargne(double amount, double interest) : Compte(amount), interet(interest)
{
    if (solde < 0.0)
    {
        cout << "Error: Balance cannot be less than 0. Setting to 0" << endl << endl;
        solde = 0.0;
    }
    if (interet < 0.0)
    {
        cout << "Error: Interest rate cannot be less than 0. Setting to 0" << endl << endl;
        interet = 0.0;
    }
}

double CompteEpargne::calculateInterest()
{
    return solde * (interet / 100);
}

double CompteEpargne::getInterest()
{
	return interet;
}

string CompteEpargne::getAccountType()
{
    return "savings";
}
