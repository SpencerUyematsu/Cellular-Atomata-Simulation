
#include <mycellularautomata.h>

// prints out the type of the cells in a vector
void print_vector(std::vector<cell>& neighbors) {
    for(auto it : neighbors){
        cout << it.type << " ";
    }
    cout << endl;
}
// tests various boundary conditions and neighborhood rules for our cellular automata
int main(){
    cellular_automata CA;
    vector<double> prob = {0.5, 0.3};
    std::vector<cell> neighbors;

    // setup automata
    CA.setup_dimensions(5, 4);
    CA.setup_states(3, prob);

    // print CA grid
    CA.print_CA_status();

    // test a number of boundary conditions and neighborhood rules
    CA.setup_boundary("periodic");
    CA.setup_neighborhood("Moore");
    
    cout << "Moore's neighbors for cell at (1,1)." << endl;
    neighbors = CA.get_neighborhood(1,1);
    print_vector(neighbors);

    cout << endl;
    cout << "Moore's neighbors for cell at (0,0) with periodic boundaries." << endl;
    neighbors = CA.get_neighborhood(0,0);
    print_vector(neighbors);

    cout << endl;
    CA.setup_boundary("fixed");
    CA.setup_fixed_boundary(10);
    cout << "Moore's neighbors for cell at (3,3) with fixed boundaries." << endl;
    neighbors = CA.get_neighborhood(3,3);
    print_vector(neighbors);

    cout << endl;
    CA.setup_neighborhood("von Neumann");
    CA.setup_boundary("none");
    cout << "von Neumann neighbors for cell at (0,1) for no boundaries. It is important to note that boundary cells have the value of INT_MAX. These are ignored when applying rules." << endl;
    neighbors = CA.get_neighborhood(0,1);
    print_vector(neighbors);
    
    cout << endl;
    cout << "von Neumann neighbors for cell at (0,1) for periodic boundaries." << endl;
    neighbors = CA.get_neighborhood(4,3);
    print_vector(neighbors);


    return 0;
}