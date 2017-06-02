#pragma once

class Point2D
{
public:
	Point2D ();
	Point2D (float newX, float newY);
	bool isInsideSquare (float x, float y, int width, int height) const;
	float getX ();
	float getY ();

	void setX (float newX);
	void setY (float newY);

private:
	float x;
	float y;
};