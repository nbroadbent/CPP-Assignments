// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 4
// compteEpargne.h

#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include "compte.h"

class CompteEpargne : public Compte
{
private:
   	 double interet;

public:
	CompteEpargne(double amount = 0.0, double interest = 0.0);
	double calculateInterest();
	double getInterest();
};

#endif // COMPTEEPARGNE_H
