#include "trainstation.h"

void TrainStation::addTrain(const Train& train) {
    trains.push_back(train);
}

void TrainStation::displayAllTrains() const {
    std::cout << "All Trains:\n";
    for (const Train& train : trains) {
        train.displayTrainInfo();
    }
}

void TrainStation::displayRequestedTrains(const std::string& destinationStation) const {
    std::cout << "Requested Trains for Station: " << destinationStation << "\n";
    for (const Train& train : trains) {
        if (train.getDestinationStation() == destinationStation) {
            train.displayTrainInfo();
        }
    }
}