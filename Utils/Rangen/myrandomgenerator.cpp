// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Group 14
// Date Created: 12/05/2023
// Last revisited: 12/05/2023
//         This file contains a C++ hash table class implementation.
//
// mycellularautomata.h Contains the C++ Class declaration
//         

#include <random>

double rand_number(){
    // Create a random device to seed the random number generator
    std::random_device rd;

    // Use the Mersenne Twister engine for randomness
    std::mt19937 gen(rd());

    // Create a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // Generate a random value between 0 and 1
    double randomValue = distribution(gen);

    return randomValue;
};