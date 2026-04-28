#pragma once

#include <random>

class Random{
    private:
        std::mt19937 gen{std::random_device{}()};

    public:
        int getRandomInt(int min, int max) {
            std::uniform_int_distribution<> randInt(min, max);

            int randomNumber = randInt(gen);
            return randomNumber;
        }

        double getRandomDouble(double min, double max) {
            std::uniform_real_distribution<double> randDouble(min, max);
            
            double randomNumber = randDouble(gen);
            return randomNumber;
        }

};