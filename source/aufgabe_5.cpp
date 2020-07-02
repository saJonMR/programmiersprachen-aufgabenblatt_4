#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <algorithm>
#include <list>
#include <iostream>
#include "color.hpp"
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"

TEST_CASE("Overload Comparison operators to sort list of Cirlces, [circle]") {
    std::list<Circle> sorted_circles;

    Vec2 center{};
    Color rgb{};

    Circle c1{center, 20, rgb};
    Circle c2{center, 20, rgb};
    Circle c3{center, 50, rgb};
    Circle c4{center, 10, rgb};
    sorted_circles.push_back(c1);
    sorted_circles.push_back(c2);
    sorted_circles.push_back(c3);
    sorted_circles.push_back(c4);

    sorted_circles.sort();

    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

TEST_CASE("Sort Circles using a Lambda, [circle]") {
    std::list<Circle> sorted_circles;

    Vec2 center{};
    Color rgb{};

    Circle c1{center, 20, rgb};
    Circle c2{center, 20, rgb};
    Circle c3{center, 50, rgb};
    Circle c4{center, 10, rgb};
    sorted_circles.push_back(c1);
    sorted_circles.push_back(c2);
    sorted_circles.push_back(c3);
    sorted_circles.push_back(c4);

    auto sorting_lambda = [](Circle const& lhs, Circle const& rhs)->bool{
            return (lhs.circumference() < rhs.circumference());
        };

    sorted_circles.sort(sorting_lambda);

    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}

