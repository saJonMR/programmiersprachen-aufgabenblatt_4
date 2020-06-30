#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "mat2.hpp"
#include "vec2.hpp"
#include "rect.hpp"
#include "circle.hpp"

TEST_CASE("Vec initialisation, [Vec2]") {
  Vec2 def;
  Vec2 v1{5.1f, -9.3f};

  REQUIRE(def.x == 0.0f);
  REQUIRE(def.y == 0.0f);
  REQUIRE(v1.x == Approx(5.1f));
  REQUIRE(v1.y == Approx(-9.3f));
}

TEST_CASE("Vec member funcs, [Vec2]") {
  Vec2 v2{2.0f, 3.0f};
  Vec2 v3{-3.0f, 5.0f};
  Vec2 v4{2.0f, 3.0f};
  Vec2 v5{-3.0f, 5.0f};
  Vec2 v6{2.0f, 3.0f};
  Vec2 v7{2.0f, 4.0f};
  v2 += v3;
  v4 -= v5;
  v6 *= 2;
  v7 /= 2;

  REQUIRE(v2.x == -1.0f);
  REQUIRE(v2.y == 8.0f);
  REQUIRE(v4.x == 5.0f);
  REQUIRE(v4.y == -2.0f);
  REQUIRE(v6.x == 4.0f);
  REQUIRE(v6.y == 6.0f);
  REQUIRE(v7.x == 1.0f);
  REQUIRE(v7.y == 2.0f);
}
TEST_CASE("Vec free funcs, [Vec2]") {
  Vec2 v3{-3.0f, 5.0f};
  Vec2 v5{-3.0f, 5.0f};
  Vec2 v8{4.0f, 12.0f};
  Vec2 plus = v3 + v5;
  Vec2 minus = v3 - v5;
  Vec2 times = v3 * 3.0f;
  Vec2 divided = v8 / 2.0f;
  Vec2 timesR = 3 * v3;

  REQUIRE(plus.x == -6.0f);
  REQUIRE(plus.y == 10.0f);
  REQUIRE(minus.x == 0.0f);
  REQUIRE(minus.y == 0.0f);  
  REQUIRE(times.x == -9.0f);
  REQUIRE(times.y == 15.0f);
  REQUIRE(timesR.x == -9.0f);
  REQUIRE(timesR.y == 15.0f);
  REQUIRE(divided.x == 2.0f);
  REQUIRE(divided.y == 6.0f);
}


TEST_CASE("Mat initialisation, [Mat2]") {
  Mat2 defM;

  REQUIRE(defM.e_00 == 1);
  REQUIRE(defM.e_10 == 0);
  REQUIRE(defM.e_01 == 0);
  REQUIRE(defM.e_11 == 1);
}

TEST_CASE("Mat operators, [Mat2]") {
  Mat2 defM;
  Mat2 m1{1, 2, 3, 4};
  Mat2 m2{5, 6, 7, 8};
  m1 *= m2;
  Mat2 freefunc = m1 * defM;
  float test = defM.det();
  
  REQUIRE(m1.e_00 == 19);
  REQUIRE(m1.e_10 == 22);
  REQUIRE(m1.e_01 == 43);
  REQUIRE(m1.e_11 == 50);
  REQUIRE(freefunc.e_00 == 19);
  REQUIRE(freefunc.e_10 == 22);
  REQUIRE(freefunc.e_01 == 43);
  REQUIRE(freefunc.e_11 == 50);
  REQUIRE(test == 1);
}

TEST_CASE("Mat manipulation, [Mat2]") {
  Mat2 m1{2, 3, 5, 3};
  Mat2 trans = transpose(m1);
  Mat2 m2{2, 4, 4, 6};
  Mat2 inv = inverse(m2);
  Mat2 m3{1, 1, 1, 1};
  Mat2 rot = make_rotation_mat2(1);

  REQUIRE(trans.e_00 == 2);
  REQUIRE(trans.e_10 == 5);
  REQUIRE(trans.e_01 == 3);
  REQUIRE(trans.e_11 == 3);
  REQUIRE(inv.e_00 == -1.5);
  REQUIRE(inv.e_10 == 1);
  REQUIRE(inv.e_01 == 1);
  REQUIRE(inv.e_11 == -0.5);
  REQUIRE(rot.e_00 == Approx(0.5403f));
  REQUIRE(rot.e_10 == Approx(-0.84149f));
  REQUIRE(rot.e_01 == Approx(0.84149f));
  REQUIRE(rot.e_11 == Approx(0.5403f));
}

TEST_CASE("Shape circumference, [Circle/Rect]") {
  Circle c{};
  Rect r{};
  float rect = r.circumference();
  float circ = c.circumference();

  REQUIRE(rect == 4);
  REQUIRE(circ == Approx(6.28319f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
