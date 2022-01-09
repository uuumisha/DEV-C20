#pragma once

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
};

MyString Concatenation(const char* str, ...);