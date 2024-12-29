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

vector<string> extractURLs(const string& text) {
    vector<string> urls;
    regex urlRegex(R"(\b((https|http?://|www\.)?[a-zA-Z0-9-]+\.(com|org|net|edu|gov|mil|int|info|biz|xyz|name|io|ai|museum|travel|tech|lt|[a-zA-Z]{2})(/[^\s]*)?)\b)");
    auto wordsBegin = sregex_iterator(text.begin(), text.end(), urlRegex);
    auto wordsEnd = sregex_iterator();

    for (sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
        urls.push_back(i->str());
    }

    return urls;
}

void writeWordDataToFile(const map<string, WordData>& wordData, const string& fileName, const string& text) {
    ofstream outputFile(fileName);
    vector<string> urls = extractURLs(text);
    if (!outputFile.is_open()) {
        throw runtime_error("Failed to open output file: " + fileName);
    }

    outputFile << setw(15) << left << "Word"
               << setw(10) << "Count"
               << "Lines" << endl;
    outputFile << "-------------------------------------------------------------------------------" << std::endl;

    for (const auto& entry : wordData) {
        if (entry.second.count > 1) {
            outputFile << setw(15) << left << entry.first
                       << setw(10) << entry.second.count;

            for (const int lineNum : entry.second.lineNums) {
                outputFile << lineNum << " ";
            }
            outputFile << endl;
        }
    }

    outputFile << "-------------------------------------------------------------------------------" << endl;
    outputFile << "URLs:" << endl;

        for (const auto& url : urls) {
        outputFile << url << endl;
    }

    outputFile.close();
}

void writeWordDataToTerminal(const map<string, WordData>& wordData, const string& text) {
    vector<string> urls = extractURLs(text);

    cout << setw(15) << left << "Word"
         << setw(10) << "Count"
         << "Lines" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for (const auto& entry : wordData) {
        if (entry.second.count > 1) {
            cout << setw(15) << left << entry.first
                 << setw(10) << entry.second.count;

            for (const int lineNum : entry.second.lineNums) {
                cout << lineNum << " ";
            }
            cout << endl;
        }
    }

    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "URLs:" << endl;

    for (const auto& url : urls) {
        cout << url << endl;
    }
}
