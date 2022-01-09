#include "inc\Shape.h"
#include <iostream>

Shape::Shape() {
	m_color = BLUE;
}

Shape::Shape(COLOR c) {
	m_color = c;
}

COLOR Shape::GetColor() const {
	return m_color;
}

void Shape::WhereAmI() const {
	std::cout << "Now I am in class Shape" << std::endl;
}

void Shape::WhereAmIVirtual() const {
	std::cout << "Now I am in class Shape" << std::endl;
}

Shape::~Shape() {
	std::cout << "Now I am in Shape's destructor!\n";
}

// Закомментировать, когда сделаем метод чисто виртуальным
void Shape::Inflate(int val) {
	
}