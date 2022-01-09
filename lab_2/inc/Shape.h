#pragma once
enum COLOR {RED, GREEN, BLUE};

class Shape {
	COLOR m_color;
public:
	Shape();
	Shape(COLOR c);
	void WhereAmI() const;
	COLOR GetColor() const;
	virtual void WhereAmIVirtual() const;
	virtual ~Shape();
	//virtual void Inflate(int val) = 0;
	virtual void Inflate(int val);
};