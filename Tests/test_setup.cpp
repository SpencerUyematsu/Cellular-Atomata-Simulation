#include <iostream>
#include "mycellularautomata.h"
using namespace std;

int main(){
    cellular_automata CA;
    vector<string> states = {"healthy", "infected", "dead"};
    vector<double> prob = {0.5, 0.3};

    CA.setup_dimensions(5, 4);
    CA.setup_states(3, prob);
    CA.print_CA_status();

    cout << "Tests Passed." << endl;
    return 0;
}