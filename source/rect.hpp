#ifndef RECT_HPP
#define RECT_HPP

#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Rect {
    public:
        Rect() :
            min_{0, 0},
            max_{1, 1},
            color_{255, 0, 0}
        {}

        Rect(Vec2 const& v1, Vec2 const& v2, Color const& rgb) :
            min_{v1.x, v1.y},
            max_{v1.x + v2.x, v1.y + v2.y},
            color_{rgb.r, rgb.g, rgb.b}
        {}
            
        float circumference() const;

        void draw(Window const& w, bool highlight) const;
        void draw(Window const& w, float thickness, bool highlight) const;

        bool is_inside(Vec2 const& v) const;
        bool is_inside(Window const& w) const;
        
    private:
        Vec2 min_;
        Vec2 max_;
        Color color_;
};

#endif //RECT_HPP