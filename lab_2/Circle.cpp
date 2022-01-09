#include "inc\Circle.h"
#include <iostream>

// Конструктор по умолчанию
Circle::Circle() : Shape(GREEN) {
	m_x_center = m_y_center = 0;
	m_radius = 1;
}

// Конструктор с параметрами
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

// Невиртуальная функция идентификации
void Circle::WhereAmI() const {
	std::cout << "Now I am in class Circle" << std::endl;
}

// Виртуальная функция идентификации
void Circle::WhereAmIVirtual() const {
	std::cout << "Now I am in class Circle" << std::endl;
}

// Деструктор
Circle::~Circle() {
	std::cout << "Now I am in Circle's destructor!\n";
}

// Конструктор с параметром класса прямоульников
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