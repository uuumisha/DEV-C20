#include "inc\Point.h"
#include <utility>

// Конструкторы
Point::Point() {
	m_x = m_y = 0;
}

Point::Point(int x) {
	m_x = x;
	m_y = 0;
}

Point::Point(int x, int y) {
	m_x = x;
	m_y = y;
}


// Операторы через методы класса
Point Point::operator +(const Point &other) const {
	Point tmp(m_x + other.m_x, m_y + other.m_y);
	return tmp;
}

Point Point::operator +(int val) const {
	Point tmp(m_x + val, m_y + val);
	return tmp;
}

Point& Point::operator +=(const Point &other) {
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}

Point& Point::operator +=(int val) {
	m_x += val;
	m_y += val;
	return *this;
}

Point Point::operator -() const {
	Point tmp(-m_x, -m_y);
	return tmp;
}

const Point& Point::operator +() const {
	return *this;
}


// Операторы через глобальные функции

Point operator -(const Point &pt1, const Point & pt2) {
	Point tmp(pt1.m_x - pt2.m_x, pt1.m_y - pt2.m_y);
	return tmp;
}

Point operator -(const Point &pt1, int val) {
	Point tmp(pt1.m_x - val, pt1.m_y - val);
	return tmp;
}

Point& operator-=(Point &pt1, int val) {
	pt1 = pt1 - val;
	return pt1;
}

Point& operator-=(Point &pt1, const Point &pt2) {
	pt1 = pt1 - pt2;
	return pt1;
}

Point operator +(int val, const Point &pt1) {
	Point tmp(pt1.m_x + val, pt1.m_y + val);
	return tmp;
}