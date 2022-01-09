#include "inc/myRect.h"
#include <iostream>
#include <algorithm>

// ����������� � �����������
Rect::Rect(int left, int right, int top, int bottom) {

	if ((left > right) || (bottom > top)) {
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

// ����������� ��� ����������
Rect::Rect() {
	m_left		= 0;
	m_right		= 0;
	m_top		= 0;
	m_bottom	= 0;
}

Rect::~Rect() {
	std::cout << "I'm Rect Destructor.\n";
}

// ���������� �������������� �� 4 ������ ������
void Rect::InflateRect(int dleft, int dright, int dtop, int dbottom) {
	m_left		-= dleft;
	m_right		+= dright;
	m_top		+= dtop;
	m_bottom	-= dbottom;
}

// ����������� �����������
Rect::Rect(const Rect &other) {
	m_left		= other.m_left;
	m_right		= other.m_right;
	m_top		= other.m_top;
	m_bottom	= other.m_bottom;
}

// ���������� �������������� �� 2 ������ ������
void Rect::InflateRect(int dwidth, int dhight) {
	m_left -= dwidth;
	m_right += dwidth;
	m_top += dhight;
	m_bottom -= dhight;
}

// ������ private ���������� (�������)
void Rect::SetAll(int left, int right, int top, int bottom) {
	if ((left > right) || (bottom > top))
		std::cout << "SetAll: wrong parameters.\n";
	else {
		m_left = left;
		m_right = right;
		m_top = top;
		m_bottom = bottom;
	}
}

// �������� private ���������� (�������)
void Rect::GetAll(int &left, int &right, int &top, int &bottom) const {
	left = m_left;
	right = m_right;
	top = m_top;
	bottom = m_bottom;
}

// �������� ��������� ������������� (�������� ���������� �� ��������) (����� ������)
void Rect::BoundingRect(const Rect &r1, const Rect &r2) {
	SetAll(std::min(r1.m_left, r2.m_left), std::max(r1.m_right, r2.m_right), std::max(r1.m_top, r2.m_top), std::min(r1.m_bottom, r2.m_bottom));
}

// �������� ��������� ������������� (�������� ���������� �� ��������) (���������� �������)
Rect BoundingRect(Rect r1, Rect r2) {
	int left1, right1, top1, bottom1;
	int left2, right2, top2, bottom2;

	r1.GetAll(left1, right1, top1, bottom1);
	r2.GetAll(left2, right2, top2, bottom2);

	Rect r3(std::min(left1, left2), std::max(right1, right2), std::max(top1, top2), std::min(bottom1, bottom2));
	return r3;
	
}

// �������� ��������� ������������� (�������� ���������� �� ������) (���������� �������)
Rect BoundingRect2(const Rect &r1, const Rect &r2) {
	Rect r3;
	int left1, right1, top1, bottom1;
	int left2, right2, top2, bottom2;

	r1.GetAll(left1, right1, top1, bottom1);
	r2.GetAll(left2, right2, top2, bottom2);

	r3.SetAll(std::min(left1, left2), std::max(right1, right2), std::max(top1, top2), std::min(bottom1, bottom2));
	return r3;
}