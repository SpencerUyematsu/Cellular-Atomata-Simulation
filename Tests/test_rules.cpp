// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
// Date Created: 12/15/2023
// Last revisited: 12/15/2023
//
// Description: This file tests the four different rules that can be
//              applicable for the cellular automata.
// 

#include <iostream>
#include "mycellularautomata.h"
using namespace std;

int main(){
    // setup cellular automata
    cellular_automata CA;
    vector<double> prob = {0.5, 0.3};
    std::vector<cell> neighbors; // used to store the neighbors for each cell

    CA.setup_dimensions(5, 4);
    CA.setup_states(3, prob);
    CA.setup_boundary("periodic");
    CA.setup_neighborhood("Moore");
    
    // assign steps passed for some cells to something other than 1
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            CA(i,j).steps_passed = (i + j) % 5;
        }
    }

    CA.print_CA_status();

    // setup rules. One of each type is tested.
    rule sc;
    rule ct;
    rule m;
    rule p;

    sc.setup_straight_conditional(1,2,3);
    ct.setup_conditional_transition(0,1);
    m.setup_majority(0,1,3);
    p.setup_probabilistic(1,0,2,2,0.7);

    // print the state of the each cell at the next time point for each cell in the CA. 
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            neighbors = CA.get_neighborhood(i,j);

            cout << endl << "Cell: " << i << ", " << j << endl;
            cout << "Straight conditional: " << sc.apply(CA(i,j), neighbors) << endl;
            cout << "Conditional Transitional: " << ct.apply(CA(i,j), neighbors) << endl;
            cout << "Majority rule: " << m.apply(CA(i,j), neighbors) << endl;
            cout << "Probability Straight Conditional: " << p.apply(CA(i,j), neighbors)<< endl;
        }
    }
    cout << "Tests Passed." << endl;
    return 0;
}