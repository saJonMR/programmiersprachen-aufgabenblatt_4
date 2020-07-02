#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <algorithm>

TEST_CASE("vectoren inhalte addieren", "[add]") {
    std::vector<int> v_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v_2{9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> v_3{};

    //REQUIRE(std::all_of(v_3.begin(), v_3.end(), XXXX));
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}