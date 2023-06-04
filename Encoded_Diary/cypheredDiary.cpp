#include <iostream>
#include <fstream>

using namespace std;

fstream myDiary;

// Function to decipher the entry
string deCypher(string cyphered) {
    string deciphered;
    for (char c : cyphered) {
        int asciiValue = static_cast<int>(c);
        // Decipher the ASCII value (subtract 1)
        asciiValue -= 1;
        char decipheredChar = static_cast<char>(asciiValue);
        deciphered += decipheredChar;
    }
    return deciphered;
}

// Read the entry which calls the decipher function
void readEntries() {
    string line;
    string entry;

    while (getline(myDiary, line)) {
        // Check if the line is a marker indicating the end of an entry
        if (line == "##END##") {
            // Decipher the current entry and display it
            string decipheredEntry = deCypher(entry);
            cout << "Entry:\n" << decipheredEntry << endl;
            // Reset the entry string for the next entry
            entry = "";
        } else {
            entry += line;
        }
    }
}

// Function to cipher the entry
string Cypher(string plainText) {
    string ciphered;
    for (char c : plainText) {
        int asciiValue = static_cast<int>(c);
        // Cipher the ASCII value (add 1)
        asciiValue += 1;
        char cipheredChar = static_cast<char>(asciiValue);
        ciphered += cipheredChar;
    }
    return ciphered;
}

int main() {
    string viewEntries;
    string writeEntry;
    string newEntry;

    cout << "Welcome to your diary!\n";
    cout << "Do you want to view your previous entries? (Yes/No)" << endl;
    getline(cin, viewEntries);

    if (viewEntries == "Yes" || viewEntries == "yes") {
        myDiary.open("myDiary.txt", ios::in);
        if (myDiary.is_open()) {
            readEntries();
        }
        myDiary.close();
    }

    cout << "Do you want to write a new entry? (Yes/No)\n";
    getline(cin, writeEntry);

    if (writeEntry == "Yes" || writeEntry == "yes") {
        myDiary.open("myDiary.txt", ios::app);
        cout << "Please input your new entry now and add ##END## to the end of it:\n";
        getline(cin, newEntry);
        string cypheredEntry = Cypher(newEntry);
        myDiary << cypheredEntry << endl;
        // Add a marker to indicate the end of the entry
        myDiary << "##END##" << endl;

        myDiary.close();
    }
    cout << "Diary Updated!\n";
    return 0;
}
