#include <iostream>
#include "mycellularautomata.h"
using namespace std;

int main(){
    cellular_automata CA;
    vector<string> states = {"healthy", "infected", "dead"};
    vector<double> prob = {0.5, 0.3};
    vector<cell> neighborhood;

    CA.setup_dimensions(5, 4);
    CA.setup_states(3, prob);
    CA.setup_boundary("fixed");
    CA.setup_fixed_boundary(20);
    CA.setup_neighborhood("von Neumann");

    CA.print_CA_status();
    neighborhood = CA.get_neighborhood(4,3);
    for(auto it : neighborhood){
        cout << it.type << " ";
    }
    cout << endl;

    cellular_automata CA2;
    CA2 = CA;
    CA2.print_CA_status();
    CA2.setup_boundary("periodic");
    neighborhood = CA2.get_neighborhood(4,3);
    for(auto it : neighborhood){
        cout << it.type << " ";
    }
    cout << endl;

    cout << CA2(1,1).type << endl;

    cout << "Tests Passed." << endl;
    return 0;
}