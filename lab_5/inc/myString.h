#pragma once

#include "counter.h"

class MyString
{
	Counter *m_pCounter;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other);
	~MyString();

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);

	static void ShowAllStrings();
	static void ChangeReg();
	static void ShowAllStringsInOrder();
	static void SortStrings();
};


/*#include <iostream>
using namespace std;

class MyString
{
    char* m_pStr;	// 
public:
	MyString();
	MyString(const char *str);
	MyString(const MyString &other);
	MyString(MyString&& tmp);

	~MyString();
	const char* GetString() const;
	void SetNewString(const char* str);
	MyString& operator = (const MyString& str);
	MyString& operator = (const char *str);
	MyString operator +(const MyString& str) const;
	MyString& operator +=(const MyString& str);
	MyString& operator = (MyString&& str);
};

MyString Concatenation(const char* str, ...);
ostream& operator<<(std::ostream &os, const MyString& str);*/
