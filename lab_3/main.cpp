// ????:
// ?????????? ??????????.
// ?????????? ??????? 

#include <tchar.h>
#include <iostream>
#include "inc\myString.h"
#include "inc\Point.h"
#include "inc\DataBase.h"
#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
//////////////////////////////////////////////////////////////////////


	//??????? 1.?????????? ??????????.

	//?????????? ? ??????? ????? MyString.cpp ? MyString.h
	//?????? MyString, ?????????????? ???? ?? ?????????? ???????
	//9a. ??????????? ???????? ???????????? ??? ?????? MyString
	//????????? ???????????? ?????? ?????????????? ?????????

	{
		MyString s1("AAA"), s2;
		s2=s1;
		s1="CCC";
		s2= MyString("tmp"); // ???????????? 
		s1=s1;
		s1.operator=("check");
		stop
	}
	

	//2.???????? ????? Point, ??????? ????? ????????? ??????????
	//"?????". ???????? ??????????? (????????????) ??????   

	//2b. "???????????" ???????? += ???, ????? ??? ??????????
	//???????? ???? pt2+=pt1; ????????????
	//??????????? ?????????? ???????? pt1 ? pt2, ? ?????
	//????????????? ??????????????? ?????????? ??????? pt2 ???
	// ? ??????  pt2+=1; ??? ?????????? ??????? pt2 ????????????? ??
	// ????????? ????????
	//a) ? ??????? ?????? ?????? (???????? +=)
	//?) ? ??????? ?????????? ??????? (???????? -=)
	//????????? ???????????? ?????? ?????????????? ?????????

	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 += pt1;
		pt2 += 1;
		Point pt3(3, 3);
		pt2 += pt1 += pt3;
		pt2 -= pt1 -= pt3;
		stop
	}

	//??????? 2c. ??????????? ???????? +/- 
	//a)? ??????? ??????? ?????? (???????? +)
	//?) ? ???????  ?????????? ??????? (???????? -)
	//???, ????? ????? ?? ?????????????????? ?????
	//???? ??????????? ?????????
	Point pt1(1,1);
	Point pt2(2,2);
	Point pt3;

	pt3 = pt1 + 5;
	pt3 = 2 + pt1;
	pt3 = pt1 + pt2;

	pt3 = pt1 - 5;
	pt3 = pt1 - pt2;
	stop

	//??????? 1d. ??????????? ??????? ???????? +/- 
	pt3 = -pt1;
	pt3 = +pt1;


	//??????? 2d. ??????????? ???????? << (?????? ? ?????) ???
	//?????? MyString ????? ???????, ????? ??? ?????????? ??????????? ??????
	//?? ????? ???? ????????:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	cout << s <<endl;


	stop
	//??????? 2e*. ??????????? ????????? + ? += ??? ?????? MyString ????? ???????,
	//????? ??????????? ???????????? ?????

	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1 + s2;
	s4 += s1; 
	stop

	//??????? 3. ??????????? "???? ??????" ? ??????????? ??????????? ??????????????
	//???????. ?????? ???????? ??????? (???? ? ??????? ????????, ??????? ?????????? ????????
	//? ???? ???? ?? ?????), ? ???????: ???, ???????, ?????????, ????????...
	//??????????:
	//?????????? ??????????? ? ????
	//??????????
	//????? ?????????? ? ?????????? ??????????
	//????? ???? (??? ????????????) ?????????? ? ???? ???????????
	//????????:	

	Base bd;												//???????? ?????? ????
	bd["Ivanov"] = MyData(MALE, 30, "injeneer", 100);		//???? Ivanov-? ? ???? ??? ???, ?? ??????????, ???? ??? ????, ?? ?????? ??? ??????????
	bd["Petrov"] = MyData(MALE, 35, "programmer", 150);
	bd["Sidorova"] = MyData(MALE, 40, "hr", 50);
	bd["Kovalenko"] = MyData(MALE, 40, "programmer", 200);
	cout << bd;												//????? ?????????? ??? ???? ???????????

	bd.DeletePair("Petrov");								// ????????? ??????????

	cout << bd["Ivanov"];									// ????? ?????????? ? ??????????		
	cout << bd;

	Base bd2 = bd;			// ??????????? ???????????
	bd = bd2;				// ???????? ?????????????

	Base bd3 = move(bd);	// ???????????? ??????????? ???????????
	bd = move(bd3);			// ???????????? ???????? ????????????

	return 0;
}//endmain

