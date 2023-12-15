#include <iostream>
#include "mycellularautomata.h"
using namespace std;

int main(){
    std::cout << "2D Cellular Automata" << std::endl;
    cellular_automata CA;
    vector<double> prob = {0.5, 0.3};

    CA.setup_dimensions(5, 4);
    CA.setup_states(3, prob);
    CA.print_CA_status();

    std::cout << std:: endl<< "1D Cellular Automata" << std::endl;
    cellular_automata CA_1D;
    CA_1D.setup_dimensions(5);
    CA_1D.setup_states(3, prob);
    CA_1D.print_CA_status();

    cout << "Tests Passed." << endl;
    return 0;
}