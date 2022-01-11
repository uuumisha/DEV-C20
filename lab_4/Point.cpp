#include "inc\Point.h"
#include <utility>

// ������������

Point::Point(int x, int y) {
	m_x = x;
	m_y = y;
}

// ��������� ����� ������ ������
Point Point::operator +(const Point &other) const {
	Point tmp(m_x + other.m_x, m_y + other.m_y);
	return tmp;
}

Point Point::operator +(int val) const {
	Point tmp(m_x + val, m_y + val);
	return tmp;
}

bool Point::operator ==(const Point &other) const {
	if ((m_x == other.m_x) && (m_y == other.m_y))
		return true;
	else
		return false;
}

Point& Point::operator +=(const Point &other) {
	this->operator+(other);
	return *this;
}

Point& Point::operator +=(int val) {
	this->operator+(val);
	return *this;
}

Point Point::operator -() {
	Point tmp(-m_x, -m_y);
	return tmp;
}

Point& Point::operator +() {
	return *this;
}


// ��������� ����� ���������� �������

Point operator -(Point &pt1, const Point & pt2) {
	Point tmp(pt1.m_x - pt2.m_x, pt1.m_y - pt2.m_y);
	return tmp;
}

Point operator -(Point &pt1, int val) {
	Point tmp(pt1.m_x - val, pt1.m_y - val);
	return tmp;
}

Point& operator-=(Point &pt1, int val) {
	operator-(pt1, val);
	return pt1;
}

Point& operator-=(Point &pt1, const Point &pt2) {
	operator-(pt1, pt2);
	return pt1;
}

Point operator +(int val, Point &pt1) {
	Point tmp(pt1.m_x + val, pt1.m_y + val);
	return tmp;
}

ostream& operator<<(ostream &os, const Point& p) {
	os << "( " << p.m_x << " " << p.m_y << " )"  <<  endl;
	return os;
}