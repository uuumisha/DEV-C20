#pragma once

class Counter {
	Counter *pNext;
	char *m_pStr;
	unsigned m_nOwners;

	static Counter Head;
	static unsigned m_curCounters;
	static Counter* CreateOrFind(const char* str);
	void AddUser();
	void DeleteUser();

	friend class MyString;

	Counter();
	Counter(const char* str);
	~Counter();
};