#include <stdio.h>
#include <math.h>
#include "allegro.h"

const float del_theta = 0.3;
const float del_g = 0.1;
const float length_factor = 0.8;
const float thickness_factor = 0.9;

void draw_line(int x, int y, float length, float angle, float thickness, float g)
{
    if (length < 10)
        return;
    float end_x = x - length * sin(angle);
    float end_y = y - length * cos(angle);
    al_draw_line(x, y, end_x, end_y, al_map_rgb_f(0, g, 0), thickness);
    draw_line(end_x, end_y, length * length_factor, angle + del_theta, thickness * thickness_factor, g + del_g);
    draw_line(end_x, end_y, length * length_factor, angle - del_theta, thickness * thickness_factor, g + del_g);
}

void rec_drawing()
{
    draw_line(WIDTH / 2, HEIGHT, 125, 0, 5, 0);
    al_flip_display();
}

int main()
{
    allegro_init();
    ALLEGRO_EVENT event;
    rec_drawing();
    al_wait_for_event(queue, &event);
    allegro_close();

    return 0;
}