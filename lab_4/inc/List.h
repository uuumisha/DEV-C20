#pragma once

#include "Node.h"
#include <iostream>

class List {
	Node Head, Tail;
	size_t m_size;
public:
	List();
	~List();

	List(const List& other);
	List(List&& other);

	void AddToHead(const Circle &c); 
	void AddToTail(const Circle &c);
	bool RemoveOne(const Circle &c);
	unsigned RemoveEveryOne(const Circle &c);
	void DoEmpty();
	void Sort();
	void SortByChoise();

	void WriteList() const;
	void ReadList();

	List& operator=(const List& other);
	List& operator=(List&& other);

	friend std::ostream& operator<<(std::ostream& os, const List& list);
};
