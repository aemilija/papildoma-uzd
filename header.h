
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

//functions.cpp
string cleanWord(const string& word);
map<string, int> countWords(const string& fileName);
void writeWordCountsToFile(const map<string, int>& wordCounts, const string& fileName);
void writeWordCountsToTerminal(const map<string, int>& wordCounts);

#endif