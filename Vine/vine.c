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

void draw_line(int x, int y, float length, float thickness, float angle, int level, ALLEGRO_COLOR *colors, int current_color)
{
    if (level == MAX_LEVELS)
        return;

    if (current_color == 7)
    {
        current_color = 0;
    }

    // Draw the main vine
    int main_x = x - length * sin(rad(angle));
    int main_y = y - length * cos(rad(angle));
    al_draw_line(x, y, main_x, main_y, colors[current_color], thickness);
    draw_line(main_x, main_y, length * MAIN_LENGTH_FACTOR, thickness * MAIN_THICKNESS_FACTOR, angle + 30, level + 1, colors, current_color + 1);

    // Draw the side vine
    length *= SIDE_LENGTH_FACTOR;
    thickness *= SIDE_THICKNESS_FACTOR;
    int side_x = x + length * cos(rad(angle - 30));
    int side_y = y - length * sin(rad(angle - 30));
    al_draw_line(x, y, side_x, side_y, colors[current_color], thickness);
    draw_line(side_x, side_y, length * MAIN_LENGTH_FACTOR, thickness * MAIN_THICKNESS_FACTOR, angle - 60, level + 1, colors, current_color + 1);

    al_flip_display();
}

void rec_drawing()
{
    ALLEGRO_COLOR colors[7];
    colors[6] = al_map_rgb(148, 0, 211);
    colors[5] = al_map_rgb(75, 0, 130);
    colors[4] = al_map_rgb(0, 0, 255);
    colors[3] = al_map_rgb(0, 255, 0);
    colors[2] = al_map_rgb(255, 255, 0);
    colors[1] = al_map_rgb(255, 127, 0);
    colors[0] = al_map_rgb(255, 0, 0);
    draw_line(3 * WIDTH / 4, HEIGHT, 250, 80, 0, 0, colors, 0);
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