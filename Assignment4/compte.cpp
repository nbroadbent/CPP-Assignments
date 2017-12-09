// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 4
// compte.cpp

#include "compte.h"
#include <iostream>
#include <string>

using namespace std;

Compte::Compte(double num) : solde(num)
{
	if (solde < 0.0)
	{
		cout << "Erreur: Solde ne peut pas être moins de zero" << endl;
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

	cout << "« Debit amount exceeded account balance »" << endl;
	return false;

}

double Compte::getBalance()
{
	return solde;
}
