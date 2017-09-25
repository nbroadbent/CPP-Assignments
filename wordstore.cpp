#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::getline;
using std::string;

// Prototypes.
double sdCalculations(vector<int> ascii, double mean, int num);
void display(string word, double mean, double sd);

int main()
{
	// Initialize variables.
	double mean = 0;
	double sd = 0;
	string phrase;
	string word = "";
	vector<string> v;

	// Get user input.
	getline(cin, phrase);

	// Store each word into a vector.
	for (char& c : phrase)
	{
		// Check for word.
		if (c == ' ')
		{
			if (word == "stop")
				break;

			// Push word to the vector, then reset.
			v.push_back(word);
			word = "";
			continue;
		}
		word += c;
	}

	// Display phrase back to the user.
	for (string s : v)
	{
		cout << s + " ";
	}
	cout << "\n";

	// Calculate mean and standard deviation of the ascii values of each word.
	for (string word : v)
	{
		int num = 0;
		vector<int> ascii;

		// Calculate mean of the current word.
		for (char& c : word)
		{
			mean += double(c);
			ascii.push_back(int(c));

			num++;
		}
		mean /= num;

		// Calculate standard deviation.
		sd = sdCalculations(ascii, mean, num);

		// Display results.
		display(word, mean, sd);

		// Reset variables.
		num = 0;
		mean = 0;
		sd = 0;
	}

	cin.ignore();
	return 69;
}

/// Calculates the standard deviation.
double sdCalculations(vector<int> ascii, double mean, int num)
{
	double x = 0;
	double sd = 0;
	for (int n : ascii)
	{
		x = (double)(n - mean);
		x *= x;
		sd += x;
	}
	return (sqrt(sd / (num - 1)));
}

/// Displays text.
void display(string word, double mean, double sd)
{
	cout << "Moyenne de " + word + " : " << mean << "\n";
	cout << "Ecart-type: " << sd << "\n";
}
