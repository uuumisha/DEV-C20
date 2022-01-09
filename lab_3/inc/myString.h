#pragma once
#include <iostream>
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
ostream& operator<<(std::ostream &os, const MyString& str);