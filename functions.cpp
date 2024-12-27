#include "header.h"

string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

map<string, int> countWords(const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open input file: " + fileName);
    }

    map<string, int> wordCounts;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;

        while (ss >> word) {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                wordCounts[cleanedWord]++;
            }
        }
    }

    inputFile.close();
    return wordCounts;
}

void writeWordCountsToFile(const map<string, int>& wordCounts, const string& fileName) {
    ofstream outputFile(fileName);

    for (const auto& entry : wordCounts) {
        if (entry.second > 1) {
            outputFile << entry.first << " " << entry.second << endl;
        }
    }

    outputFile.close();
}

void writeWordCountsToTerminal(const map<string, int>& wordCounts) {
    for (const auto& entry : wordCounts) {
        if (entry.second > 1) {
            cout << entry.first << " " << entry.second << endl;
        }
    }
}
