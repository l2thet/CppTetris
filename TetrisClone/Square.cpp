#include "Square.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>



Square::Square()
{
	currentState = Up;
	ShapeSize.x = 20;
	ShapeSize.y = 20;

	Location.x = 20;
	Location.y = 20;

	SquareOne = Location;
	SquareTwo.x = SquareOne.x + 10;
	SquareTwo.y = SquareOne.y;
	SquareThree.x = SquareOne.x;
	SquareThree.y = SquareOne.y + 10;
	SquareFour.x = SquareOne.x + 10;
	SquareFour.y = SquareOne.y + 10;
}

void Square::draw()
{
	al_draw_filled_rectangle(SquareOne.x, SquareOne.y, SquareOne.x + 10, SquareOne.y + 10, al_color_name("aqua"));
	al_draw_filled_rectangle(SquareTwo.x, SquareTwo.y, SquareTwo.x + 10, SquareTwo.y + 10, al_color_name("blue"));
	al_draw_filled_rectangle(SquareThree.x, SquareThree.y, SquareThree.x + 10, SquareThree.y + 10, al_color_name("brown"));
	al_draw_filled_rectangle(SquareFour.x, SquareFour.y, SquareFour.x + 10, SquareFour.y + 10, al_color_name("red"));
}

void Square::rotate()
{
	/*switch (currentState) {
	case Up: 
		currentState = Right;
		break;
	case Right: 
		currentState = Down;
		break;
	case Down: 
		currentState = Left;
		break;
	case Left:
		currentState = Up;
		break;
	}*/
}

void Square::move(int updown, int leftright)
{
	Location.y += updown;
	Location.x += leftright;
	SquareOne = Location;
	SquareTwo.x = SquareOne.x + 10;
	SquareTwo.y = SquareOne.y;
	SquareThree.x = SquareOne.x;
	SquareThree.y = SquareOne.y + 10;
	SquareFour.x = SquareOne.x + 10;
	SquareFour.y = SquareOne.y + 10;
}
