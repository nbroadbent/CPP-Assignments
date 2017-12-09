// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 4
// compteEpargne.cpp

#include "compteEpargne.h"
#include <iostream>
#include <string>

using namespace std;

CompteEpargne::CompteEpargne(double amount, double interest) : Compte(amount), interet(interest)
{
    if (solde < 0.0)
    {
        cout << "Erreur: Solde ne peut pas être moins de zero" << endl;
        solde = 0.0;
    }
    if (interet < 0.0)
    {
        cout << "Erreur: Taux d'intérêt ne peut pas être moins de zero" << endl;
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
