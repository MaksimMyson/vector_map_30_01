#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "train.h"
#include <vector>

class TrainStation {
public:
    // ������� ��� ������ � �������
    void addTrain(const Train& train);
    void displayAllTrains() const;
    void displayRequestedTrains(const std::string& destinationStation) const;

private:
    std::vector<Train> trains;
};

#endif // TRAINSTATION_H