#include "T.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>



T::T()
{
	currentState = Up;
	ShapeSize.x = 20;
	ShapeSize.y = 20;

	Location.x = 20;
	Location.y = 20;

	SquareOne = Location;
	SquareTwo.x = SquareOne.x;
	SquareTwo.y = SquareOne.y + 10;
	SquareThree.x = SquareOne.x + 10;
	SquareThree.y = SquareOne.y + 10;
	SquareFour.x = SquareOne.x - 10;
	SquareFour.y = SquareOne.y + 10;
}

void T::draw()
{
	al_draw_filled_rectangle(SquareOne.x, SquareOne.y, SquareOne.x + 10, SquareOne.y + 10, al_color_name("aqua"));
	al_draw_filled_rectangle(SquareTwo.x, SquareTwo.y, SquareTwo.x + 10, SquareTwo.y + 10, al_color_name("blue"));
	al_draw_filled_rectangle(SquareThree.x, SquareThree.y, SquareThree.x + 10, SquareThree.y + 10, al_color_name("brown"));
	al_draw_filled_rectangle(SquareFour.x, SquareFour.y, SquareFour.x + 10, SquareFour.y + 10, al_color_name("red"));
}

void T::rotate()
{
	switch (currentState) {
	case Up: 
		currentState = Right;
		SquareOne = Location;
		SquareTwo.x = SquareOne.x - 10;
		SquareTwo.y = SquareOne.y;
		SquareThree.x = SquareOne.x - 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y + 10;
		break;
	case Right: 
		currentState = Down;
		SquareOne = Location;
		SquareTwo.x = SquareOne.x;
		SquareTwo.y = SquareOne.y - 10;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y - 10;
		break;
	case Down: 
		currentState = Left;
		break;
	case Left:
		currentState = Up;
		SquareOne = Location;
		SquareTwo.x = SquareOne.x;
		SquareTwo.y = SquareOne.y + 10;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y + 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y + 10;
		break;
	}
}

void T::move(int updown, int leftright)
{
	switch(currentState) {
	case Up:
		Location.y += updown;
		Location.x += leftright;
		SquareOne = Location;
		SquareTwo.x = SquareOne.x;
		SquareTwo.y = SquareOne.y + 10;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y + 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y + 10;
		break;
	case Right:
		Location.y += updown;
		Location.x += leftright;
		SquareOne = Location;
		SquareTwo.x = SquareOne.x - 10;
		SquareTwo.y = SquareOne.y;
		SquareThree.x = SquareOne.x - 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y + 10;
		break;
	case Down:
		Location.y += updown;
		Location.x += leftright;
		SquareOne = Location;
		SquareTwo.x = SquareOne.x;
		SquareTwo.y = SquareOne.y - 10;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y - 10;
		break;
	}
	
}
