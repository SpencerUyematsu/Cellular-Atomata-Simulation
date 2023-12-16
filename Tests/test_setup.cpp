// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
// Date Created: 12/15/2023
// Last revisited: 12/15/2023
//
// Description: This file tests the setup and state assignments for
//              the 1D and 2D cellular automata.
//              
//              


#include <iostream>
#include "mycellularautomata.h"
using namespace std;

int main(){
    // setup 2D cellular automata
    std::cout << "2D Cellular Automata" << std::endl;
    cellular_automata CA;
    vector<double> prob = {0.5, 0.3};

    CA.setup_dimensions(5, 4);

    // setup state probabilities
    CA.setup_states(3, prob);
    CA.print_CA_status();

    // setup 1D cellular automata
    std::cout << std:: endl<< "1D Cellular Automata" << std::endl;
    cellular_automata CA_1D;
    CA_1D.setup_dimensions(5);

    // serup state probabilities
    CA_1D.setup_states(3, prob);
    CA_1D.print_CA_status();

    cout << "Tests Passed." << endl;
    return 0;
}