// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
// Date Created: 12/03/2023
// Last revisited: 12/15/2023
//
// Description:
//              This file contains a C++ class implementation for the cellular automata
//              class simulation. Simulates a cellular automata based on the initial condition of the
//              the automata. It cycles throught the automata and updates each cell based on the previous cell 
//              states
//             
//              mycellularautomata.h Contains the C++ Class declaration
//               
#include <map>
#include <limits.h>
#include <fstream>
#include <iostream>
#include "mycellularautomata.h"
#include "myrandom.h"

//                                          CONSTRUCTORS
// --------------------------------------------------------------------------------------------------
simulate::simulate(){}; // default constructor

simulate::~simulate(){}; // default destructor


//                                          FUNCTIONS
// --------------------------------------------------------------------------------------------------
int simulate::setup_simulation(cellular_automata &CA, int total_steps, int steps_per_output, std::string filename, std::string filename2)
/* Function that takes in automata class, filenames, total steps and steps per output to set up an automata simulation*/
{
    CA1 = CA;
    step_number = 0;
    filename_ = filename;
    filename_2_ = filename2;
    width_ = CA.get_width();
    height_ = CA.get_height();
    total_steps_ = total_steps;
    steps_per_output = steps_per_output;
    return NO_ERROR;
}

int simulate::add_rule(rule new_rule) 
/* This function applies user specified rules to simulation*/
{
    rules.push_back(new_rule);
    return NO_ERROR;
}

const cellular_automata& simulate::step()
/* This function runs a time step by applying the rules to the current cell state and recordeing them to CA2*/
{
    int new_type;
    std::vector<cell> neighbors;
    CA2 = CA1;

// Loop through each cell 
    for(int i = 0; i < height_; i++)
    {
        for(int j = 0; j < width_; j++){
            neighbors = CA1.get_neighborhood(i, j);

            for(size_t k = 0; k < rules.size(); k++){
                new_type = rules[k].apply(CA1(i, j), neighbors);

                if(new_type != CA1(i, j).type){
                    CA2(i, j).type = new_type;
                }
            }
            if(CA2(i, j).type != CA1(i, j).type){
                CA2(i, j).steps_passed = 0;
            } else CA2(i, j).steps_passed += 1;

        }
    }
    CA1 = CA2; // assign CA2 to CA1

    step_number += 1;
    return CA1;
}

int simulate::run()

{
    ofstream filestream;
    filestream.open(filename_);
    ofstream filestream2;
    filestream2.open(filename_2_);

    filestream << 0;
    for (int i = 1; i < width_; i++){
        filestream << "," << i;
    }
    filestream2 << "timestep,width,height";
    
   
    for (int i = 0; i < CA1.get_state_count().size(); i++) {
        filestream2 << ",count_for_type_" << i;
    }


    filestream << endl;
    filestream2 << endl;

    // Print initial state
    for(int k = 0; k < height_; k++){
        filestream << CA1(k,0).type;
        for(int j = 1; j < width_; j++){
            filestream << "," << CA1(k,j).type;
        }
        filestream << endl;
    }
    filestream2 << step_number << "," << width_ << "," << height_;
    for (int i = 0; i <  CA1.get_state_count().size(); i++) {
        filestream2 << "," << CA1.get_state_count()[i];
    }
    filestream2 << endl; 


    for(int s = 0; s < total_steps_; s++){
        step();
        for(int k = 0; k < height_; k++){
            filestream << CA1(k,0).type;
            for(int j = 1; j < width_; j++){
                filestream  << "," << CA1(k,j).type;
            }
            filestream << endl;        
        }

        filestream2 << step_number << "," << width_ << "," << height_;
        for (int i = 0; i <  CA1.get_state_count().size(); i++){
            filestream2 << "," << CA1.get_state_count()[i];
        }
        filestream2 << endl; 
    }

    filestream.close();
    filestream2.close();
    return 0;
}