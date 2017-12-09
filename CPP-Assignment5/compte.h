// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 5
// compte.h

#ifndef COMPTE_H
#define COMPTE_H

#include <string>

class Compte
{
protected:
    double solde; // declaring protected so we can access from subclasses

public:
    Compte(double num = 0.0);
    virtual void credit(double); // virtual so it can be redefined in subclasses
    virtual bool debit(double); // virtual so it can be redefined in subclasses
    virtual std::string getAccountType(); // virtual so it can be redefined in subclasses
	double getBalance(); // Getter for solde
};

#endif // COMPTE_H
