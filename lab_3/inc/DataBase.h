#pragma once

#include "myString.h"
enum Sex { UNDEF, MALE, FMALE };

class MyData {
	Sex m_sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public:
	MyData();
	MyData(Sex s, size_t age, const char* job, float sal);

	friend ostream& operator<<(ostream& os, const MyData& d);
};

class Pair {
	MyString m_key;
	MyData m_data;

	Pair();
	Pair(const char* k, const MyData& d);

	bool operator==(const char* k) const;

	friend class Base;
	friend ostream& operator<<(ostream& os, const Pair& pair);
};

class Base {
	Pair *m_pBase;
	size_t m_count;
	size_t m_capacity;
public:
	Base();
	~Base();

	Base(const Base& bd);
	Base& operator=(const Base& bd);
	void DeletePair(const char* str);
	Base(Base&& bd);
	Base& operator=(Base&& bd);

	MyData& operator[](const char* key);
	friend ostream& operator<<(ostream& os, const Base& bd);
};

ostream& operator<<(ostream& os, const MyData& d);
ostream& operator<<(ostream& os, const Pair& pair);
ostream& operator<<(ostream& os, const Base& bd);