#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <algorithm>

bool is_multiple_of_3(int i) {
    return (i % 3 == 0);
}

TEST_CASE("filter alle vielfache von drei", "[erase]") {
    std::vector<unsigned int> v(100);

    for(auto& i : v) {
        i = rand() % 100;
    }

    v.erase(std::remove_if(v.begin(), v.end(), [](int x){return x % 3;}), v.end());

    std::copy(std::cbegin(v), std::cend(v), std::ostream_iterator<int>(std::cout, ", "));

    REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}