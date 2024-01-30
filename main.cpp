#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> wordFrequency; // Словник для зберігання частот слів
    string word;

    // 1. Читання вхідного тексту з файлу
    ifstream inputFile("input.txt"); // Назва файлу може бути зміненою

    if (!inputFile.is_open()) {
        cerr << "Input file not found. Creating a new one...\n";
        ofstream newInputFile("input.txt");
        newInputFile.close();

        // Повторно намагаємося відкрити файл
        inputFile.open("input.txt");
        if (!inputFile.is_open()) {
            cerr << "Error opening the input file.\n";
            return 1; // Повертаємо код помилки
        }
    }

    while (inputFile >> word) {
        // Збільшуємо частоту слова в словнику
        wordFrequency[word]++;
    }

    inputFile.close();

    // 2. Виведення інформації про всі слова
    cout << "Frequency of each word:\n";
    for (const auto& entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << " times\n";
    }

    // 3. Знаходимо та виводимо інформацію про найбільш часто вживане слово
    string mostFrequentWord;
    int maxFrequency = 0;

    for (const auto& entry : wordFrequency) {
        if (entry.second > maxFrequency) {
            mostFrequentWord = entry.first;
            maxFrequency = entry.second;
        }
    }

    cout << "\nMost frequent word: " << mostFrequentWord << " (used " << maxFrequency << " times)\n";

    // 4. Запис результату в файл
    ofstream outputFile("output.txt"); // Назва файлу може бути зміненою

    if (!outputFile.is_open()) {
        cerr << "Error opening the output file. Creating a new one...\n";
        // Спробуємо створити новий файл
        outputFile.open("output.txt");
        if (!outputFile.is_open()) {
            cerr << "Error creating the output file.\n";
            return 1; // Повертаємо код помилки
        }
    }

    for (const auto& entry : wordFrequency) {
        outputFile << entry.first << ": " << entry.second << " times\n";
    }

    outputFile.close();

    return 0;
}