// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
// Date Created: 12/03/2023
// Last revisited: 12/15/2023
//
// Description:
//              This file contains a C++ class implementation of a virus simulation example
//	            To begin, user has to set up the cellular automata by inputting the height, width, number of states, 
//              probabilities, neighborhood law and boundary. 
//	            The user then proceeds to setup the different rules between cell states. 
//	            Finally, the user sets up the simulation by inputting the CA class, names for data files 
//              and adding rules to the simulation class. 

//
// mycellularautomata.h Contains the C++ Class declaration
//     
#include "mycellularautomata.h"

int main(){
    cellular_automata cellular_environment; // set up environment
    // states healthy, infected (stage 1), infected (stage 2), infected (stage 3), dead
    vector<double> prob = {0.9, 0.03, 0.03, 0.03}; // user defined probabilites

    cellular_environment.setup(50, 50, 5, prob, "Moore", "periodic"); // CA main setup. Uses Moore neighborhood

// define rules
    rule infect_1;
    rule infect_2;
    rule infect_3;
    rule get_infected;

    infect_1.setup_straight_conditional(1, 2, 2);
    infect_2.setup_probabilistic(2, 0, 3, 2, 0.5);
    //infect_2.setup_straight_conditional(2, 3, 2);
    infect_3.setup_straight_conditional(3, 4, 1);

    get_infected.setup_conditional_transition(0,1);

    simulate virus_sim; // initialize simulation class
    virus_sim.setup_simulation(cellular_environment, 50, 1, "virus_results.csv", "virus_simulation_stats.csv");
    
    // add rules
    virus_sim.add_rule(infect_1);
    virus_sim.add_rule(infect_2);
    virus_sim.add_rule(infect_3);
    virus_sim.add_rule(get_infected);

    virus_sim.run(); // run simulation
}