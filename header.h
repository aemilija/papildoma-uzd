#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <stdexcept>
#include <set>
#include <iomanip>

using namespace std;

struct WordData {
    int count; 
    set<int> lineNums;        
};

//functions.cpp
string cleanWord(const string& word);
map<string, WordData> countWords(const string& fileName);
void writeWordDataToFile(const map<string, WordData>& wordData, const string& fileName);
void writeWordDataToTerminal(const map<string, WordData>& wordData);

#endif
