#include "vec2.hpp"
#include <string>

//Member Funktionen
Vec2& Vec2::operator+=(Vec2 const& v) {
    x += v.x;
    y += v.y;

    return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v) {
    x -= v.x;
    y -= v.y;

    return *this;
}

Vec2& Vec2::operator*=(float s) {
    x *= s;
    y *= s;

    return *this;
}

Vec2& Vec2::operator/=(float s) {
    if (s == 0) {
        throw std::invalid_argument("Division by 0");
    }
    x /= s;
    y /= s;

    return *this;
}

//Freie Funktionen
Vec2 operator+(Vec2 const & u, Vec2 const & v) {
    Vec2 newVec{u};
    newVec.x += v.x;
    newVec.y += u.y;

    return newVec;
}

Vec2 operator-(Vec2 const & u, Vec2 const & v) {
    Vec2 newVec{u};
    newVec.x -= v.x;
    newVec.y -= u.y;

    return newVec;
}

Vec2 operator*(Vec2 const & v, float s) {
    Vec2 newVec{v};
    newVec.x *= s;
    newVec.y *= s;

    return newVec;
}

Vec2 operator/(Vec2 const & v, float s) {
    Vec2 newVec{v};
    newVec.x /= s;
    newVec.y /= s;

    return newVec;
}

Vec2 operator*(float s, Vec2 const & v) {
    Vec2 newVec{v};
    newVec.x *= s;
    newVec.y *= s;

    return newVec;
}