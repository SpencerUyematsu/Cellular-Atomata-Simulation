// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Group
// Date Created: 12/03/2023
// Last revisited: 12/03/2023
//         This file contains a C++ hash table class implementation.
//
// mycellularautomata.h Contains the C++ Class declaration
//               


#include "mycellularautomata.h"


// default constructor
cellular_automata::cellular_automata(){
    cellular_matrix = nullptr;
}




// default destructor
cellular_automata::~cellular_automata(){
    
    for (int i = 0; i < height_; i++) { // delete rows of cellular matrix
        delete[] cellular_matrix[i];
    }

    delete[] cellular_matrix; // delete cellular matrix
    cellular_matrix = nullptr;

}






// setup method
int cellular_automata::setup(int height, int width) {

    if (cellular_matrix != nullptr) { // already setup
        std::cout << "Error 1: Cellular Automata Class Already Setup " << std::endl; 

        return 1; 
    }

    else {
        height_ = height // set height 
        width_ = width; // set width

        cellular_matrix = new (nothrow) cell * [height_]; // setup matrix rows
        for (int i = 0; i < height_; i++) {
            cellular_matrix[i] = new (nothrow) cell[width_]; // setup matrix columns
        }

        return 0;
    }

}





// states setup method
int cellular_automata::setup_states(int num_states, vector<string> states, vector<double> state_probabilities) {

    
    if (states.size() != state_probabilites.size()) { // states not matched with probabilities
        std::cout << "Error 2: Each State Must Have A Probability " << std::endl;
        return 2;

    }

    else if (cellular_matrix == nullptr) { // cellular grid not setup
        std::cout << "Error 3: Cellular Automata Not Setup " << std::endl; 

        return 3; 
    }   

    else {
        num_states_ = num_states // set num states

        set_rseed(GEN_RANDOM_SEED); // set random seed                <--- need to include random library
        
        for (int i = 0; i < height_; i++) { // iterating over grid rows
            for (int j = 0; j < width_; j++) { // iterating over grid colums
                cell cellij = cellular_matrix[i][j];
                //cellstate.type = default_state;//                   <--- need to incorporate a default cell state
                for (int k = 0; k < states.size(); k++) // choosing cell state
                {
                    bool True = (rand() % 100) < state_probabilities[k] * 100 ; // returns True based on probability

                    if (True) { // sets the cell's type to state based on probability
                        cellij.type = states[k];
                    }
                }
            }
        }

        return 0;
    }

}






// print out cellular automata
int cellular_automata::print_CA_status() {

    if (cellular_matrix == nullptr) { // cellular grid not setup
        std::cout << "Error 3: Cellular Automata Class Not Setup " << std::endl; 

        return 3; 
    }    

    else { // print out status of each cell in grid
 
        for (int i = 0; i < height_; i++) {
            for (int j = 0; j < width_; j++) {
                
                cell cellij = cellular_matrix[i][j]
                std::cout << std::endl << "Grid Row: " << i << " Grid Column: " << j 
                << " Cell Type " << cellij.type << " Number of Steps Passed: " << cellij.steps_passed
                << " Cell Color: " << cellij.color << std::endl;
            }
        }

        return 0; 
    }

}









