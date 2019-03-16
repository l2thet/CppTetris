#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include "Square.h"
#include "T.h"

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE
};

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_TIMER *keyPointer = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;
	Shape *firstShape = new T();

	bool key[5] = { false, false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	keyPointer = al_create_timer(.1);
	if (!timer || !keyPointer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to init primitives!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(keyPointer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	al_start_timer(keyPointer);
	
	//al_stop_timer

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		if (ev.timer.source == keyPointer) {
			al_get_keyboard_state(&keyState);
			if (al_key_down(&keyState, ALLEGRO_KEY_UP) && (firstShape->Location.y + firstShape->ShapeRange.MinYFromCenterBlock) >= 10) {
				firstShape->move(-10, 0);
			}

			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) && (firstShape->Location.y + firstShape->ShapeRange.MaxYFromCenterBlock) <= SCREEN_H - 10) {
				firstShape->move(10, 0);
			}

			if (al_key_down(&keyState, ALLEGRO_KEY_LEFT) && (firstShape->Location.x + firstShape->ShapeRange.MinXFromCenterBlock) >= 10) {
				firstShape->move(0, -10);
			}

			if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && (firstShape->Location.x + firstShape->ShapeRange.MaxXFromCenterBlock) <= SCREEN_W - 10) {
				firstShape->move(0, 10);
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == timer) {
			if (key[KEY_UP] && (firstShape->Location.y + firstShape->ShapeRange.MinYFromCenterBlock) >= 10) {
				firstShape->move(-10, 0);
			}

			if (key[KEY_DOWN] && (firstShape->Location.y + firstShape->ShapeRange.MaxYFromCenterBlock) <= SCREEN_H - 10) {
				firstShape->move(10, 0);
			}

			if (key[KEY_LEFT] && (firstShape->Location.x + firstShape->ShapeRange.MinXFromCenterBlock) >= 10) {
				firstShape->move(0, -10);
			}

			if (key[KEY_RIGHT] && (firstShape->Location.x + firstShape->ShapeRange.MaxXFromCenterBlock) <= SCREEN_W - 10) {
				firstShape->move(0, 10);
			}

			if (key[KEY_SPACE]) {
				firstShape->rotate();
			}

			key[KEY_UP] = false;
			key[KEY_DOWN] = false;
			key[KEY_LEFT] = false;
			key[KEY_RIGHT] = false;
			key[KEY_SPACE] = false;

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = true;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			firstShape->draw();

			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_timer(keyPointer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	delete firstShape;

	return 0;
}