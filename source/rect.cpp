#include "rect.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

float Rect::circumference() const {
    float res;
    float length = max_.x - min_.x;
    float height = max_.y - min_.y;
    res = 2 * (length + height);
    return res;
}


void Rect::draw(Window const& w, float thickness, bool highlight = true) const {
    w.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    w.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    w.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    w.draw_line(max_.x, min_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
}


bool Rect::is_inside(Vec2 const& v) const {
    bool itis = false;
    if (min_.x < v.x && v.x < max_.x) {
        if (min_.y < v.y && v.y < max_.y) {
            itis = true;
        }
    }
    return itis;
}

bool Rect::is_inside(Window const& w) const {
    bool isit = false;
    std::pair<float, float> pair = w.mouse_position();
    Vec2 ptr{pair.first, pair.second};
    if (min_.x < ptr.x && ptr.x < max_.x) {
        if (min_.y < ptr.y && ptr.y < max_.y) {
            isit = true;
        }
    }
    return isit;
}