#include "inc\Circle.h"
#include <iostream>


// конструкторы

Circle::Circle(int x, int y, int radius) : m_point(x, y) {
	if (radius < 0) {
		std::cout << "Warning: radius can't be negative. It was set to 1.";
		m_radius = 1;
	}
	else
		m_radius = radius;
}

Circle::Circle(const Point &point, int radius) : m_point(point) {
	if (radius < 0) {
		std::cout << "Warning: radius can't be negative. It was set to 1.";
		m_radius = 1;
	}
	else
		m_radius = radius;
}


bool Circle::operator==(const Circle &other) const {
	if ((m_radius == other.m_radius) && (m_point == other.m_point))
		return true;
	else
		return false;
}

ostream& operator<<(ostream &os, const Circle& c) {
	os << "Circle with radius " << c.m_radius << " and center " << c.m_point;
	return os;
}

double Circle::GetArea() const {
	return 3.14 * m_radius * m_radius;
}
