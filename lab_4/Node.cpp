#include "inc\Node.h"

Node::Node() {
	pNext = nullptr;
	pPrev = nullptr;
}

Node::Node(const Circle* pc) {
	pNext = nullptr;
	pPrev = nullptr;
	m_data = *pc;
}

Node::Node(Node* n, const Circle* c) : m_data(*c) {
	pPrev = n;
	pNext = n->pNext;
	n->pNext = this; 
	pNext->pPrev = this;
}

Node::~Node() {
	if (pPrev) {
		pPrev->pNext = this->pNext;
	}

	if (pNext) {
		pNext->pPrev = this->pPrev;
	}
}