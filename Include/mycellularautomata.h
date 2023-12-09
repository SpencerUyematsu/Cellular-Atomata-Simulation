// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Group 14
// Date Created: 11/30/2021

#include <string>
#include <vector>
using namespace std;

struct cell{
    int type; // state of cell
    int steps_passed; // steps passed at current type
};

class cellular_automata{
    public:
        cellular_automata();    // default constructor
        ~cellular_automata();   // default destructor
        int setup_dimensions(int height, int width);
        int setup_states(int num_states, vector<double> state_probabilities);
        int setup_prob(vector<double> &state_probabilities);
        int print_CA_status();
        int setup_neighborhood(std::string neighborhood_law);
        std::vector<cell> get_neighborhood(int row, int column);
        cell get_cell(int row, int col);

    private:
        cell **cellular_matrix;
        int height_;
        int width_;
        int num_states_;
        std::string neighborhood_law_;
        std::vector<cell> neighborhood_;

};

#define NO_ERROR 0
#define ERR_ALREADY_SETUP -1
#define ERR_NUM_STATES -2
#define ERR_INC_PROBABILITY -3
#define ERR_NO_SETUP -4
#define NEIGHBORHOOD_INVALID_TYPE = - 5
#define ERR_NEIGHBORHOOD_NOT_SET = -6

class simulate{
    public:
        simulate();
        ~simulate();
        int setup_simulation(cellular_automata &CA);
        int step();
        int print_sim_status();
        int straight_conditional_transition_rule(int row, int column, int initial_type, int final_type, int num_steps);
        int conditional_transition_rule_on_neighbor(int row, int column, int initial_type, int neighbor_type);

    private:
        vector<cellular_automata> CA_record;
        int step_number;
};