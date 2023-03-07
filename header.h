#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <ctime>
#include <cctype>

using namespace std;


string randomWord();

string initUnderscores(string);

char askForLetter(string);

void updateUnderscores(string, string&, char);

void hangmanUpdate(int, string, string);




#endif