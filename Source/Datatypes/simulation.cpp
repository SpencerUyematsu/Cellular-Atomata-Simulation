#include <map>
#include <limits.h>
#include "mycellularautomata.h"

simulate::simulate(){};

simulate::~simulate(){};

int simulate::setup_simulation(cellular_automata &CA){}

int simulate::add_rule(rule new_rule) {
    rules.push_back(new_rule);
    return NO_ERROR;
}

int simulate::step(){
    int new_type;
    std::vector<cell> neighbors;
    CA2 = CA1;
    for(int i = 0; i < height_; i++){
        for(int j = 0; i < width_; j++){
            neighbors = CA1.get_neighborhood(i, j);
            for(size_t k = 0; k < rules.size(); k++){
                CA2(i, j).type = rules[k].apply(CA1(i, j), neighbors);
            }
            if(CA2(i, j).type != CA1(i, j).type){
                CA2(i, j).steps_passed = 0;
            }
        }
    }
    CA1 = CA2;
    return NO_ERROR;
}
