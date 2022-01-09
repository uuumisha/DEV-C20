#include "inc/counter.h"

#include <iostream>

Counter Counter::Head;
unsigned Counter::m_curCounters = 0;

Counter::Counter() {
	pNext = nullptr;
	m_pStr = nullptr;
	m_nOwners = 0;
}

Counter::Counter(const char* str) {
	pNext = Head.pNext;
	Head.pNext = this;
	m_curCounters++;
	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);
	m_nOwners = 1;
}

Counter::~Counter() {
	Counter* ptr = &Head;
	for (unsigned i = 0; i < m_curCounters; i++) {
		if (ptr->pNext == this) {
			m_curCounters--;
			ptr->pNext = pNext;
			delete[] m_pStr;
			return;
		}
		ptr = ptr->pNext;
	}
}


Counter* Counter::CreateOrFind(const char* str) {
	Counter* ptr = Head.pNext;
	for (unsigned i = 0; i < m_curCounters; i++) {
		if (!strcmp(ptr->m_pStr, str)) {
			ptr->m_nOwners++;
			return ptr;
		}
		ptr = ptr->pNext;
	}
	
	ptr = new Counter(str);
	return ptr;
}

void Counter::AddUser() {
	m_nOwners++;
}

void Counter::DeleteUser() {
	if (!(--m_nOwners))
		delete this;
}
