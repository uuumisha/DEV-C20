// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.


#include <tchar.h>
#include <iostream>
#include "inc\myString.h"
#include "inc\Shape.h"
#include "inc\myRect.h"
#include "inc\Circle.h"
#include "inc\Bytes.h"


#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//������� 1.������ �������� ������.
	{
	//�������� � ������������������ ������ ar �� ��������
	// ���� MyString. 
		const int N=3;
		MyString str1[N] = { "First string", "Second string" , "Third string" };
  
	//�������� - ������ �����-������ ������
		for (int i = 0; i < N; i++)
			cout << str1[i].GetString() << endl;

	//�������� ������ const int N=5; , �� ������� ������ ��������������� (�������� ����������� �� ���������).
		const int N2 = 5;
		MyString str2[N2] = { "First string", "Second string" , "Third string" };
		for (int i = 0; i < N2; i++)
			cout << str2[i].GetString() << endl;		
	}
	stop


	//������� 2.������ ���������� �� ������� ������.
	{
	//�������� � ������������������ ������ arPtr �� N
	//���������� �� ������� ���� MyString (���� ������� 
	//��������� �����������!).
		const int N=3;
		MyString **arPtr = new MyString*[N];
		arPtr[0] = new MyString("First string");
		arPtr[1] = new MyString("Second string");
		arPtr[2] = new MyString("Third string");
	
	//������ �����-������ ������
		for (int i = 0; i < N; i++)
			cout << arPtr[i]->GetString() << endl;
		delete[] arPtr;
   	//�������� ������ const int N=5; , �� ������� ������ ���������������.
		const int N2 = 5;
		MyString **arPtr2 = new MyString*[N2];
		arPtr2[0] = new MyString("First string");
		arPtr2[1] = new MyString("Second string");
		arPtr2[2] = new MyString("Third string");
		//for (int i = 0; i < N2; i++)
		//	cout << arPtr2[i]->GetString() << endl;
		delete[] arPtr2;
	}
		stop


	//������� 3.������� ������������.��������� ������������,
	// ������������ � ������� �����.

	//�������� �������� �������:
	//������� ����� Shape (������� ��������� ����� ������)
	//� ��� ����������� ������ Rect � Circle.
	//���������: ����� ������ � ������ ����� ������ � �������
	//� ����������� ������ (��������, ����� ������ ����� �������
	//������� => � ������� ������ ����� ������ ����������, �������
	//����� ���������� ���� ������.
	//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);
		
		Shape s1;
	
	//� ������������� ����������� ������� ������������� ��������
	//���������-����� ������������ �������� ������.
	//��� �������� � ����������� ������� ������������ ���� ����������
	//������������������ ������� ������������� � ������������ ��������
	//� ������������ �������
	
		Rect r1(0, 1, 1, 0, BLUE);
		Circle circle(1, 1, 2, GREEN);


	stop
//////////////////////////////////////////////////////////////////////

	//������� 4.����������� �������.
	//4�) ������������� ������ Shape,Rect � Circle:
	//�������� � ������ ����� public ����� void WhereAmI().
	//���������� ������ ������� ������ �������� ��������� 
	//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
	//��������� ����������� ��������, ��������� ���������.


	{
		Shape s;
		Rect r;
		Circle c;

	
		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmI();	//	Now I am in class Shape
		r.WhereAmI();	//	Now I am in class Rect
		c.WhereAmI();	//	Now I am in class Circle
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	Now I am in class Shape
		pRect->WhereAmI();	//	Now I am in class Shape
		pCircle->WhereAmI(); //	Now I am in class Shape
		stop


		//��������� ... �������� ������������
		Shape& rShape = s; //��������� s
		Shape& rRect = r; //��������� r
		Shape& rCircle = c; //��������� c
		rShape.WhereAmI();	//����� ����������� rShape	Now I am in class Shape
		rRect.WhereAmI();	//����� �����������	rRect	Now I am in class Shape
		rCircle.WhereAmI(); //����� ����������� rCircle	Now I am in class Shape
		stop
	}

	//4�) �������� � ������� � ����������� ������ �����������
	// ����� WhereAmIVirtual(). �� �������� � 4� ��������
	// ����������� ����� ����������� ��������, ���������� �
	// ������, ������������ � ���������� ���������.
	//��������� ����� ��������, ��������� ������� (��������� ������� ����������� �������)

	{
		Shape s;
		Rect r;
		Circle c;


		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmIVirtual();	//	Now I am in class Shape
		r.WhereAmIVirtual();	//	Now I am in class Rect
		c.WhereAmIVirtual();	//	Now I am in class Circle
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
		pShape->WhereAmIVirtual();	//	Now I am in class Shape
		pRect->WhereAmIVirtual();	//	Now I am in class Rect
		pCircle->WhereAmIVirtual(); //	Now I am in class Circle
		stop


		//��������� ... �������� ������������
		Shape& rShape = s; //��������� s
		Shape& rRect = r; //��������� r
		Shape& rCircle = c; //��������� c
		rShape.WhereAmIVirtual();	//����� ����������� rShape	Now I am in class Shape
		rRect.WhereAmIVirtual();	//����� �����������	rRect	Now I am in class Rect
		rCircle.WhereAmIVirtual(); //����� ����������� rCircle	Now I am in class Circle
		stop
	}

//////////////////////////////////////////////////////////////////////

	//������� 5.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.	
	// ��� ��������� ����� virtual ���������� ������ ����������� �������� ������

	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������. 
	// � �������� ������ virtual ���������� ����������� ������������ ������, � ����� ����������� �������� ������

	
	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������

		Rect r(0,1,1,0,BLUE);
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
		//�������� ��� ������� �������� ������� ����� WhereAmIVirtual()
		for (int i = 0; i < 4; i++) {
			ar[i]->WhereAmIVirtual();
			delete ar[i];
		}
		// ��������� ������������ ������, � ������������ ������ Circle(Rect &r);
	stop



	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)

		//���������� ������� ����� WhereAmIVirtual() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???
		for (int i = 0; i < 10; i++) {
			static_cast<Rect*>(pShapes)[i].WhereAmIVirtual();
			pRects[i].WhereAmIVirtual();
		}

		//���������� ����������� ����������� ������
		delete[] pShapes;
		delete[] pRects;
	}



//////////////////////////////////////////////////////////////////////

	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		Rect r(0, 2, 2, 0, RED);
		Shape* p = &r;	
		p->WhereAmIVirtual(); //Now I am in class Rect
		stop


		//4a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmIVirtual()������ Shape

		p->Shape::WhereAmIVirtual();
		//static_cast<Shape>(*p).WhereAmIVirtual();
	}


//////////////////////////////////////////////////////////////////////
	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		Rect r(-1, 1, 1, -1, GREEN);
		Shape* p = &r;
		p->Inflate(5);
		Circle c(2, 2, 2, RED);
		p = &c;
		p->Inflate(5);
	}


//////////////////////////////////////////////////////////////////////
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������

	MyString conc_str = Concatenation("qwe", "rty", "123", "456", 0);

////////////////////////////////////////////////////////////////////////
	//������� 10.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	MyByte byte(0x1F);

	// ����� ����� � ��������� ��������
	byte.ShowHex();
	byte.ShowDec();
	byte.ShowOct();
	byte.ShowBin();
	
	// ����� �� �������� ��� hex
	for (int i = 0; i < 2; i++) {
		byte.ShowHexPos(i);
	}

	// ����� �� �������� ��� oct
	for (int i = 0; i < 3; i++) {
		byte.ShowOctPos(i);
	}

	// ����� �� �������� ��� bin
	for (int i = 0; i < 8; i++) {
		byte.ShowBinPos(i);
	}


	return 0;
}//endmain

