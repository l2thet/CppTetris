#pragma once

#ifndef __T_H_INCLUDED__
#define __T_H_INCLUDED__


//=====================================
// forward declared deps


//=====================================
// Included deps
#include "Shape.h"

class T : public Shape {
public:
	T();
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
