#pragma once
#include "Shape.h"
class Rect : public Shape {
	int m_left, m_right, m_top, m_bottom;
public:
	Rect();
	Rect(int left, int right, int top, int bottom, COLOR c);
	void InflateRect(int dleft, int dright, int dtop, int dbottom);
	void InflateRect(int dwidth = 1, int dhight = 1);
	void SetAll(int left, int right, int top, int bottom);
	void GetAll(int &left, int &right, int &top, int &bottom) const;
	void BoundingRect(const Rect &r1, const Rect &r2);
	void WhereAmI() const;
	void WhereAmIVirtual() const;
	void Inflate(int val);
	Rect(const Rect &other);
	~Rect();
	bool Check(int left, int right, int top, int bottom);
};
