// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Group 14
// Date Created: 11/30/2021

#include <string>
#include <vector>
using namespace std;

class cell{
    public:

    private:
        int type;
        int steps_passed;
        std::string color;
};

class cellular_automata{
    public:
        cellular_automata();    // default constructor
        ~cellular_automata();   // default destructor
        int setup(int height, int width);
        int setup_states(int num_states, vector<string> states, vector<double> state_probabilities);
        int print_CA_status();

    private:
        cell **cellular_matrix;
        int height_;
        int width_;
        int num_states_;
};

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