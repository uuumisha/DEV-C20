#include "inc\List.h"
#include <fstream>

List::List() : m_size(0) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List() {
	while (Tail.pPrev != &Head) {
		delete Tail.pPrev;
	}
}

// конструктор копирования
List::List(const List& other) : m_size(other.m_size) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;

	for (size_t i = 0; i < m_size; i++) {
		pThis = new Node(pThis, &pOther->m_data);
		pOther = pOther->pNext;
	}
}

//move конструктор копирования
List::List(List&& other) : m_size(other.m_size) {
	if (other.m_size) {
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		m_size = other.m_size;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	else {
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
		
	}
}

void List::AddToHead(const Circle& c) {
	new Node(&Head, &c);
	m_size++;
}

void List::AddToTail(const Circle& c) {
	new Node(Tail.pPrev, &c);
	m_size++;
}

bool List::RemoveOne(const Circle &c) {
	Node *pn = Head.pNext;
	while (pn != &Tail) {
		if (pn->m_data == c) {
			m_size--;
			delete pn;
			return true;
		}
		pn = pn->pNext;
	}
	return false;
}

unsigned List::RemoveEveryOne(const Circle &c) {
	unsigned cnt = 0;
	Node* pn = Head.pNext;
	while (pn != &Tail) {
		Node* p = pn->pNext;
		if (pn->m_data == c) {
			m_size--;
		
			delete pn;
			cnt++;
		}
		
			pn = p;
	}

	return cnt;
}

void List::DoEmpty() {
	Node *pn = Head.pNext;
	while (pn != &Tail) {
		delete pn;
		pn = Head.pNext;
	}
	m_size = 0;
}

void List::Sort() {
	if (m_size) {
		Node *pn;
		Node *end = &Tail;
		for (size_t i = 0; i < m_size - 1; i++) {
			pn = Head.pNext;
			while (pn->pNext != end) {
				if (pn->m_data.GetArea() > pn->pNext->m_data.GetArea()) {

					pn->pPrev->pNext = pn->pNext;
					pn->pNext->pNext->pPrev = pn;

					Node* buff1 = pn->pPrev;
					Node* buff2 = pn->pNext;

					pn->pPrev = pn->pNext;
					pn->pNext = pn->pNext->pNext;

					buff2->pNext = pn;
					buff2->pPrev = buff1;
				}
				else
					pn = pn->pNext;
			}
			end = end->pPrev;
		}
	}
}

void List::SortByChoise() {
	//if (m_size) {
	//	Node *min;
	//	Node *start = Head.pNext;
	//	Node *pn = start->pNext;
	//	for (size_t i = 0; i < m_size; i++) {
	//		min = start;
	//		while (pn->pNext != &Tail) {
	//			if (pn->m_data.GetArea() < min->m_data.GetArea()) {

	//				pn->pPrev->pNext = pn->pNext;
	//				pn->pNext->pNext->pPrev = pn;

	//				Node* buff1 = pn->pPrev;
	//				Node* buff2 = pn->pNext;

	//				pn->pPrev = pn->pNext;
	//				pn->pNext = pn->pNext->pNext;

	//				buff2->pNext = pn;
	//				buff2->pPrev = buff1;
	//			}
	//			else
	//				pn = pn->pNext;
	//		}
	//	}
	//}
}

// оператор присваивания
List& List::operator=(const List& other) {
	if (this != &other) {
		Node *po, *pt;
		size_t m;
		if (m_size < other.m_size)
			m = m_size;
		else
			m = other.m_size;
		

		po = other.Head.pNext;
		pt = Head.pNext;
		for (size_t i = 0; i < m; i++) {
			pt->m_data = po->m_data;
			pt = pt->pNext;
			po = po->pNext;
		}

		if (m_size < other.m_size) {
			for (size_t i = 0; i < other.m_size - m_size; i++) {
				new Node(Tail.pPrev, &po->m_data);
				po = po->pNext;
			}
		}
		else {
			for (size_t i = 0; i < m_size - other.m_size; i++) {
				delete Tail.pPrev;
			}
		}
	}

	m_size = other.m_size;
	return *this;
}

//move  оператор присваивания
List& List::operator=(List&& other) {

	if (this != &other) {
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		m_size = other.m_size;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
	os << "I'm a list with " << list.m_size << " elements: " << endl;
	Node *pn = list.Head.pNext;
	while (pn != &list.Tail) {
		os << pn->m_data;
		pn = pn->pNext;
	}
	return os;
}

// Записать список в файл
void List::WriteList() const {
	cout << "Enter Output File Name  - ";
	char name[80];
	cin >> name;
	ofstream fout(name);
	fout << *this;
	fout << "End";
	fout.close();
}

// Считать список из файла
void List::ReadList() {
	cout << "Enter Input File Name  - ";
	char name[80], str[80];
	int size, radius;
	int x,y;
	char ch;

	cin >> name;
	ifstream fin(name);
	Node* p = &Head;

	if (!fin.is_open()) {
		cout << "Unable to open file" << endl;
		return;
	}

	// считываем размер списка
	while (strcmp("with", str)) {
		fin >> str;
	}
	fin >> size;

	if (size) {
		while (true) {
			str[0] = 0;
			while (strcmp("radius", str)) {
				fin >> str;
			}

			fin >> radius;

			ch = 0;
			while (fin.get() != '(');
			fin >> x;
			fin >> y;
			
			AddToTail(Circle(x, y, radius));
			fin >> str;
			fin >> str;
			if (!strcmp(str, "End"))
				break;
		}
	}
	
	return;
}
