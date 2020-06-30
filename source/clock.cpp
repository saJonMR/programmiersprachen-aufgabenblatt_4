#include "window.hpp"
#include "rect.hpp"
#include "circle.hpp"
#include "color.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>


int main()
{
    Window win{std::make_pair(800,800)};

    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            win.close();
        }
        Color black{0, 0, 0};
        Vec2 ctr{400, 400};
        Circle clock{ctr, 100, black};

        clock.draw(win, 0.1f, 1);
        clock.drawSec(win);
        clock.drawMin(win);
        clock.drawHr(win);
        
        win.update();
    }
    return 0;
}
