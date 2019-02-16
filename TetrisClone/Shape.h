#pragma once

#ifndef __Shape_H_INCLUDED__
#define __Shape_H_INCLUDED__


//=====================================
// forward declared deps


//=====================================
// Included deps
#include "Point.h"

enum ROTATION {
	Right = 1, Up = 2, Down = 3, Left = 4
};

class Shape {
public:
	Shape();
	void virtual draw();
	void virtual rotate();
	void virtual move(int updown, int leftright);
	Point ShapeSize;
	Point Location;
	
};

#endif // !__Shape_H_INCLUDED__
