// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
// Date Created: 12/03/2023
// Last revisited: 12/15/2023
//
// Description:
//              This file contains a C++ class implementation of rules for the cellular automata
//              class. 
//              The straight conditional rule changes a cell to another state after a timestep. 
//              The conditional transition rule changes a cell to another state depending on the state of 
//              of its neighbors
//              The Majority rule changes a cell's state based on the dominant state of the majority of its
//              neighbors 
//              mycellularautomata.h Contains the C++ Class declaration
//               

#include "mycellularautomata.h"
#include "myrandom.h"


//                                          CONSTRUCTORS
// --------------------------------------------------------------------------------------------------
// default constructors
rule::rule(){};

// default destructor
rule::~rule(){};

//                                          FUNCTIONS
// --------------------------------------------------------------------------------------------------


int rule::setup_straight_conditional(int initial_type, int final_type, int num_steps)
/*  Function to define straight conditional rule (sets one cell type to another cell type) */
{
    // set parameters of cell(t) to cell(t+1)
    rule_type_ = "straight conditional";
    num_steps_ = num_steps;
    initial_type_ = initial_type;
    transition_type_ = final_type;
    return NO_ERROR;
}

int rule::setup_conditional_transition(int initial_type, int neighbor_type)
/*  Function to define conditional transition rule (sets one cell type to another cell type based on
                                                    its neighbors) */

{
    // set parameters of cell(t) to cell neighbor(t+1)
    rule_type_ = "conditional transition";
    initial_type_ = initial_type;
    transition_type_ = neighbor_type;
    return NO_ERROR;
}

int rule::setup_majority(int initial_type, int neighbor_type, int num_states)
/*  Function to define majority rule (sets one cell type to another cell type based on
                                                    majority state of its neighbors) */
{
    rule_type_ = "majority";
    num_states_ = num_states;
    initial_type_ = initial_type;
    transition_type_ = neighbor_type;
    return NO_ERROR;
}

int rule::setup_probabilistic(int initial_state, int final_type_1, int final_type_2, int num_steps, double probability){
    rule_type_ = "probabalistic";
    num_steps_ = num_steps;
    initial_type_ = initial_state;
    transition_type_ = final_type_1;
    transition_type_2_ = final_type_2;
    probability_ = probability;
    return NO_ERROR;
}

int rule::apply(cell starting_cell, std::vector<cell> neighbors){
    if(rule_type_ == "straight conditional"){
        return straight_conditional_rule(starting_cell);
    } else if(rule_type_ == "conditional transition"){
        return conditional_transition_rule(starting_cell, neighbors);
    } else if(rule_type_ == "majority") {
        return  majority_rule(starting_cell, neighbors);
    } else if(rule_type_ == "probabalistic") {
        return probability_rule(starting_cell);
    } else {
        return ERR_NO_RULE_SETUP;
    }
}

int rule::straight_conditional_rule(cell starting_cell){
    if((starting_cell.type == initial_type_) && (starting_cell.steps_passed >= num_steps_)){
        return transition_type_;
    } else {
        return starting_cell.type;
    }
}

int rule::conditional_transition_rule(cell starting_cell, std::vector<cell> neighbors){
    if(starting_cell.type == initial_type_){    
        for (size_t i = 0; i < neighbors.size(); i++){
            if(neighbors[i].type == transition_type_){
                return transition_type_;
            }
        }
    }
    return starting_cell.type;
}

int rule::majority_rule(cell starting_cell, std::vector<cell> neighbors){
    int max_count = 0;
    int max_type = 0;
    std::vector<int> type_count(num_states_, 0);

    for (size_t i = 0; i < neighbors.size(); i++) {
        if(neighbors[i].type < INT_MAX){
            type_count[neighbors[i].type] += 1;
            if(type_count[neighbors[i].type] > max_count){
                max_count = type_count[neighbors[i].type];
                max_type = neighbors[i].type;
            } else if(type_count[neighbors[i].type] == max_count) {
                max_type = starting_cell.type;
            }
        }
    }
    return max_type;
}
int rule::probability_rule(cell starting_cell){
    if((starting_cell.type == initial_type_) && (starting_cell.steps_passed >= num_steps_)){
        double random = rand_number();
        if(random < probability_){
            return transition_type_;
        } else {
            return transition_type_2_;
        }
    } else return starting_cell.type;
}
