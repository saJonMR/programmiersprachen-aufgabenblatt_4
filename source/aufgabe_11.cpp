#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <algorithm>
#include <functional>

bool is_ten(int x) {
    return (x == 10);
}

TEST_CASE("vectoren inhalte addieren", "[add]") {
    std::vector<int> v_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v_2{9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> v_3(9);

    std::transform(v_1.cbegin(), v_1.cend(), v_2.cbegin(), v_3.begin(), [](int x, int y){return x + y;});

    REQUIRE(std::all_of(v_3.begin(), v_3.end(), is_ten));
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}