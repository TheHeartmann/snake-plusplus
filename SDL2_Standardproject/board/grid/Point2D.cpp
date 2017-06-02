//Representation of a point for use with snake 

#include "Point2D.h"

Point2D::Point2D()
{
	x = 0.0f;
	y = 0.0f;
}

Point2D::Point2D(float newX, float newY)
{
	x = newX;
	y = newY;
}

bool Point2D::isInsideSquare(float sq_x, float sq_y, int sq_width, int sq_height) const
{
	if (x > sq_x && x <= sq_x + sq_width)
		if (y > sq_y && y <= sq_y + sq_height)
			return true;

	return false;
}

float Point2D::getX()
{
	return x;
}

float Point2D::getY()
{
	return y;
}

void Point2D::setX(float newX)
{
	x = newX;
}

void Point2D::setY(float newY)
{
	y = newY;
}