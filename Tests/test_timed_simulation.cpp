#include "mycellularautomata.h"
#include <iostream>
#include "mytimings.h"
#include <fstream>

int main(){
    
    std::ofstream file1("timedsim.csv");

    vector<int> sgrid_sizes = {5, 10, 50, 100, 500, 1000}; // square grid
    double elapsed_t;

    file1 << "size,time" << std::endl;
    for (int i = 0; i < sgrid_sizes.size(); i++) {

        


        cellular_automata CA;
        vector<string> states = {"healthy", "infected", "dead"};
        vector<double> prob = {0.9, 0.05};
        vector<cell> neighborhood;


        CA.setup_dimensions(sgrid_sizes[i],sgrid_sizes[i]);
        CA.setup_states(3, prob);
        CA.setup_boundary("periodic");
        CA.setup_fixed_boundary(20);
        CA.setup_neighborhood("Moore");

        simulate simulation;
        
        rule rule1;
        rule rule2;
        rule rule3;

        rule1.setup_straight_conditional(1,2,4);
        rule2.setup_conditional_transition(0,1);
        rule3.setup_majority(0,1,3);

        simulation.add_rule(rule1);
        simulation.add_rule(rule2);
        std::cout << "1" << std::endl;
        simulation.setup_simulation(CA, 50, 1, "test_output.csv", "test_output2.csv");
        std::cout << "2" << std::endl;

        auto tstart = WTimeChrono(); //start timing 
        simulation.run();
        auto tend = WTimeChrono(); //stop timing
        elapsed_t = WTElapsedMicro(tstart, tend);

        file1 << sgrid_sizes[i] << "," << elapsed_t << std::endl;
        
    }
    
    
    file1.close();
    
    
    

    return 0;



}