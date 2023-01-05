#ifndef ALLEGRO
#define ALLEGRO

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

extern int WIDTH;
extern int HEIGHT;

extern ALLEGRO_EVENT_QUEUE *queue;
extern ALLEGRO_DISPLAY *disp;

void must_init(bool test, const char *description);

void allegro_init();

void allegro_close();
#endif
