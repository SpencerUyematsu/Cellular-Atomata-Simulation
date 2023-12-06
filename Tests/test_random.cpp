#include <iostream>

int main(){
    srand(time(NULL));
    int random_number = rand() % 100000;
    double random_prob = static_cast<double>(random_number) / 100000;
    std::cout << random_prob << std::endl;
    return 0;
}