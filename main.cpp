#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Function to display instructions to the user
void printInstructions() {
    cout << "Dictionary. Basic functionalities:\n"
        << "1. Search for a word\n"
        << "2. Add a word\n"
        << "3. Delete a word\n"
        << "4. Edit a word\n"
        << "5. Read the dictionary from a file\n"
        << "6. Write the dictionary to a file\n"
        << "0. Exit\n";
}

int main() {
    map<string, string> dictionary;

    string word, translation, filename;
    int choice;

    ifstream inputFile;  // Declare inputFile outside the switch
    ofstream outputFile; // Declare outputFile outside the switch

    while (true) {
        printInstructions();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a word to search: ";
            cin >> word;
            if (dictionary.find(word) != dictionary.end()) {
                cout << "Translation: " << dictionary[word] << endl;
            }
            else {
                cout << "Word not found in the dictionary.\n";
            }
            break;

        case 2:
            cout << "Enter a word to add: ";
            cin >> word;
            cout << "Enter the translation: ";
            cin >> translation;
            dictionary[word] = translation;
            cout << "Word successfully added to the dictionary.\n";
            break;

        case 3:
            cout << "Enter a word to delete: ";
            cin >> word;
            if (dictionary.find(word) != dictionary.end()) {
                dictionary.erase(word);
                cout << "Word successfully deleted from the dictionary.\n";
            }
            else {
                cout << "Word not found in the dictionary.\n";
            }
            break;

        case 4:
            cout << "Enter a word to edit: ";
            cin >> word;
            if (dictionary.find(word) != dictionary.end()) {
                cout << "Enter the new translation: ";
                cin >> translation;
                dictionary[word] = translation;
                cout << "Word successfully edited.\n";
            }
            else {
                cout << "Word not found in the dictionary.\n";
            }
            break;

        case 5:
            cout << "Enter the file name to read the dictionary from: ";
            cin >> filename;
            inputFile.open(filename); // Initialize inputFile here
            if (inputFile.is_open()) {
                dictionary.clear();
                while (inputFile >> word >> translation) {
                    dictionary[word] = translation;
                }
                inputFile.close();
                cout << "Dictionary successfully read from the file.\n";
            }
            else {
                cout << "Error opening the file.\n";
            }
            break;

        case 6:
            cout << "Enter the file name to write the dictionary to: ";
            cin >> filename;
            outputFile.open(filename); // Initialize outputFile here
            if (outputFile.is_open()) {
                for (const auto& entry : dictionary) {
                    outputFile << entry.first << " " << entry.second << "\n";
                }
                outputFile.close();
                cout << "Dictionary successfully written to the file.\n";
            }
            else {
                cout << "Error opening the file.\n";
            }
            break;

        case 0:
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}