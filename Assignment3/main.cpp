// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 3
// main.cpp

#include "oldstring.h"
#include <iostream>
#include <string>

using namespace std;

// Function prototypes.
bool findWord(string text, string find);
void wordStats(string word);

int main()
{
	string s;
	string words = "";

	// Reads input and parses each word separated by a space.
	while (true)
	{
		string parsed = "";
		bool charFound = false;

		getline(cin, s);

		if (s.empty())
			continue;

		for (int i = 0; i < s.length(); i++)
		{
			// Skip spaces before first word.
           		 if (!charFound && s[i] == ' ')
				continue;

			// Reduce multiple spaces to one.
            		if (i < s.length()-1 && s[i] == ' ' && s[i + 1] == ' ')
				continue;

			parsed += s[i];
            		charFound = true;
		}

		// Ensure only 1 space after word.
		if (parsed[parsed.length() - 1] != ' ')
			parsed += " ";

		//Stop reading when word "stop" is found.
		if (parsed == "stop ") // 'stop' was entered by itself on its own line.
		{
		    break;
		}
		else if (findWord(s, "stop")) // 'stop' was entered mid-sentence.
		{

		    parsed = parsed.substr(0, parsed.find("stop"));
		    words += parsed; // Add substring before 'stop' before breaking the loop.
		    break;
		}

		words += parsed;
	}

	// Remove space at end of sentence.
    	if (words[words.length() - 1] == ' ')
		words.erase(words.end()-1);

	// Convert std::string to C-style string (array of char).
	char cStringWords[words.length() + 1];
	strcpy(cStringWords, words.c_str());

	// Points to and iterates through array of char C-style string.
	char* pntCStringWords = &cStringWords[0];

	cout << endl;

	// Prints information for each word in C-style string.
	while (*pntCStringWords != NULL)
	{
		double mean = oldstring::mean(pntCStringWords);
		double deviation = oldstring::stdDev(pntCStringWords, mean);
		string word = oldstring::getWord(&pntCStringWords);

		cout << "Mean of " << word << ": " << mean << endl;
		cout << "Standard deviation: " << deviation << endl;
	}

	return 0;
}

/*
 * Searches for a word in an std::string of text.
 * Returns true if the word is found in the string
 * and false otherwise.
 */
bool findWord(string text, string find)
{
	string word = "";

    	for (const char c : text)
	{
        	word += c;

		if (word == find)
            		return true;

        	if (c == ' ')
           		word = "";
    	}
	return false;
}
