#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "allegro.h"

float random_num()
{
    return (float)rand() / (float)(RAND_MAX)-0.5;
}

const float del_theta = 0.4;
const float del_g = 0.1;
const float length_factor = 0.8;
const float thickness_factor = 0.8;
const int MAX_LEVEL = 13;

void draw_line(int x, int y, float length, float angle, float thickness, int level)
{
    if (level == MAX_LEVEL)
        return;
    float end_x = x - length * sin(angle);
    float end_y = y - length * cos(angle);
    al_draw_line(x, y, end_x, end_y, level <= MAX_LEVEL - 4 ? al_map_rgb(97, 59, 22) : al_map_rgb(12, 174, 91), thickness);
    draw_line(end_x, end_y, length * length_factor, angle + del_theta + random_num() / 4, thickness * thickness_factor, level + 1);
    draw_line(end_x, end_y, length * length_factor, angle - del_theta + random_num() / 4, thickness * thickness_factor, level + 1);
    al_flip_display();
}

void rec_drawing()
{
    draw_line(WIDTH / 2, HEIGHT, 150, 0, 15, 0);
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