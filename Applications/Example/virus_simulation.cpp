
#include "mycellularautomata.h"

int main(){
    cellular_automata cellular_environment;
    // states healthy, infected (stage 1), infected (stage 2), infected (stage 3), dead
    vector<double> prob = {0.9, 0.03, 0.03, 0.03};

    cellular_environment.setup(50, 50, 5, prob, "Moore", "periodic");

    rule infect_1;
    rule infect_2;
    rule infect_3;
    rule get_infected;

    infect_1.setup_straight_conditional(1, 2, 2);
    infect_2.setup_probabilistic(2, 0, 3, 2, 0.9);
    //infect_2.setup_straight_conditional(2, 3, 2);
    infect_3.setup_straight_conditional(3, 4, 1);

    get_infected.setup_conditional_transition(0,1);

    simulate virus_sim;
    virus_sim.setup_simulation(cellular_environment, 50, 1, "virus_results.csv", "virus_simulation_stats.csv");
    virus_sim.add_rule(infect_1);
    virus_sim.add_rule(infect_2);
    virus_sim.add_rule(infect_3);
    virus_sim.add_rule(get_infected);

    virus_sim.run();
}