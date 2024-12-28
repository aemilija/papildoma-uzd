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

map<string, WordData> countWords(const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open input file: " + fileName);
    }

    map<string, WordData> wordData;
    string line;
    int lineNum = 0;

    while (getline(inputFile, line)) {
        lineNum++;

        stringstream ss(line);
        string word;

        while (ss >> word) {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                wordData[cleanedWord].count++;
                wordData[cleanedWord].lineNums.insert(lineNum);
            }
        }
    }

    inputFile.close();
    return wordData;
}

void writeWordDataToFile(const map<string, WordData>& wordData, const string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to open output file: " + fileName);
    }

    outputFile << std::setw(15) << std::left << "Word"
               << std::setw(10) << "Count"
               << "Lines" << std::endl;
    outputFile << "-------------------------------------------------------------------------------" << std::endl;

    for (const auto& entry : wordData) {
        if (entry.second.count > 1) {
            outputFile << std::setw(15) << std::left << entry.first
                       << std::setw(10) << entry.second.count;

            for (const int lineNum : entry.second.lineNums) {
                outputFile << lineNum << " ";
            }
            outputFile << std::endl;
        }
    }

    outputFile.close();
}

void writeWordDataToTerminal(const map<string, WordData>& wordData) {
    cout << std::setw(15) << std::left << "Word"
         << std::setw(10) << "Count"
         << "Lines" << std::endl;
    cout << "-------------------------------------------------------------------------------" << std::endl;

    for (const auto& entry : wordData) {
        if (entry.second.count > 1) {
            cout << std::setw(15) << std::left << entry.first
                 << std::setw(10) << entry.second.count;

            for (const int lineNum : entry.second.lineNums) {
                cout << lineNum << " ";
            }
            cout << std::endl;
        }
    }
}
