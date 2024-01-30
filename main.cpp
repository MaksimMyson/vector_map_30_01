#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> wordFrequency; // ������� ��� ��������� ������ ���
    string word;

    // 1. ������� �������� ������ � �����
    ifstream inputFile("input.txt"); // ����� ����� ���� ���� �������

    if (!inputFile.is_open()) {
        cerr << "Input file not found. Creating a new one...\n";
        ofstream newInputFile("input.txt");
        newInputFile.close();

        // �������� ���������� ������� ����
        inputFile.open("input.txt");
        if (!inputFile.is_open()) {
            cerr << "Error opening the input file.\n";
            return 1; // ��������� ��� �������
        }
    }

    while (inputFile >> word) {
        // �������� ������� ����� � ��������
        wordFrequency[word]++;
    }

    inputFile.close();

    // 2. ��������� ���������� ��� �� �����
    cout << "Frequency of each word:\n";
    for (const auto& entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << " times\n";
    }

    // 3. ��������� �� �������� ���������� ��� ������� ����� ������� �����
    string mostFrequentWord;
    int maxFrequency = 0;

    for (const auto& entry : wordFrequency) {
        if (entry.second > maxFrequency) {
            mostFrequentWord = entry.first;
            maxFrequency = entry.second;
        }
    }

    cout << "\nMost frequent word: " << mostFrequentWord << " (used " << maxFrequency << " times)\n";

    // 4. ����� ���������� � ����
    ofstream outputFile("output.txt"); // ����� ����� ���� ���� �������

    if (!outputFile.is_open()) {
        cerr << "Error opening the output file. Creating a new one...\n";
        // �������� �������� ����� ����
        outputFile.open("output.txt");
        if (!outputFile.is_open()) {
            cerr << "Error creating the output file.\n";
            return 1; // ��������� ��� �������
        }
    }

    for (const auto& entry : wordFrequency) {
        outputFile << entry.first << ": " << entry.second << " times\n";
    }

    outputFile.close();

    return 0;
}