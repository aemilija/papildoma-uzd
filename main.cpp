#include "header.h"

int main() {
    string inputFileName;
    string outputFileName;
    char writeChoice;

    cout << "Input file name: ";
    cin >> inputFileName;

    map<string, int> wordCounts = countWords(inputFileName);
 
    cout << "Do you want to print the word count to the terminal? (y/n) "; 
    cin >> writeChoice;

    if (writeChoice == 'y') {
        writeWordCountsToTerminal(wordCounts);
    }
    else {
        cout << "Output file name: ";
        cin >> outputFileName;
        writeWordCountsToFile(wordCounts, outputFileName);
    }

    cout << "Word count complete." << endl;

    return 0;

}