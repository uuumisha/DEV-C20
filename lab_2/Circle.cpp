#include "inc\Circle.h"
#include <iostream>

// ����������� �� ���������
Circle::Circle() : Shape(GREEN) {
	m_x_center = m_y_center = 0;
	m_radius = 1;
}

// ����������� � �����������
Circle::Circle(int x_center, int y_center, int radius,  COLOR c) : Shape(c) {
	m_x_center = x_center;
	m_y_center = y_center;
	if (radius < 0) {
		std::cout << "Sorry, we can't create circle with negative radius. It will be set to one." << std::endl;
		m_radius = 1;
	}
	else
		m_radius = radius;
}

// ������������� ������� �������������
void Circle::WhereAmI() const {
	std::cout << "Now I am in class Circle" << std::endl;
}

// ����������� ������� �������������
void Circle::WhereAmIVirtual() const {
	std::cout << "Now I am in class Circle" << std::endl;
}

// ����������
Circle::~Circle() {
	std::cout << "Now I am in Circle's destructor!\n";
}

// ����������� � ���������� ������ �������������
Circle::Circle(const Rect &r) : Shape(r) {
	int left, right, top, bottom;
	r.GetAll(left, right, top, bottom);
	m_x_center = right - left;
	m_y_center = top - bottom;
	m_radius = (top - bottom) / 2.0;
}

void Circle::Inflate(int val) {
	if (val < 0)
		std::cout << "Sorry, we can't inflate with negative parameter" << std::endl;
	else
		m_radius += val;
}