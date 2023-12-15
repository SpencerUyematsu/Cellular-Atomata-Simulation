// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Group 14
// Date Created: 11/30/2021

#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <limits.h>
#include <stdexcept>
#pragma once    // This ensures this file is included only once during
                // compilation
using namespace std;

struct cell{
    int type; // state of cell
    int steps_passed; // steps passed at current type
};

class cellular_automata{
    public:
        cellular_automata();    // default constructor
        ~cellular_automata();   // default destructor
        void operator=(const cellular_automata& other);
        cell& operator()(int row, int col);

        int setup(int height, int width, int num_states, vector<double> state_probabilities, 
                  std::string neighborhood_law, std::string boundary);
        int setup_dimensions(int height, int width);
        int setup_states(int num_states, vector<double> state_probabilities);
        int setup_prob(vector<double> &state_probabilities);
        int setup_boundary(std::string boundary);
        int setup_neighborhood(std::string neighborhood_law);
        int setup_fixed_boundary(int type);
        std::vector<int> get_state_count() const;

        
        std::vector<cell> get_neighborhood(int row, int column);
        std::vector<cell> get_neighborhood(int column);
        cell get_cell(int row, int col);
        int get_num_states();
        int get_height() const;
        int get_width() const;

        int print_CA_status();

    private:
        cell **cellular_matrix;
        int height_;
        int width_;
        int num_states_;

        std::string neighborhood_law_;

        std::string boundary_;
        int boundary_cell_;
        int boundary_type;
};

#define NO_ERROR 0
#define ERR_ALREADY_SETUP -1
#define ERR_NUM_STATES -2
#define ERR_INC_PROBABILITY -3
#define ERR_NO_SETUP -4
#define NEIGHBORHOOD_INVALID_TYPE = - 5
#define ERR_NEIGHBORHOOD_NOT_SET = -6

class rule{
    public:
        rule();
        ~rule();
        int setup_straight_conditional(int initial_type, int final_type, int num_steps);
        int setup_conditional_transition(int initial_type, int neighbor_type);
        int setup_majority(int initial_type, int neighbor_type, int num_states);
        int apply(cell starting_cell, std::vector<cell> neighbors);
        int straight_conditional_rule(cell starting_cell);
        int conditional_transition_rule(cell starting_cell, std::vector<cell> neighbors);
        int majority_rule(cell starting_cell, std::vector<cell> neighbors);
    
    private:
        std::string rule_type_;
        int initial_type_;
        int transition_type_;
        int num_steps_;
        int num_states_;
};

#define ERR_NO_RULE_SETUP -7

class simulate{
    public:
        simulate();
        ~simulate();
        int setup_simulation(cellular_automata &CA, int total_steps, int steps_per_output, std::string filename, std::string filename2);
        int step();
        int run();
        int add_rule(rule new_rule);

    private:
        cellular_automata CA1;
        cellular_automata CA2;
        int step_number;
        vector<rule> rules;
        int height_;
        int width_;
        int total_steps_;
        int steps_per_output;
        std::string filename_;
        std::string filename_2_;
};