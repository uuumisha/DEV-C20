#include "inc\DataBase.h"


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//--------------------------	Класс Base		------------------------------------
// Конструкторы
Base::Base() {
	m_pBase = new Pair[2];
	m_count = 0;
	m_capacity = 2;
}

// конструктор копирования 
Base::Base(const Base& bd) {
	m_pBase = new Pair[bd.m_count + 2];
	for (size_t i = 0; i < bd.m_count; i++)
		m_pBase[i] = bd.m_pBase[i];
	m_count = bd.m_count;
	m_capacity = bd.m_count + 2;

}

// Деструктор
Base::~Base() {
	delete[] m_pBase;
}

// Перемещающий конструктор копирования
Base::Base(Base&& bd) {
	m_pBase = bd.m_pBase;
	bd.m_pBase = nullptr;
	m_capacity = bd.m_capacity;
	m_count = bd.m_count;
	bd.m_count = bd.m_capacity = 0;
}

MyData& Base::operator[](const char* key) {
	
	// ищем сотрудника в базе
	for (size_t i = 0; i < m_count; i++) {
		if (m_pBase[i] == key)
			return m_pBase[i].m_data;
	}

	// если сотрудник не найден, добавляем

	// перераспределяем память
	if (m_count >= m_capacity) {
		Pair* tmp = new Pair[m_count+2];
		for (size_t i = 0; i < m_count; i++)
			tmp[i] = std::move(m_pBase[i]);

		delete[] m_pBase;
		m_pBase = tmp;
	}

	// добавляем сотрудника
	m_pBase[m_count].m_key = key;
	m_count++;
	return m_pBase[m_count-1].m_data;

}

void Base::DeletePair(const char* str) {
	// ищем сотрудника в базе
	for (size_t i = 0; i < m_count; i++) {
		if (m_pBase[i] == str) {
			m_pBase[i] = m_pBase[m_count - 1];
			m_count--;
			break;
		}
	}
}

// оператор присваивания
Base& Base::operator=(const Base& bd) {
	if (this != &bd) {
		if (m_capacity < bd.m_count) {
			delete[] m_pBase;
			m_pBase = new Pair[bd.m_count + 2];
			m_capacity = bd.m_count + 2;
		}
		m_count = bd.m_count;
		for (size_t i = 0; i < m_count; i++)
			m_pBase[i] = bd.m_pBase[i];
	}
	return *this;
}

// перемещающий оператор присваивания
Base& Base::operator=(Base&& bd) {
	if (this != &bd) {
		delete[] m_pBase;
		m_pBase = bd.m_pBase;
		bd.m_pBase = nullptr;
		m_capacity = bd.m_capacity;
		m_count = bd.m_count;
		bd.m_capacity = bd.m_count = 0;
	}
	return *this;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//--------------------------	Класс Pair		------------------------------------

Pair::Pair() {
	
}

Pair::Pair(const char* k, const MyData& d) : m_key(k), m_data(d) {

}

bool Pair::operator==(const char* k) const {
	if (!strcmp(m_key.GetString(), k))
		return 1;
	else
		return 0;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//--------------------------	Класс MyData		--------------------------------

// конструкторы
MyData::MyData(Sex s, size_t age, const char* job, float sal) : m_job(job) {
	m_sex = s;
	m_age = age;
	m_salary = sal;
}

MyData::MyData() : m_job("undef"){
	m_sex = MALE;
	m_age = 30;
	m_salary = 50;
}

//--------------------------	Глобальные операторы и функции		--------------------------------

ostream& operator<<(ostream& os, const MyData& d) {
	os << "Sex: " << d.m_sex << endl;
	os << "Age: " << d.m_age << endl;
	os << "Job: " << d.m_job << endl;
	os << "Salary: " << d.m_salary << endl;
	return os;
}

ostream& operator<<(ostream& os, const Pair& pair) {
	os << "----------------------------------------------------------------------\n";
	os << "Surname: " << pair.m_key << endl << pair.m_data;
	return os;
}

ostream& operator<<(ostream& os, const Base& bd) {
	os << "This is super database:\n";
	for (size_t i = 0; i < bd.m_count; i++)
		os << bd.m_pBase[i];
	os << "Thanks for using!\n\n";
	return os;
}
