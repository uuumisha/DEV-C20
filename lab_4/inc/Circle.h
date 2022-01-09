#pragma once

#include "Point.h"
#include <iostream>

using namespace std;

class Circle {
	int m_radius;
	Point m_point;
public:
	Circle(int x = 0, int y = 0, int radius = 1);
	Circle(const Point &point, int radius);

	double GetArea() const;
	bool operator==(const Circle &other) const;
	friend ostream& operator<<(ostream &os, const Circle& c);
};