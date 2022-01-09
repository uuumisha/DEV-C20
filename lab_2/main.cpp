// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.


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
	//Задание 1.Массив объектов класса.
	{
	//Объявите и проинициализируйте массив ar из объектов
	// типа MyString. 
		const int N=3;
		MyString str1[N] = { "First string", "Second string" , "Third string" };
  
	//Проверка - печать строк-членов класса
		for (int i = 0; i < N; i++)
			cout << str1[i].GetString() << endl;

	//Замените размер const int N=5; , не изменяя список инициализаторов (добавили конструктор по умолчанию).
		const int N2 = 5;
		MyString str2[N2] = { "First string", "Second string" , "Third string" };
		for (int i = 0; i < N2; i++)
			cout << str2[i].GetString() << endl;		
	}
	stop


	//Задание 2.Массив указателей на объекты класса.
	{
	//Объявите и проинициализируйте массив arPtr из N
	//указателей на объекты типа MyString (сами объекты 
	//создаются динамически!).
		const int N=3;
		MyString **arPtr = new MyString*[N];
		arPtr[0] = new MyString("First string");
		arPtr[1] = new MyString("Second string");
		arPtr[2] = new MyString("Third string");
	
	//Печать строк-членов класса
		for (int i = 0; i < N; i++)
			cout << arPtr[i]->GetString() << endl;
		delete[] arPtr;
   	//Замените размер const int N=5; , не изменяя список инициализаторов.
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


	//Задание 3.Простое наследование.Аргументы конструктора,
	// передаваемые в базовый класс.

	//Создайте иерархию классов:
	//базовый класс Shape (который описывает любую фигуру)
	//и два производных класса Rect и Circle.
	//Подумайте: какие данные и методы нужно ввести в базовый
	//и производные классы (например, любую фигуру можно сделать
	//цветной => в базовом классе можно ввести переменную, которая
	//будет определять цвет фигуры.
	//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);
		
		Shape s1;
	
	//В конструкторах производных классов предусмотрите передачу
	//параметра-цвета конструктору базового класса.
	//При создании и уничтожении объекта производного типа определите
	//последовательность вызовов конструкторов и деструкторов базового
	//и производного классов
	
		Rect r1(0, 1, 1, 0, BLUE);
		Circle circle(1, 1, 2, GREEN);


	stop
//////////////////////////////////////////////////////////////////////

	//Задание 4.Виртуальные функции.
	//4а) Модифицируйте классы Shape,Rect и Circle:
	//добавьте в каждый класс public метод void WhereAmI().
	//Реализация каждой функции должна выводить сообщение 
	//следующего вида "Now I am in class Shape(Rect или Circle)".
	//Выполните приведенный фрагмент, объясните результат.


	{
		Shape s;
		Rect r;
		Circle c;

	
		//Метод какого класса вызывается в следующих строчках???
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


		//Заполните ... согласно комментариям
		Shape& rShape = s; //псевдоним s
		Shape& rRect = r; //псевдоним r
		Shape& rCircle = c; //псевдоним c
		rShape.WhereAmI();	//вызов посредством rShape	Now I am in class Shape
		rRect.WhereAmI();	//вызов посредством	rRect	Now I am in class Shape
		rCircle.WhereAmI(); //вызов посредством rCircle	Now I am in class Shape
		stop
	}

	//4б) Добавьте в базовый и производные классы виртуальный
	// метод WhereAmIVirtual(). По аналогии с 4а вызовите
	// виртуальный метод посредством объектов, указателей и
	// ссылок, определенных в предыдущем фрагменте.
	//Выполните новый фрагмент, объясните разницу (создается таблица виртуальных функций)

	{
		Shape s;
		Rect r;
		Circle c;


		//Метод какого класса вызывается в следующих строчках???
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


		//Заполните ... согласно комментариям
		Shape& rShape = s; //псевдоним s
		Shape& rRect = r; //псевдоним r
		Shape& rCircle = c; //псевдоним c
		rShape.WhereAmIVirtual();	//вызов посредством rShape	Now I am in class Shape
		rRect.WhereAmIVirtual();	//вызов посредством	rRect	Now I am in class Rect
		rCircle.WhereAmIVirtual(); //вызов посредством rCircle	Now I am in class Circle
		stop
	}

//////////////////////////////////////////////////////////////////////

	//Задание 5.Виртуальные деструкторы.
	//Модифицируйте классы:
	//a) введите соответствующие
	// деструкторы (без ключевого слова virtual).
	//Реализация каждого деструктора
	//должна выводить сообщение следующего вида
	// "Now I am in Shape's destructor!" или
	// "Now I am in Rect's destructor!"
	//Выполните фрагмент. Объясните результат.	
	// Без ключевого слова virtual вызывается только конструктор базового класса

	// b) Добавьте в объявление деструкторов ключевое слово virtual 
	//Выполните фрагмент.Объясните разницу. 
	// С ключевым словом virtual вызывается конструктор производного класса, а затем конструктор базового класса

	
	//Подумайте: какие конструкторы вызываются в следующей строке?
		//Если в разработанных классов каких-то конструкторов
		//не хватает - реализуйте
		//Если Вы считаете, что в приведенном фрагменте чего-то
		//не хватает - добавьте

		Rect r(0,1,1,0,BLUE);
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
		//Вызовите для каждого элемента массива метод WhereAmIVirtual()
		for (int i = 0; i < 4; i++) {
			ar[i]->WhereAmIVirtual();
			delete ar[i];
		}
		// Нехватало освобождения памяти, и конструктора класса Circle(Rect &r);
	stop



	//Задание 6*. В чем заключается отличие 1) и 2)
	{
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)

		//Попробуйте вызвать метод WhereAmIVirtual() для каждого элемента обоих массивов -
		//в чем заключается проблема???
		for (int i = 0; i < 10; i++) {
			static_cast<Rect*>(pShapes)[i].WhereAmIVirtual();
			pRects[i].WhereAmIVirtual();
		}

		//Освободите динамически захваченную память
		delete[] pShapes;
		delete[] pRects;
	}



//////////////////////////////////////////////////////////////////////

	//Задание 7.Виртуальные функции и оператор разрешения области видимости. 

	{
		Rect r(0, 2, 2, 0, RED);
		Shape* p = &r;	
		p->WhereAmIVirtual(); //Now I am in class Rect
		stop


		//4a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmIVirtual()класса Shape

		p->Shape::WhereAmIVirtual();
		//static_cast<Shape>(*p).WhereAmIVirtual();
	}


//////////////////////////////////////////////////////////////////////
	//Задание 8.Чисто виртуальные функции. 
	//Введите в базовый класс метод void Inflate(int); Подумайте:
	//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
	//Реализуйте этот метод для производных классов.
	{
		Rect r(-1, 1, 1, -1, GREEN);
		Shape* p = &r;
		p->Inflate(5);
		Circle c(2, 2, 2, RED);
		p = &c;
		p->Inflate(5);
	}


//////////////////////////////////////////////////////////////////////
	//Задание 9. Создайте глобальную функцию, которая будет принимать любое
	//количество указателей на строки, а возвращать объект MyString,
	//в котором строка будет конкатенацией параметров

	MyString conc_str = Concatenation("qwe", "rty", "123", "456", 0);

////////////////////////////////////////////////////////////////////////
	//Задание 10.Объединения (union) C++. Битовые поля.
	//1.
	//Создайте следующие классы для различных представлений значений байта:
	//Bin - для двоичного представления
	//Hex - для шестнадцатерчного представления
	//Oct - для восьмеричного представления.
	//Подсказка 1: - для удобства используйте битовые поля.
	//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
	//так как все они будут членами объединения (union).
	//2.
	//В каждом классе введите метод Show, который должен выводить значение в
	//соответствующем виде
	//3.
	//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
	//одним и тем же значением по-разному:
	//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта 
	//          а также символ, соответствующий хранимому значению (если есть соответствие);
	//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
	//			восьмеричные, двоичные цифры;
	//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;

	MyByte byte(0x1F);

	// Вывод байта в различных форматах
	byte.ShowHex();
	byte.ShowDec();
	byte.ShowOct();
	byte.ShowBin();
	
	// Вывод по позициям для hex
	for (int i = 0; i < 2; i++) {
		byte.ShowHexPos(i);
	}

	// Вывод по позициям для oct
	for (int i = 0; i < 3; i++) {
		byte.ShowOctPos(i);
	}

	// Вывод по позициям для bin
	for (int i = 0; i < 8; i++) {
		byte.ShowBinPos(i);
	}


	return 0;
}//endmain

