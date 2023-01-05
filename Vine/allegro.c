#include <stdio.h>
#include "allegro.h"

int WIDTH = 1920;
int HEIGHT = 1080;

ALLEGRO_EVENT_QUEUE *queue = NULL;
ALLEGRO_DISPLAY *disp = NULL;

void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

void allegro_init()
{
    must_init(al_init(), "init");

    queue = al_create_event_queue();
    must_init(queue, "queue");

    disp = al_create_display(WIDTH, HEIGHT);
    must_init(disp, "disp");

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_display_event_source(disp));
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_set_window_title(disp, "Vine");
}

void allegro_close()
{
    al_destroy_display(disp);
    al_destroy_event_queue(queue);
}
