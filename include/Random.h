#pragma once

#include <random>

class Random{
    public:
        static int getRandomInt(int min, int max) {
            std::uniform_int_distribution<> randInt(min, max);

            std::mt19937 gen{std::random_device{}()};
            int randomNumber = randInt(gen);
            return randomNumber;
        }

        static double getRandomDouble(double min, double max) {
            std::uniform_real_distribution<double> randDouble(min, max);
            
            std::mt19937 gen{std::random_device{}()};
            double randomNumber = randDouble(gen);
            return randomNumber;
        }

};