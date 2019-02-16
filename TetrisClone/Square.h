#pragma once

#ifndef __Square_H_INCLUDED__
#define __Square_H_INCLUDED__


//=====================================
// forward declared deps


//=====================================
// Included deps
#include "Shape.h"

class Square: public Shape {
public:
	Square();
	void draw() override;
	void rotate() override;
	void move(int updown, int leftright) override;
private:
	Point SquareOne;
	Point SquareTwo;
	Point SquareThree;
	Point SquareFour;
	ROTATION currentState;
};

#endif // !__Square_H_INCLUDED__
