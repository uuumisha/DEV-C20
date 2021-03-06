#include <iostream>
#include "inc/myRect.h"
#include "inc/myString.h"
#include "inc/Bochka.h"


#define stop __asm nop

using namespace std;

int main()
{
	//Задание 1.Объявление класса. Создание экземпляра класса.
	//Вызов методов класса. 
	//Откройте закладку Class View - (здесь Вы увидите имена методов и
	//данных - классов Rect и MyString)
	//Обратите внимание на пиктограммы слева от имен членов класса - они
	//обозначают спецификатор доступа к каждому члену класса.
	//Какой конструктор вызывается при создании экземпляра класса?
	{
		Rect rect; // default конструктор
		stop
	}
	//1a. Объявите и определите конструктор с параметрами для
	//инициализации переменных класса. Создайте экземляры класса Rect
	//с помощью конструктора с параметрами. Если компилятор выдает
	//ошибку в предыдущем фрагменте, подумайте - чего ему не
	//хватает? Добейтесь отсутствия ошибок.
	//Выполняя задание с самого начала по шагам, определите:
	//в какой момент происходит вызов конструктора(какого?)?
	//Подсказка: учтите, что пользователь Вашего класса может указывать
	//в качестве параметров любые значения! Например:
	// Rect rrr(4,3,2,1);

	Rect r_ok(0, 4, 3, 0);
	Rect r_err(2, 0, 3, 0);
	
	stop
	//1б. При конструировании объекта посредством конструктора без параметров
	//предусмотрите инициализацию переменных класса, например, нулем
	
	Rect r_null;
	
	stop
	//1в. Объявите, определите и вызовите метод класса InflateRect(), 
	//который увеличивает размеры прямоугольника на заданные приращения
	//(раздвигая стороны от центра - каждую сторону на свое значение).
	//Подсказка: объявить и определить методы можно не только "вручную",
	//но и с помощью Wizard-a Class View. Для этого: откройте закладку
	//ClassView окна проекта, сделайте активным класс Rect и нажмите
	//правую кнопку мыши - в появившемся контекстном меню выберите
	//Add/Add Member Function... С помощью появившейся диалоговой панели
	//"дайте указания" Wizard-у как объявить и определить метод.
	
	r_ok.InflateRect(1,1,1,1);
	
	stop

	//Задание 2.Перегрузка конструкторов и методов класса.
	//Конструктор копирования.
	//2а.Объявите и определите конструктор копирования в классе Rect.
	//Выполняя задание по шагам, определите, какой
	//конструктор вызывается при создании r1,r2,r3 и r4?
	//Чему равны переменные созданных объектов?
	Rect r1;
	Rect r2(1,2,3,4);
	Rect r3 = r1;
	Rect r4(r2);

	stop
  //2б. Объявите и определите в классе Rect метод InflateRect(),
	//который принимает два аргумента, по умолчанию равных 1, и 
	//раздвигает стороны прямоугольника на заданные приращения.
	//Для каких объектов вызывается функция InflateRect()?
	r1.InflateRect(1,1);	
	r2.InflateRect(2,2);
	//Какая из функций InflateRect() вызывается в каждом из трех случаев?
	r3.InflateRect(2,2,2,2);
	r3.InflateRect(3,3);
	r3.InflateRect(5);
	r3.InflateRect();

	stop

	
	//Задание 3.Спецификаторы доступа. Инкапсуляция. 
	{
	Rect r;
	//Раскомментируйте следующую строку. Объясните ошибку
	//компилятора
	//int tmp = r.m_left; // переменная private
	//Введите в класс Rect метод void SetAll(...),
	//который присваивают переменным класса передаваемые
	//значения. Вызовите созданный метод, проверьте корректность. 
	//Введите в класс Rect парный метод GetAll(...),
	//который "достает" значения private-переменных класса.
	//Вызовите созданный метод, проверьте корректность. 

	int left = 100, right = 200, top = 100, bottom = 0;
	Rect r_get_set_test(0, 1, 1, 0);
	r_get_set_test.SetAll(left, right, top, bottom);
	left = 0, right = 0, top = 0, bottom = 0;
	r_get_set_test.GetAll(left, right, top, bottom);

	stop

	}

	//Задание 4.Передача экземпляра класса в качестве параметра
	//функции. Возвращение объекта класса по значению. Поставив
	//остановы в конструкторе копирования или выполняя фрагмент
	//по шагам, определите: в какой момент происходит обращение
	//к конструктору копирования. 
	//Создайте глобальную функцию 
	//Rect BoundingRect(Rect, Rect);
	//которая принимает два объекта класса Rect по значению и
	//возвращает объект класса Rect, который является прямоугольником,
	//в который вписаны заданные прямоугольники. Как происходит
	//передача параметров и возвращение объекта класса?
	//Замечание*: хорошо было бы учесть тот факт, что прямоугольник
	//может оказаться "ненормализованным", то есть m_left>m_right или/и
	//m_top<m_bottom
	{
		Rect r1(1,2,3,4), r2(5,6,7,8),r3;
		r3= BoundingRect(r1, r2);
	stop
	
	//Задание 4а. Передача объектов по ссылке.
	//Создайте глобальную функцию BoundingRect2, которая выполняет ту же
	//задачу, принимая параметры по ссылке
	//Вызываются ли конструкторы при передаче параметров?
	
	r3 = BoundingRect2(r1, r2);
	stop
	}
	//Задание 4б.Реализуйте ту же задачу (BoundingRect) методом класса
	{
		Rect r4(0, 20, 20, 0), r5(0, 10, 10, 0), r3;
		r3.BoundingRect(r1, r2);
	}

	//Задание 5. Когда вызываются конструкторы и деструкторы.
	//Объявите и определите
	//явный деструктор класса. Поставьте остановы в 
	//конструкторе (конструкторах) и деструкторе. Определите: когда для
	//каждого из объектов вызывается конструктор, а когда - деструктор?
	{
		Rect r1;
		Rect*	pR = new Rect(1,2,1,2);	
		{
			Rect r2(r1);
			Rect arRect[2];
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i) ;
				Rect r4(*pR);
				Rect r5(i,i,i,i);
			}
		}
		delete pR;	
		stop
	}


	//Задание 6.Конструктор + деструктор = функциональное
	// замыкание. Класс MyString
	// Посредством конструктора (конструкторов) и деструктора обеспечьте
	//корректные инициализацию и деактивацию объекта
	//C помощью остановов определите когда происходит
	//захват и освобождение памяти для строки-члена класса
	{
		MyString	str("It's my string!");
		//Создайте метод GetString(), который обеспечит доступ к хранящейся строке.
		//С помощью cout и метода GetString() распечатайте строку объекта str
		//Замечание: подумайте, как следует корректно реализовать метод GetString().
		//...
		cout << str.GetString() << "\n";
	}
	stop


	//6a. Раскомментируйте следующий фрагмент. Подумайте - какие
	//неприятности Вас ожидают. Попробуйте исправить положение (как?)
	{
		MyString str1("The first string!");
		MyString str2 = str1;
	}
	stop
	//6б. Реализуйте метод SetNewString, который будет заменять строку
	// на новую
	{
		MyString str1("The second string!");
		str1.SetNewString("The replace string");
	}
	


	//Задание 7.  Решите с помощью классов следующую задачу:
	//даны две бочки известного объема. В одной бочке в начальный момент
	//времени содержится спирт (96%), в другой – вода.
	//Кружкой емкостью 1л переливаем итеративно содержимое из одной бочки
	//в другую следующим способом: на каждой итерации
	//зачерпнули из первой бочки -> вылили во вторую
	//зачерпнули из второй бочки -> вылили в первую.
	//Требуется определить номер итерации, на которой концентрация спирта в
	//первой бочке станет меньше 50%.

	Bochka spirt(96, 100);
	Bochka water(0, 100);
	int cnt = 0;

	while(spirt.GetConc() >= 0.5) {
		spirt.Pereliv(water, 1); //или spirt.Pereliv(water, объем_кружки);
		water.Pereliv(spirt, 1); // аналогично
		cnt++;
	}
	cout << "Done. Cnt = " << cnt;

	return 0;
}//end_main