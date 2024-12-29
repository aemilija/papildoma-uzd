#include "header.h"

int main() {
    string inputFileName;
    string outputFileName;
    char writeChoice;

    cout << "Input file name: ";
    cin >> inputFileName;
 
    cout << "Do you want to print the word count to the terminal? (y/n) "; 
    cin >> writeChoice;

    ifstream inputFile(inputFileName);
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string text = buffer.str();
    inputFile.close();

    map<string, WordData> wordData = countWords(inputFileName);

    if (writeChoice == 'y') {
        writeWordDataToTerminal(wordData);
    }
    else {
        cout << "Output file name: ";
        cin >> outputFileName;
        writeWordDataToFile(wordData, outputFileName, text);
    }

    cout << "Word count complete." << endl;

    return 0;

}
