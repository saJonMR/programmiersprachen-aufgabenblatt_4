#include <cstdlib>    // std::rand ()
#include <vector>     // std::vector<>
#include <list>       // std::list<>
#include <iostream>   // std::cout
#include <iterator>   // std::ostream_iterator <>
#include <algorithm>  // std::reverse, std::generate
 
int main () {
    //Initialize vector with size 10
    std::vector<int> v_0(10); 
    //Fill vector with "random" numbers
    for (auto& v : v_0) {
        v = std::rand();
    }

    //Displays the vector v_0
    /*  std::ostream_iterator<int> is an iterator which writes to the ostream by inserting each element into cout  */
    std::copy(std::cbegin(v_0), std::cend(v_0), std::ostream_iterator<int>(std::cout, "\n"));
    std::cout << "------------" << std::endl;

    //Initialize l_0 with values of v_0
    std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
    //Initialize l_1 with values of l_0
    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0)); 

    //Reverse l_1 and write to ostream
    std::reverse(std::begin(l_1), std::end(l_1)); std::copy(std::cbegin(l_1), std::cend(l_1), std::ostream_iterator<int>(std::cout, "\n"));
    std::cout << "------------" << std::endl;

    //Sort l_1 in ascending oder (default)
    l_1.sort();
    //Display l_1
    std::copy(l_1.cbegin(), l_1.cend(), std::ostream_iterator<int>(std::cout, "\n"));
    std::cout << "------------" << std::endl;

    //Iterates over the entire v_0 and fills the vector with random numbers
    std::generate(std::begin(v_0), std::end(v_0), std::rand);

    //Display v_0
    std::copy(v_0.crbegin(), v_0.crend(), std::ostream_iterator<int>(std::cout, "\n"));
    
    return 0; 
}