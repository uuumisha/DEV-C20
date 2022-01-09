#pragma once
#include "Shape.h"
#include "myRect.h"
class Circle : public Shape {
	int m_x_center, m_y_center;
	double m_radius;
public:
	Circle();
	Circle(int x_center, int y_center, int radius, COLOR c);
	Circle(const Rect &r);
	void WhereAmI() const;
	void WhereAmIVirtual() const;
	void Inflate(int val);
	~Circle();
};
