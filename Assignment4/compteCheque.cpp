// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 4
// compteCheque.cpp

#include "compteCheque.h"
#include <iostream>
#include <string>

using namespace std;

CompteCheque::CompteCheque(double amount, double fee) : Compte(amount), frais(fee)
{
    if (solde < 0.0)
    {
        cout << "Erreur: Solde ne peut pas être moins de zero" << endl;
        solde = 0.0;
    }
    if (frais < 0.0)
    {
        cout << "Erreur: Frais ne peut pas être moins de zero" << endl;
        frais = 0.0;
    }
}

void CompteCheque::credit(double num)
{
    solde += num;
    solde -= frais;

    if (solde < 0.0)
    {
        cout << "Erreur: Pas assez d'argent pour payer le frais" << endl;
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
            cout << "Erreur: Pas assez d'argent pour payer le frais" << endl;
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
