#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <iomanip>
#include <list>

int main() {
    clock_t start, end;
    start = clock();

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

    //Aufgabe 4.9
    //Initialize empty list
    std::list<int> l_0;

    std::copy(std::begin(vec), std::end(vec), std::back_inserter(l_0));

    //Output vector elements
    std::cout << "Vector elements:" << std::endl;
    std::copy(std::cbegin(vec) + 90, std::cend(vec), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    //Output list elements
    auto beginning = std::begin(l_0);
    for(int i = 1; i <= 90; ++i) {
        beginning++;
    }
    std::cout << "List elements:" << std::endl;
    std::copy(beginning, std::end(l_0), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    std::cout << "Runtime : " << std::fixed << time_taken << std::setprecision(5); 
    std::cout << " sec " << std::endl; 
    return 0; 
}