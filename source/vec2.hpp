#ifndef VEC2_HPP
#define VEC2_HPP

//Vec 2 data type definition
struct Vec2 {
    float x{0.0f};
    float y{0.0f};

    //Member Funktionen
    Vec2& operator+=(Vec2 const& v);
    Vec2& operator-=(Vec2 const& v);
    Vec2& operator*=(float s);
    Vec2& operator/=(float s);
};

Vec2 operator+(Vec2 const & u, Vec2 const & v);
Vec2 operator-(Vec2 const & u, Vec2 const & v);
Vec2 operator*(Vec2 const & v, float s);
Vec2 operator/(Vec2 const & v, float s);
Vec2 operator*(float s, Vec2 const & v);


#endif //VEC2_HPP