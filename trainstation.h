#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "train.h"
#include <vector>

class TrainStation {
public:
    // Функції для роботи з поїздами
    void addTrain(const Train& train);
    void displayAllTrains() const;
    void displayRequestedTrains(const std::string& destinationStation) const;

private:
    std::vector<Train> trains;
};

#endif // TRAINSTATION_H