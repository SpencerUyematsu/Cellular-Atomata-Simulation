#include "mycellularautomata.h"
#include <iostream>

int main(){
    // Setup CA
    cellular_automata CA;
    vector<double> prob = {0.9, 0.1};
    vector<cell> neighborhood;
    cellular_automata CA_new;

    CA.setup_dimensions(10, 10);
    CA.setup_states(3, prob);
    CA.setup_boundary("periodic");
    CA.setup_fixed_boundary(20);
    CA.setup_neighborhood("Moore");
    
    // define rules
    rule rule1;
    rule rule2;
    rule rule3;

    rule1.setup_straight_conditional(1,2,4);
    rule2.setup_conditional_transition(0,1);
    rule3.setup_majority(0,1,3);

    // create simulation
    simulate simulation;
    simulation.add_rule(rule1);
    simulation.add_rule(rule2);
    simulation.setup_simulation(CA, 50, 1, "test_output.csv", "test_output2.csv");

    // simulations can be run in two different ways.
    // In the first, you step through manually. This function returns the new CA state
    CA_new = simulation.step();
    CA_new.print_CA_status();

    // You can also run a series of steps.
    simulation.run();
}