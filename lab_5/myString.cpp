#include "inc\myString.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// конструктор по умолчанию 
MyString::MyString() {
	m_pCounter = nullptr;
}

// конструктор с параметрами
MyString::MyString(const char* str) {
	if (str != nullptr)
		m_pCounter = Counter::CreateOrFind(str);
	else
		m_pCounter = nullptr;
}

// конструктор копирования
MyString::MyString(const MyString& other) {
	m_pCounter = other.m_pCounter;
	other.m_pCounter->AddUser();
}

// move конструктор копирования
MyString::MyString(MyString&& other) {
	m_pCounter = other.m_pCounter;
	other.m_pCounter = nullptr;
}

// оператор присваивания
MyString& MyString::operator=(const MyString& other) {
	if (this == &other)
		return *this;
	else {
		m_pCounter->DeleteUser();
		m_pCounter = other.m_pCounter;
		m_pCounter->AddUser();
		return *this;
	}
}

// move оператор присваивания
MyString& MyString::operator=(MyString&& other) {
	m_pCounter = other.m_pCounter;
	return *this;
}

// деструктор
MyString::~MyString() {
	if(m_pCounter)
		m_pCounter->DeleteUser();
}

// ----------------------- Статические методы класса -------------------------------

// вывести все строки
void MyString::ShowAllStrings() {
	Counter* ptr = &Counter::Head;
	std::cout << "Show all " << Counter::m_curCounters << " strings:" << std::endl;
	for (unsigned i = 0; i < Counter::m_curCounters; i++) {
		std::cout << ptr->pNext->m_pStr << std::endl;
		ptr = ptr->pNext;
	}
}

// изменить регистр всех строк
void MyString::ChangeReg() {
	Counter* ptr = &Counter::Head;
	std::cout << "Change register of all strings" << std::endl;
	for (unsigned i = 0; i < Counter::m_curCounters; i++) {
		int j = 0;
		while (ptr->pNext->m_pStr[j]) {
			if (std::isupper(ptr->pNext->m_pStr[j]))
				ptr->pNext->m_pStr[j] = std::tolower(ptr->pNext->m_pStr[j]);
			else
				ptr->pNext->m_pStr[j] = std::toupper(ptr->pNext->m_pStr[j]);
			j++;
		}
		ptr = ptr->pNext;
	}
}

// вывести все строки в алфавитном порядке
void MyString::ShowAllStringsInOrder() {
	Counter* ptr = &Counter::Head;
	std::cout << "Show all " << Counter::m_curCounters << " strings:" << std::endl;
	for (unsigned i = 0; i < Counter::m_curCounters; i++) {
		std::cout << ptr->pNext->m_pStr << std::endl;
		ptr = ptr->pNext;
	}
}

// сортировка выбором строк в алфавитном порядке 
void MyString::SortStrings() {
	Counter FHEAD;							// фиктивная голова
	Counter* fptr = &FHEAD;					// указатель для записи строк в новом порядке
	Counter* ptr;							// указатель для пробега по строкам
	Counter* min;							// текущий минимум
	Counter* minpPrev;						// указатель на counter, предшествующий минимуму

	while (Counter::Head.pNext->pNext != nullptr) {
		ptr = Counter::Head.pNext;
		minpPrev = &Counter::Head;
		min = ptr;
		while (ptr->pNext != nullptr) {
			if (min->m_pStr[0] > ptr->pNext->m_pStr[0]) {
				minpPrev = ptr;
				min = ptr->pNext;
			}
			ptr = ptr->pNext;
		}
		fptr->pNext = min;
		fptr = min;
		minpPrev->pNext = min->pNext;
	}
	fptr->pNext = Counter::Head.pNext;
	Counter::Head.pNext = FHEAD.pNext;
	FHEAD.pNext = nullptr;
}
