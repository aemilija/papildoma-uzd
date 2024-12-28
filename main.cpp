#include "header.h"

int main() {
    string inputFileName;
    string outputFileName;
    char writeChoice;

    cout << "Input file name: ";
    cin >> inputFileName;

    map<string, WordData> wordData = countWords(inputFileName);
 
    cout << "Do you want to print the word count to the terminal? (y/n) "; 
    cin >> writeChoice;

    if (writeChoice == 'y') {
        writeWordDataToTerminal(wordData);
    }
    else {
        cout << "Output file name: ";
        cin >> outputFileName;
        writeWordDataToFile(wordData, outputFileName);
    }

    cout << "Word count complete." << endl;

    return 0;

}
