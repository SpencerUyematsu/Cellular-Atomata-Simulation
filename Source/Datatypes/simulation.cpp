#include <map>
#include <limits.h>
#include <fstream>
#include <iostream>
#include "mycellularautomata.h"

simulate::simulate(){};

simulate::~simulate(){};

int simulate::setup_simulation(cellular_automata &CA, int total_steps, int steps_per_output, std::string filename){
    CA1 = CA;
    step_number = 0;
    filename_ = filename;
    width_ = CA.get_width();
    height_ = CA.get_height();
    total_steps_ = total_steps;
    steps_per_output = steps_per_output;
    return NO_ERROR;
}

int simulate::add_rule(rule new_rule) {
    rules.push_back(new_rule);
    std::cout << "Size of rules" << rules.size() << std::endl;
    return NO_ERROR;
}

int simulate::step(){
    int new_type;
    std::vector<cell> neighbors;
    CA2 = CA1;
    for(int i = 0; i < height_; i++){
        for(int j = 0; j < width_; j++){
            neighbors = CA1.get_neighborhood(i, j);
            for(size_t k = 0; k < rules.size(); k++){
                new_type = rules[k].apply(CA1(i, j), neighbors);
                if(new_type != CA1(i, j).type){
                    CA2(i, j).type = rules[k].apply(CA1(i, j), neighbors);
                }
            }
            if(CA2(i, j).type != CA1(i, j).type){
                CA2(i, j).steps_passed = 0;
            } else CA2(i, j).steps_passed += 1;
        }
    }
    CA1 = CA2;
    step_number += 1;
    return NO_ERROR;
}

int simulate::run(){
    ofstream filestream;
    filestream.open(filename_);

    for(int i = 0; i < width_; i++){
        filestream << i << ",";
    }
    filestream << "width,height";
    filestream << std::endl;
    // Print initial state
    CA1.print_CA_status();
    for(int k = 0; k < height_; k++){
        for(int j = 0; j < width_; j++){
            filestream << CA1(k,j).type << ",";
        }
        filestream << width_ << "," << height_;
        filestream << std::endl;
    }

    for(int s = 0; s < total_steps_; s++){
        step();
        CA1.print_CA_status();
        for(int k = 0; k < height_; k++){
            for(int j = 0; j < width_; j++){
                filestream << CA1(k,j).type << ",";
            }
            filestream << width_ << "," << height_;
            filestream << std::endl;
        }
    }

    filestream.close();
    return 0;
}