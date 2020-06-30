#include <vector>
#include <set>
#include <map>
#include <iostream>

int main() {
    //Initialise vector with size 100
    std::vector<unsigned int> vec(100);

    //Fill Vector with "random" numbers between 0 and 100
    for(auto& i : vec) {
        i = (rand() % 100);
    }

    //Output vector elements
    std::cout << std::endl;
    std::cout << "The vector is filled with numbers: " << std::endl;
    for(auto i : vec) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    

    //Initialise empty set
    std::set<unsigned int> setto;

    //Add each number that exists within the vector into set (equal numbers dont get added again)
    for(auto i : vec) {
        setto.emplace(i);
    }

    //Output size of set (equal to amount of varying numbers)
    std::cout << "The Vector has " << setto.size() << " different numbers." << std::endl;
    std::cout << std::endl;

    
    //Output the numbers missing from the set
    std::cout << "The numbers: " <<  std::endl;
    for(int i = 1; i <= 100; ++i) {
        auto exists = setto.find(i);
        if(exists == setto.end()) {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "are not included in the container" << std::endl;
    std::cout << std::endl;
    

    //Output set elements
    std::cout << "The set is filled with numbers: " << std::endl;
    for(auto i : setto) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //Create map
    std::map<unsigned int, unsigned int> count;

    //Fill map with j as key(number) and countee as frequency of key
    for(int j = 1; j <= 100; ++j) {
        int countee = 0;
        for(auto i : vec) {
            if(i == j) {
                countee++;
            }
        }
        count.emplace(std::make_pair(j, countee));
    }

    //Output map elements
    std::cout << "Number : Frequency" << std::endl;
    for(auto i : count) {
        std::cout << i.first << " : " << i.second << std::endl;
    }
    std::cout << std::endl;
}