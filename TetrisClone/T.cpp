#include "T.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>



T::T()
{
	

	//Shape going left and right from SquareOne
	ShapeSize.x = 20;
	ShapeSize.y = 20;

	Location.x = 20;
	Location.y = 20;

	currentState = Up;
	ShapeRange.MinYFromCenterBlock = 0;
	ShapeRange.MaxYFromCenterBlock = 20;
	ShapeRange.MinXFromCenterBlock = -10;
	ShapeRange.MaxXFromCenterBlock = 20;

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
	SquareOne = Location;
	switch (currentState) {
	case Up: 
		currentState = Right;
		ShapeRange.MinYFromCenterBlock = -10;
		ShapeRange.MaxYFromCenterBlock = 20;
		ShapeRange.MinXFromCenterBlock = -10;
		ShapeRange.MaxXFromCenterBlock = 10;
		SquareTwo.x = SquareOne.x - 10;
		SquareTwo.y = SquareOne.y;
		SquareThree.x = SquareOne.x - 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y + 10;
		break;
	case Right: 
		currentState = Down;
		ShapeRange.MinYFromCenterBlock = -10;
		ShapeRange.MaxYFromCenterBlock = 10;
		ShapeRange.MinXFromCenterBlock = -10;
		ShapeRange.MaxXFromCenterBlock = 20;
		SquareTwo.x = SquareOne.x;
		SquareTwo.y = SquareOne.y - 10;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y - 10;
		break;
	case Down: 
		currentState = Left;
		ShapeRange.MinYFromCenterBlock = -10;
		ShapeRange.MaxYFromCenterBlock = 20;
		ShapeRange.MinXFromCenterBlock = 0;
		ShapeRange.MaxXFromCenterBlock = 20;
		SquareTwo.x = SquareOne.x + 10;
		SquareTwo.y = SquareOne.y;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y + 10;
		SquareFour.x = SquareOne.x + 10;
		SquareFour.y = SquareOne.y - 10;
		break;
	case Left:
		currentState = Up;
		ShapeRange.MinYFromCenterBlock = 0;
		ShapeRange.MaxYFromCenterBlock = 20;
		ShapeRange.MinXFromCenterBlock = -10;
		ShapeRange.MaxXFromCenterBlock = 20;
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
	Location.y += updown;
	Location.x += leftright;
	SquareOne = Location;
	switch(currentState) {
	case Up:
		SquareTwo.x = SquareOne.x;
		SquareTwo.y = SquareOne.y + 10;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y + 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y + 10;
		break;
	case Right:
		SquareTwo.x = SquareOne.x - 10;
		SquareTwo.y = SquareOne.y;
		SquareThree.x = SquareOne.x - 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y + 10;
		break;
	case Down:
		SquareTwo.x = SquareOne.x;
		SquareTwo.y = SquareOne.y - 10;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y - 10;
		SquareFour.x = SquareOne.x - 10;
		SquareFour.y = SquareOne.y - 10;
		break;
	case Left:
		SquareTwo.x = SquareOne.x + 10;
		SquareTwo.y = SquareOne.y;
		SquareThree.x = SquareOne.x + 10;
		SquareThree.y = SquareOne.y + 10;
		SquareFour.x = SquareOne.x + 10;
		SquareFour.y = SquareOne.y - 10;
		break;
	}
	
}
