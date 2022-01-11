// Темы:
// Двусвязный список

#include <tchar.h>
#include <iostream>
#include "inc\Circle.h"
#include "inc\List.h"

#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//////////////////////////////////////////////////////////////////////
	Circle c1, c2(1,1,2), c3(2, 2, 3), c4(3, 3, 4);
	List l;
	l.AddToHead(c1);
	l.AddToHead(c2);
	l.AddToHead(c3);
	l.AddToHead(c4);
	l.AddToTail(c4);
	cout << l;

	List l1(l);
	cout << l1;


	l.Sort();
	cout << l;

	//l.DoEmpty();
	//l.Sort();
	//cout << l;

	List l2(l);

	unsigned cnt = l1.RemoveEveryOne(c4);
	cout << cnt << " elements was removed from list" << endl;
	cout << l1;
	l1.Sort();
	cout << l1;

	//l = l1;
	cout << l;

	l1.WriteList();
	List l_read;
	l_read.ReadList();
	cout << l_read;

	return 0;
}
