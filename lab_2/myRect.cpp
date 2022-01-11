#include "inc\myRect.h"
#include <iostream>
#include <algorithm>

// Конструктор с параметрами
Rect::Rect(int left, int right, int top, int bottom, COLOR c) : Shape(c) {

	if (Check(left, right, top, bottom)) {
		std::cout << "Rect Constructor: wrong parameters. Now its were set to zero.\n";
		m_left		= 0;
		m_right		= 0;
		m_top		= 0;
		m_bottom	= 0;
	}
	else {
		m_left		= left;
		m_right		= right;
		m_top		= top;
		m_bottom	= bottom;
	}
}

// Конструктор без параметров
Rect::Rect() : Shape(RED) {
	m_left		= 0;
	m_right		= 0;
	m_top		= 0;
	m_bottom	= 0;
}

Rect::~Rect() {
	std::cout << "Now I am in Rect's destructor!\n";
}

// Растяжение прямоугольника на 4 разные дельты
void Rect::InflateRect(int dleft, int dright, int dtop, int dbottom) {
	if (Check(m_left - dleft, m_right + dright, m_top + dtop, m_bottom + dbottom))
		std::cout << "Wrong delta parameters\n";
	else {
		m_left -= dleft;
		m_right += dright;
		m_top += dtop;
		m_bottom -= dbottom;
	}
}

// Конструктор копирования
Rect::Rect(const Rect &other) {
	m_left		= other.m_left;
	m_right		= other.m_right;
	m_top		= other.m_top;
	m_bottom	= other.m_bottom;
}

// Растяжение прямоугольника на 2 разные дельты
void Rect::InflateRect(int dwidth, int dhight) {
	if (Check(m_left - dwidth, m_right + dwidth, m_top + dhight, m_bottom + dhight))
		std::cout << "Wrong delta parameters\n";
	else {
		m_left -= dwidth;
		m_right += dwidth;
		m_top += dhight;
		m_bottom -= dhight;
	}
}

// Задать private переменные (вершины)
void Rect::SetAll(int left, int right, int top, int bottom) {
	if (Check(left, right, top, bottom))
		std::cout << "SetAll: wrong parameters.\n";
	else {
		m_left = left;
		m_right = right;
		m_top = top;
		m_bottom = bottom;
	}
}

// Получить private переменные (вершины)
void Rect::GetAll(int &left, int &right, int &top, int &bottom) const {
	left = m_left;
	right = m_right;
	top = m_top;
	bottom = m_bottom;
}

// Получить описанный прямоугольник (метод класса)
void Rect::BoundingRect(const Rect &r1, const Rect &r2) {
	SetAll(std::min(r1.m_left, r2.m_left), std::max(r1.m_right, r2.m_right), std::max(r1.m_top, r2.m_top), std::min(r1.m_bottom, r2.m_bottom));
}

void Rect::WhereAmI() const {
	std::cout << "Now I am in class Rect" << std::endl;
}

void Rect::WhereAmIVirtual() const {
	std::cout << "Now I am in class Rect" << std::endl;
}

void Rect::Inflate(int val) {
	if(val < 0)
		std::cout << "Sorry, we can't inflate with negative parameter" << std::endl;
	else {
		m_left -= val;
		m_right += val;
		m_top += val;
		m_bottom -= val;
	}
}

bool Rect::Check(int left, int right, int top, int bottom) {
	if ((left > right) || (bottom > top))
		return true;
	else
		return false;
}
