// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Group 14
// Date Created: 11/30/2021

#include <string>
#include <vector>
using namespace std;

struct cell{
    std::string type;
    int steps_passed;
};

class cellular_automata{
    public:
        cellular_automata();    // default constructor
        ~cellular_automata();   // default destructor
        int setup_dimensions(int height, int width);
        int setup_states(vector<string> states, vector<double> state_probabilities);
        int setup_prob(vector<double> &state_probabilities);
        int print_CA_status();
        int setup_neighborhood(int row, int column, std::string neighborhood_law);

    private:
        cell **cellular_matrix;
        int height_;
        int width_;
        int num_states_;
        std::string neighborhood_law_;
        std::vector<cell> neighbors_;
};

#define NO_ERROR 0
#define ERR_ALREADY_SETUP -1
#define ERR_NUM_STATES -2
#define ERR_INC_PROBABILITY -3
#define ERR_NO_SETUP -4
#define NEIGHBORHOOD_INVALID_TYPE = - 5

class simulate{
    public:
        simulate();
        ~simulate();
        int setup_simulation();
        int step();
        int print_sim_status();

    private:
        vector<cellular_automata> CA_record;
        int step_number;
};