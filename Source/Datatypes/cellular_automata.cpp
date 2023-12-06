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
#include <iostream>


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

/*  Function to set up cellula automata structure: 
    (Defines the structure of automata, i.e the height, width, rows and columns)

    Parameters:
    hwight: int
        the height of cellular automata

    width: int
        the width of the cellular automata

    Returns:
        defined error codes.
*/
int cellular_automata::setup_dimensions(int height, int width) {

    if (cellular_matrix != nullptr) { // already setup
        std::cout << "Error 1: Cellular Automata Class Already Setup " << std::endl; 

        return ERR_ALREADY_SETUP; 
    }

    else {
        height_ = height; // set height 
        width_ = width; // set width

        cellular_matrix = new (nothrow) cell * [height_]; // setup matrix rows
        for (int i = 0; i < height_; i++) {
            cellular_matrix[i] = new (nothrow) cell[width_]; // setup matrix columns
        }

        return NO_ERROR;
    }

}

/*  Function to set up cellula automata states: 
    (Iterates thorugh cells in cellula automata, and assigns each cell within the cellular_matrix with a state based on state_probability)

    Parameters:
    states: vector<string>
        the different states in the automata

    state_probabilities: vector<double> 
        the probability of a state occuring

    Returns:
        defined error codes.
*/
int cellular_automata::setup_states(vector<string> states, vector<double> state_probabilities) {
    if (states.size() != (state_probabilities.size() - 1)){ // states not matched with probabilities
        std::cout << "Error 2: Each State Must Have A Probability " << std::endl;
        return ERR_NUM_STATES;
    }

    else if (cellular_matrix == nullptr) { // cellular grid not setup
        std::cout << "Error 3: Cellular Automata Not Setup " << std::endl; 

        return ERR_NO_SETUP; 
    }   

    else {
        num_states_ = states.size(); // set num states
        srand(time(NULL));

        setup_prob(state_probabilities);
        
        for (int i = 0; i < height_; i++) { // iterating over grid rows
            for (int j = 0; j < width_; j++) { // iterating over grid colums
                // UPDATE WITH RANDOM GENERATOR TO SET STATES
                int random_number = rand() % 100000;
                double random_prob = static_cast<double>(random_number) / 100000;
                int k = 0;
                
                while(random_prob > state_probabilities[k]) k++;
                cellular_matrix[i][j].type = states[k];
                cellular_matrix[i][j].steps_passed = 0;
            }
        }
        return NO_ERROR;
    }
}

int cellular_automata::setup_prob(vector<double> &state_probabilities){
    for(int i = 1; i < num_states_; i++){
        state_probabilities[i] += state_probabilities[i - 1];
        if(state_probabilities[i] > 1){
            std::cout << "Error 4: Sum probabilities exceeds 1." << endl;
            return ERR_INC_PROBABILITY;
        }
    }
    state_probabilities.push_back(1);
    return NO_ERROR;
}

/*  Function to print cellular automata cell status
    (Iterates through cells and prints each status)

    Parameters: (No arguments)

    Returns:
        defined error codes.
*/
int cellular_automata::print_CA_status() {

    if (cellular_matrix == nullptr) { // cellular grid not setup
        std::cout << "Error 3: Cellular Automata Class Not Setup " << std::endl; 

        return ERR_NO_SETUP; 
    }    

    else { // print out status of each cell in grid
 
        for (int i = 0; i < height_; i++) {
            for (int j = 0; j < width_; j++) {
                
                cell cellij = cellular_matrix[i][j];
                std::cout << std::endl << "Grid Row: " << i << " Grid Column: " << j 
                << " Cell Type: " << cellij.type << " Number of Steps Passed: " << cellij.steps_passed << endl;
            }
        }

        return 0; 
    }

}









