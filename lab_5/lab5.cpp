// Темы:
// Статические члены класса.

#include <tchar.h>
#include <iostream>
#include "inc\myString.h"

#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//////////////////////////////////////////////////////////////////////

	/*char m1[] = "ABC";
	char m2[] = "DEF";
	if (m1[0] < m2[0])
		cout << m1;
	else
		cout << m2;

	MyString s1("1234");

	{
		MyString s2("qwerty");
		MyString::ShowAllStrings();
	}

	MyString s2("qwerty");

	MyString s3("ABC"), s4(s3);

	MyString s5 = std::move(s4);

	MyString::ShowAllStrings();

	MyString s6("Point");
	s6 = s5;

	MyString::ChangeReg();
	MyString::ShowAllStrings();*/

	MyString s1("ABC");
	MyString s2("DEF");
	MyString s3("QRS");
	MyString s4("XYZ");
	MyString s5("YXZ");
	MyString s6(s5);

	MyString::ShowAllStrings();
	MyString::SortStrings();
	MyString::ShowAllStrings();
	return 0;
}//endmain

