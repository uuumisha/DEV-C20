#include <string>
#include <iostream>
#include "inc/myString.h"
using namespace std;

// Определение конструктора.
MyString::MyString(const char *str) {
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else
		m_pStr = nullptr;
}

// Определение деструктора.
MyString::~MyString() {
	delete[] m_pStr;
}

// Определение конструктора копирования
MyString::MyString(const MyString &other) {
	if (other.m_pStr) {
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy(m_pStr, other.m_pStr);
	}
	else
		m_pStr = nullptr;
}

// Получить строку из класса
const char* MyString::GetString() const {
	if (m_pStr)
		return m_pStr;
	else
		return "Error\n";
}

// Замена строки на новую
void MyString::SetNewString(const char* str) {
	delete[] m_pStr;
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else
		m_pStr = nullptr;
}