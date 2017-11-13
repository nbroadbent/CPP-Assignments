// Authors: Nicholas Broadbent (8709720) and David Goguen (8089953)
// Course: CSI2772A
// Assignment: 3
// oldstring.h

#ifndef OLDSTRING_H
#define OLDSTRING_H

#include <string>

// Using namespace oldstring to make organization easier.
namespace oldstring
{

    // Function prototypes.
    double mean(const char*);
    double stdDev(const char*, const double);
    std::string getWord(char**);

}

#endif // OLDSTRING_H
