// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Group 14
// Date Created: 12/03/2023
// Last revisited: 12/03/2023
//         This file contains a C++ hash table class implementation.
//
// mycellularautomata.h Contains the C++ Class declaration
//               


#include "mycellularautomata.h"
#include <iostream>
#include <climits>
#include <limits.h>
#include <stdexcept>

//                                            CONSTRUCTORS
// -------------------------------------------------------------------------------------------------

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
}

void cellular_automata::operator=(const cellular_automata& other){
    height_ = other.height_;
    width_ = other.width_;
    cellular_matrix = new (nothrow) cell * [height_];

    for (int i = 0; i < height_; i++) {
        cellular_matrix[i] = new (nothrow) cell[width_]; // setup matrix columns
        for (int j = 0; j < width_; j++){
            cellular_matrix[i][j] = other.cellular_matrix[i][j];
        }
    }

    num_states_ = other.num_states_;

    neighborhood_law_ = other.neighborhood_law_;

    boundary_ = other.boundary_;
    boundary_cell_ = other.boundary_cell_;
    boundary_type = other.boundary_type;
}

//                                           SETUP METHODS
// --------------------------------------------------------------------------------------------------

int cellular_automata::setup(int height, int width, int num_states, vector<double> state_probabilities, 
                             std::string neighborhood_law, std::string boundary){
    setup_dimensions(height, width);
    setup_states(num_states, state_probabilities);
    neighborhood_law_ = neighborhood_law;
    setup_boundary(boundary);
    return NO_ERROR;
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
    (Iterates thorugh cells in cellula automata, and assigns each cell within the cellular_matrix 
    with a state based on state_probability)

    Parameters:
    states: vector<string>
        the different states in the automata

    state_probabilities: vector<double> 
        the probability of a state occuring

    Returns:
        defined error codes.
*/
int cellular_automata::setup_states(int num_states, vector<double> state_probabilities) {
    if ((num_states -1) != (state_probabilities.size())){ // states not matched with probabilities
        std::cout << "Error 2: Each State Must Have A Probability " << std::endl;
        return ERR_NUM_STATES;
    }

    else if (cellular_matrix == nullptr) { // cellular grid not setup
        std::cout << "Error 3: Cellular Automata Not Setup " << std::endl; 

        return ERR_NO_SETUP; 
    }   

    else {
        num_states_ = num_states; // set num states
        srand(time(NULL));

        setup_prob(state_probabilities);
        
        for (int i = 0; i < height_; i++) { // iterating over grid rows
            for (int j = 0; j < width_; j++) { // iterating over grid colums
                // UPDATE WITH RANDOM GENERATOR TO SET STATES
                int random_number = rand() % 100000;
                double random_prob = static_cast<double>(random_number) / 100000;
                int k = 0;

                while(random_prob > state_probabilities[k]) k++;
                cellular_matrix[i][j].type = k;
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

int cellular_automata::setup_boundary(std::string boundary){
    boundary_ = boundary;
    return NO_ERROR;
}

int cellular_automata::setup_fixed_boundary(int type){
    boundary_type = type;
    return NO_ERROR;
}

/*  Function to set up cellula automata neighborhood: 

    Parameters:
    row: int
        the row of the center cell

    column: int
        the column of the center cell

    Returns:
        defined error codes.
*/
int cellular_automata::setup_neighborhood(std::string neighborhood_law) {
    neighborhood_law_ = neighborhood_law;
    return NO_ERROR;
}

//                                             GETTER METHODS
// -------------------------------------------------------------------------------------------------------
/*
const cell ** cellular_automata::get_cellular_matrix() const { // const accessor for cellular matrix class 
    return cellular_matrix;
}
*/
std::vector<cell> cellular_automata::get_neighborhood(int row, int column) {
    std::vector<cell> neighbors;
    cell boundary_cell;
    int n_col;
    int n_row;

    if(boundary_ == "none"){
        boundary_cell.type = INT_MAX;
    } else if (boundary_ == "fixed"){
        boundary_cell.type = boundary_type;
    }

    if(neighborhood_law_ == "Moore") { // setup moore neighborhood
        for (int i = row - 1; i <= row + 1; i++) { // iterate over rows
            for (int j = column - 1; j <= column + 1; j++) { // iterate over columns
                if(boundary_ == "periodic"){
                    n_row = (i + height_) % height_;
                    n_col = (j + width_) % width_;
                } else{
                    n_col = j;
                    n_row = i;
                }

                if(n_row < 0 || n_col < 0 || n_col >= width_ ||  n_row >= height_){
                    neighbors.push_back(boundary_cell);
                } else {
                    neighbors.push_back(cellular_matrix[n_row][n_col]); // include every cell besides center
                }
            }
        }
    }

    else if (neighborhood_law_ == "von Neumann") { // set up von neuman
        cell left, right, top, bottom;
        if(boundary_ == "periodic"){
            left = cellular_matrix[row][((column - 1) + width_) % width_];
            right = cellular_matrix[row][(column + 1) % width_];
            top = cellular_matrix[(row - 1) % height_][column];
            bottom = cellular_matrix[((row + 1) + height_) % height_][column];
        } else {
            if(row == 0){
                top = boundary_cell;
            } else top = cellular_matrix[row - 1][column];
            
            if(row == height_ - 1){
                bottom = boundary_cell;
            } else bottom = cellular_matrix[row + 1][column];

            if(column == 0){
                left = boundary_cell;
            } else left = cellular_matrix[row][column - 1];
            
            if(column == width_ - 1){
                right = boundary_cell;
            } else right = cellular_matrix[row][column + 1];  
        }
        neighbors.push_back(left); // include neighbors that 
        neighbors.push_back(right); // are not diagonal
        neighbors.push_back(cellular_matrix[row][column]);
        neighbors.push_back(top);
        neighbors.push_back(bottom);        
    }

    else {
        std::cout << "WARNING: Neighborhood law not setup." << std::endl;
    }
    return neighbors;
}

std::vector<cell> cellular_automata::get_neighborhood(int column) {
    std::vector<cell> neighbors;

    if(height_ == 1){
        neighbors.push_back(cellular_matrix[0][column - 1]);
        neighbors.push_back(cellular_matrix[0][column]);
        neighbors.push_back(cellular_matrix[0][column + 1]);
    }
    return neighbors;
}

int cellular_automata::get_num_states(){
    return num_states_;
}

int cellular_automata::get_height() const {
    return height_;
}

int cellular_automata::get_width() const {
    return width_;
}

cell& cellular_automata::operator()(int row, int col){
    return cellular_matrix[row][col];
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
        std::cout << "      ";
        for(int k = 0; k < width_; k++){
            std::cout << k << "    ";
            if(k < 9){
                std::cout << " ";
            }
        }
        std::cout << std::endl;
 
        for (int i = 0; i < height_; i++) {
            if(i < 10){
                std::cout << " ";
            }
            std::cout << i << " ";
            for (int j = 0; j < width_; j++) {
                cell cellij = cellular_matrix[i][j];
                std::cout << "[" << cellij.type << "," << cellij.steps_passed << "] ";
            }
            std::cout << std::endl;
        }
        return 0; 
    }

}
