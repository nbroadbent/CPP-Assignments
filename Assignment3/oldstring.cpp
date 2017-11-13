// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 3
// oldstring.cpp

#include "oldstring.h"
#include <cmath>
#include <iostream>

/*
 * Calculates the mean of ASCII values in a word.
 * Takes a pointer to a char as an argument and
 * returns the mean of the ASCII values in the word
 * the pointer is pointing to as a double. Does not
 * modify the passed pointer.
 */
double oldstring::mean(const char* word)
{
    double mean = 0;
    int len = 0;

    // Add to mean until a space or the end of the word is hit.
    while (*word != ' ' && *word != NULL)
    {
        mean += *word; // Add the ASCII value to mean.
        word++;
        len++;
    }

    // Avoids division by 0 error if loop never ran.
    if (len == 0)
        return 0;

    return mean / len;
}

/*
 * Calculates the standard deviation of ASCII values
 * in a word. Takes a pointer to a char and the mean of
 * ASCII values in the word as a double as arguments.
 * Returns the standard deviation of the ASCII values
 * in the word the pointer is pointing to as a double.
 * Does not modify the passed pointer.
 */
double oldstring::stdDev(const char* word, const double mean)
{
    double sum = 0;
    double len = 0;

    // Add to deviation until a space or the end of the word is hit.
    while (*word != ' ' && *word != NULL)
    {
        sum += pow((*word - mean), 2);
        word++;
        len++;
    }

    // Avoids division by 0 error if the loop never ran or if there is only one character.
    if (len == 0 || len == 1)
        return 0;

    return sqrt(sum / (len - 1));
}

/*
 * Analyzes a C-style string and returns an std::string
 * containing the first word found at the pointer to a
 * char passed as a parameter. Modifies the passed pointer
 * directly. This function finishes by placing the pointer
 * at the beginning of the next word in the sentence if
 * there is one, and if not, leaves it at the end of the
 * C-string.
 */
std::string oldstring::getWord(char** word)
{

    std::string strWord = "";
    while (**word != ' ' && **word != NULL)
    {
        strWord += **word; // Add character to word one by one.
        ++*word;
    }

    // Not end of string; move pointer to beginning of next word.
    if (**word == ' ')
    {
        ++*word;
    }

    return strWord;

}
