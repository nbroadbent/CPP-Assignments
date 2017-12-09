// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 4
// main.cpp

#include "compte.h"
#include "compteCheque.h"
#include "compteEpargne.h"
#include <iostream>
#include <string>

using namespace std;

// Prototypes.
template <class T> void debit(double, T*); 
template <class T> void credit(double, T*);

int main()
{
	// Compte Testing.
	cout << "Testing Compte" << endl;
	cout << "----------------------------------" << endl;

	Compte a(10);
	Compte *ptrA = &a;
	cout << "Initial Balance: " << a.getBalance() << endl;
	cout << endl;

	debit(7, ptrA);
	credit(10, ptrA);
	debit(7, ptrA);

	cout << endl;
	cout << endl;
	cout << endl;

	// CompteCheque Testing.
	cout << "Testing CompteCheque" << endl;
	cout << "----------------------------------" << endl;

    CompteCheque b(10, 3);
	CompteCheque *ptrB = &b;
	cout << "Initial Balance: " << b.getBalance() << "	Transaction Fees: " << b.getFees() << endl;
	cout << endl;

	debit(7, ptrB);
	credit(10, ptrB);
	debit(7, ptrB);

	cout << endl;
	cout << endl;
	cout << endl;

	// CompteEparge Testing.
	cout << "Testing CompteEparge" << endl;
	cout << "----------------------------------" << endl;

	CompteEpargne c(100, 3);
	CompteEpargne *ptrC = &c;
	cout << "Initial Balance: " << c.getBalance() << "	Interest: " << c.getInterest() << endl;
	cout << endl;

	debit(2, ptrC);
	credit(c.calculateInterest(), ptrC);
	debit(4, ptrC);
	
	cin.ignore();
	return 0;
}

template <class T> void credit(double num, T* ptr)
{
	ptr->credit(num);
	cout << "Balance: " << ptr->getBalance() << "	After credit of " << num << endl;
}

template <class T> void debit(double num, T* ptr)
{
	ptr->debit(num);
	cout << "Balance: " << ptr->getBalance() << "	After debit of " << num << endl;
}
