#include "window.hpp"
#include "rect.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    Color red{1, 0, 0};
    Color green{0, 1, 0};
    Color blue{0, 0, 1};

    Vec2 v1{150, 200};
    Vec2 v2{400, 500};
    Rect rectangle{v1, v2, red};
    rectangle.draw(win, 20, 1);

    Vec2 outvec{200, 400};
    bool isit = rectangle.is_inside(outvec);

    std::string insideedition = "Is it really inside? " + std::to_string(isit);
    win.draw_text(620, 100, 20, insideedition);

    Vec2 v5{450, 600};
    Vec2 v6{50, 50};
    Rect rectanglethree{v5, v6, red};
    rectanglethree.draw(win, 15, 1);

    Vec2 c1{150, 220};
    Circle circ{c1, 100, green};
    circ.draw(win, 20, 1);

    Circle circctr{c1, 20, blue};
    circctr.draw(win, 20, 1);
    
    bool isitcirc = circ.is_inside(c1);

    std::string insideeditione = "Is it really inside Circ? " + std::to_string(isitcirc);
    win.draw_text(620, 300, 20, insideeditione);

    Vec2 c2{450, 220};
    Circle circ2{c2, 150, blue};
    circ2.draw(win, 15, 1);

    Circle circ2ctr{c2, 10, green};
    circ2ctr.draw(win, 10, 1);

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
