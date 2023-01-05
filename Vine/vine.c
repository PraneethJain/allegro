#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "allegro.h"

const float MAX_LEVELS = 18;
const float MAIN_LENGTH_FACTOR = 0.8;
const float SIDE_LENGTH_FACTOR = 0.7;
const float MAIN_THICKNESS_FACTOR = 0.8;
const float SIDE_THICKNESS_FACTOR = 0.5;

double rad(double deg)
{
    return M_PI * deg / 180;
}

void draw_line(int x, int y, float length, float thickness, float angle, int level)
{
    if (level == MAX_LEVELS)
        return;

    // Draw the main vine
    int main_x = x - length * sin(rad(angle));
    int main_y = y - length * cos(rad(angle));
    al_draw_line(x, y, main_x, main_y, al_map_rgb(level / MAX_LEVELS * 76, level / MAX_LEVELS * 187, level / MAX_LEVELS * 24), thickness);
    draw_line(main_x, main_y, length * MAIN_LENGTH_FACTOR, thickness * MAIN_THICKNESS_FACTOR, angle + 30, level + 1);

    // Draw the side vine
    length *= SIDE_LENGTH_FACTOR;
    thickness *= SIDE_THICKNESS_FACTOR;
    int side_x = x + length * cos(rad(angle - 30));
    int side_y = y - length * sin(rad(angle - 30));
    al_draw_line(x, y, side_x, side_y, al_map_rgb(0, 0, 0), thickness);
    draw_line(side_x, side_y, length * MAIN_LENGTH_FACTOR, thickness * MAIN_THICKNESS_FACTOR, angle - 60, level + 1);

    al_flip_display();
}

void rec_drawing()
{
    draw_line(3 * WIDTH / 4, HEIGHT, 250, 80, 0, 0);
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