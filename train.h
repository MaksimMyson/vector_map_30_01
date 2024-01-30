#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

class Train {
public:
    Train();
    Train(int number, std::string departureTime, std::string destinationStation);

    // �������
    int getNumber() const;
    std::string getDepartureTime() const;
    std::string getDestinationStation() const;

    // ������� ��� ��������� ���������� ��� ����
    void displayTrainInfo() const;

private:
    int number;
    std::string departureTime;
    std::string destinationStation;
};

#endif // TRAIN_H