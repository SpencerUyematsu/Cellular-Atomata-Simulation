// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
// Date Created: 12/15/2023
// Last revisited: 12/15/2023
//
// Description: This file times the simulation of the cellular automata for
//              different sized grids
//              
// 

#include "mycellularautomata.h"
#include <iostream>
#include "mytimings.h"
#include <fstream>

int main(){
    // setup filestream
    std::ofstream file1("timedsim.csv");

    vector<int> sgrid_sizes = {5, 10, 50, 100, 500, 1000}; // square grid
    double elapsed_t; // store times for each test

    // columns for csv. 
    file1 << "size,time" << std::endl;

    // setup automata and 
    for (int i = 0; i < sgrid_sizes.size(); i++) {
        // setup automata
        cellular_automata CA;
        vector<double> prob = {0.9, 0.05};
        vector<cell> neighborhood;

        CA.setup_dimensions(sgrid_sizes[i],sgrid_sizes[i]);
        CA.setup_states(3, prob);
        CA.setup_boundary("periodic");
        CA.setup_fixed_boundary(20);
        CA.setup_neighborhood("Moore");

        simulate simulation;
        
        // setup rules
        rule rule1;
        rule rule2;
        rule rule3;

        rule1.setup_straight_conditional(1,2,4);
        rule2.setup_conditional_transition(0,1);
        rule3.setup_majority(0,1,3);

        simulation.add_rule(rule1);
        simulation.add_rule(rule2);

        // setup simulation
        simulation.setup_simulation(CA, 50, 1, "test_output.csv", "test_output2.csv");

        // time simulation for 50 steps
        auto tstart = WTimeChrono(); //start timing 
        simulation.run();
        auto tend = WTimeChrono(); //stop timing
        elapsed_t = WTElapsedMicro(tstart, tend);


        // record results
        file1 << sgrid_sizes[i] << "," << elapsed_t << std::endl;
        
    }
    
    
    file1.close();
    
    
    

    return 0;



}