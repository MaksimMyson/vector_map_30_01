#include "trainstation.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    TrainStation trainStation;

    int numberOfTrains;
    cout << "Enter the number of trains: ";
    cin >> numberOfTrains;

    for (int i = 0; i < numberOfTrains; ++i) {
        int number;
        string departureTime, destinationStation;

        cout << "\nEnter details for Train " << i + 1 << ":\n";
        cout << "Train Number: ";
        cin >> number;

        cout << "Departure Time: ";
        cin >> departureTime;

        cout << "Destination Station: ";
        cin >> destinationStation;

        trainStation.addTrain(Train(number, departureTime, destinationStation));
    }

    // ��������� ���������� ��� �� �����
    cout << "\nAll Trains:\n";
    trainStation.displayAllTrains();

    // �������� ������� ��� ��������� ����������
    string requestedStation;
    cout << "\nEnter the destination station to display information: ";
    cin >> requestedStation;

    // ��������� ���������� ��� ��������� �����
    trainStation.displayRequestedTrains(requestedStation);

    return 0;
}