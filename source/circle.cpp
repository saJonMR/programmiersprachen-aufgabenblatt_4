#include <cmath>
#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"


float Circle::circumference() const {
    float res;
    res = M_PI * (2 * radius_);
    return res;
};

void Circle::draw(Window const& w, float thickness, bool highlight = true) const {
    Vec2 turnit{0, radius_};
    for (int i = 0; i < 360; i++) {
        float bogen = (((2 * M_PI) / 360) * i);
        float bogenPlus = ((2* M_PI) / 360) * i + 1;
        Vec2 rotation = make_rotation_mat2(bogen) * turnit;
        Vec2 rotationPlus = make_rotation_mat2(bogenPlus) * turnit;
        w.draw_line((rotation.x + center_.x), (rotation.y + center_.y), (rotationPlus.x + center_.x), (rotationPlus.y + center_.y), color_.r, color_.g, color_.b, thickness);
    }
};

void Circle::drawSec(Window const& w) const {
    Vec2 res;
    Vec2 turnit{0, radius_};
    float i = w.get_time();
    float bogen = (((2 * M_PI) / 60) * i);
    Vec2 rotation = make_rotation_mat2(bogen) * turnit;
    res.x = - rotation.x + center_.x;
    res.y = - rotation.y + center_.y;
    w.draw_line(center_.x, center_.y, res.x, res.y, color_.r, color_.g, color_.b);
}

void Circle::drawMin(Window const& w) const {
    Vec2 res;
    Vec2 turnit{0, radius_ - 5};
    float i = w.get_time();
    int mnt = i / 60;
    float bogen = (((2 * M_PI) / 60) * mnt);
    Vec2 rotation = make_rotation_mat2(bogen) * turnit;
    res.x = - rotation.x + center_.x;
    res.y = - rotation.y + center_.y;
    w.draw_line(center_.x, center_.y, res.x, res.y, 1, 0, 0);
}

void Circle::drawHr(Window const& w) const {
    Vec2 res;
    Vec2 turnit{0, radius_ - 10};
    float i = - w.get_time();
    int mnt = i / 60;
    int hr = mnt / 60;
    float bogen = (((2 * M_PI) / 12) * hr);
    Vec2 rotation = make_rotation_mat2(bogen) * turnit;
    res.x = - rotation.x + center_.x;
    res.y = - rotation.y + center_.y;
    w.draw_line(center_.x, center_.y, res.x, res.y, 0, 1, 0);
}

bool Circle::is_inside(Vec2 const& v) const {
    bool isit = false;
    Vec2 P{(v.x - center_.x), (v.y - center_.y)};
    int px = P.x;
    int py = P.y;
    float l = sqrt(px^2 + py^2);
    float r = radius_;
    if (r > l) {
        isit = true;
    }
    return isit;
};

bool Circle::is_inside(Window const& w) const {
    bool isit = false;
    std::pair<float, float> pair = w.mouse_position();
    Vec2 ptr{pair.first, pair.second};
    Vec2 ptrRel{(ptr.x - center_.x), (ptr.y - center_.y)};
    int px = ptrRel.x;
    int py = ptrRel.y;
    float l = sqrt(px^2 + py^2);
    float r = radius_;
    if (r > l) {
        isit = true;
    }
    return isit;
};
