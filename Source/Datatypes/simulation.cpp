#include "mycellularautomata.h"

simulate::simulate(){};

simulate::~simulate(){};

int simulate::setup_simulation(cellular_automata &CA);



int stimulate::straight_conditional_transition_rule(int row, int column, int initial_type, int final_type, int num_steps) {
    
    if (CA.get_cell(row, column).type == initial_type && CA.get_cell(row, column).steps_passed >= num_steps) {
        
        CA.get_cell(row, column).type = final_type; // change cell to final type
        CA.get_cell(row, column).steps_passed = 0; // reset steps passed
    }

    return NO_ERROR;
}


int simulate::conditional_transition_rule_on_neighbor(int row, int column, int initial_type, int neighbor_type) {

    if (CA.get_cell(row, column).type != intial_type) {
    
        return NO_ERROR:
    
    }
   
   
   std::vector<cell> neighbors = CA.get_neighborhood(row, column); // get neighbors of cell

   for (size_t i = 0; i < neighbors.size(); i++) {
        
        if (neighbors[i].type == neighbor_type) {

            CA.get_cell(row, column).type = neighbor_type;
            CA.get_cell(row, column).steps_passed = 0;

            break;
        }

       
   }

    return NO_ERROR;

}




