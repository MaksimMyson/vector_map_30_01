#include "train.h"

Train::Train() : number(0), departureTime(""), destinationStation("") {}

Train::Train(int number, std::string departureTime, std::string destinationStation)
    : number(number), departureTime(departureTime), destinationStation(destinationStation) {}

int Train::getNumber() const {
    return number;
}

std::string Train::getDepartureTime() const {
    return departureTime;
}

std::string Train::getDestinationStation() const {
    return destinationStation;
}

void Train::displayTrainInfo() const {
    std::cout << "Train Number: " << number << "\nDeparture Time: " << departureTime
        << "\nDestination Station: " << destinationStation << "\n\n";
}