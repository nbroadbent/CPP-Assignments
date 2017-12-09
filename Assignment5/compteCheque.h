// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 5
// compteCheque.h

#ifndef COMPTECHEQUE_H
#define COMPTECHEQUE_H
#include "compte.h"

class CompteCheque : public Compte
{
private:
	double frais;

public:
	CompteCheque(double amount = 0.0, double fee = 0.0);
	CompteCheque(CompteCheque &cheque);
	void credit(double);
	bool debit(double);
	std::string getAccountType();
	double getFees();
};

#endif // COMPTECHEQUE_H
