#pragma once
class Point {
	int m_x, m_y;
public:
	Point();
	Point(int x);
	Point(int x, int y);

	Point operator +(const Point &other) const;
	Point operator +(int val) const;

	Point& operator +=(const Point &other);
	Point& operator +=(int val);

	Point operator -() const;
	const Point& operator +() const;

	friend Point operator -(const Point &pt1, const Point & pt2);
	friend Point operator -(const Point &pt1, int val);
	friend Point operator +(int val, const Point &pt1);

	
};

Point operator -(const Point &pt1, const Point & pt2);
Point operator -(const Point &pt1, int val);

Point& operator-=(Point &pt1, const Point & pt2);
Point& operator-=(Point &pt1, int val);

Point operator +(int val, const Point &pt1);