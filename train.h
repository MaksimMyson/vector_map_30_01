#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

class Train {
public:
    Train();
    Train(int number, std::string departureTime, std::string destinationStation);

    // Геттери
    int getNumber() const;
    std::string getDepartureTime() const;
    std::string getDestinationStation() const;

    // Функція для виведення інформації про поїзд
    void displayTrainInfo() const;

private:
    int number;
    std::string departureTime;
    std::string destinationStation;
};

#endif // TRAIN_H