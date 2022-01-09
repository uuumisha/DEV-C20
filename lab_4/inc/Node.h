#pragma once

#include "Circle.h"

class Node {
	Node* pNext;
	Node* pPrev;
	Circle m_data;

	friend class List;
	friend std::ostream& operator<<(std::ostream& os, const List& list);

	Node();
	Node(const Circle* pc);
	Node(Node* n, const Circle* c);
	~Node();
};