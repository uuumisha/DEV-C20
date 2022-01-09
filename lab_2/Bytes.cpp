#include "inc\Bytes.h"
#include <iostream>

MyByte::MyByte(unsigned char val) {
	m_val = val;
}

void Hex::Show() const {
	std::cout << std::hex << static_cast<int>(m_hex1) << static_cast<int>(m_hex0) << std::endl;
}

void Dec::Show() const {
	std::cout << std::dec << static_cast<int>(m_dec) << std::endl;
}

void Oct::Show() const {
	std::cout << std::dec << static_cast<int>(m_oct2) << static_cast<int>(m_oct1) << static_cast<int>(m_oct0) << std::endl;
}

void Bin::Show() const {
	std::cout << m_bin7 << m_bin6 << m_bin5 << m_bin4 << m_bin3 << m_bin2 << m_bin1 << m_bin0 << std::endl;
}

void Hex::ShowPos(int pos) const {
	switch (pos) {
	case 0:
		std::cout << std::hex << static_cast<int>(m_hex1) << std::endl;
		break;
	case 1:
		std::cout << std::hex << static_cast<int>(m_hex0) << std::endl;
		break;
	default:
		std::cout << "Hex wrong position" << std::endl;
		break;
	}
}

void Oct::ShowPos(int pos) const {
	switch (pos) {
	case 0:
		std::cout << std::dec << static_cast<int>(m_oct2) << std::endl;
		break;
	case 1:
		std::cout << std::dec << static_cast<int>(m_oct1) << std::endl;
		break;
	case 2:
		std::cout << std::dec << static_cast<int>(m_oct0) << std::endl;
		break;
	default:
		std::cout << "Oct wrong position" << std::endl;
		break;
	}
}

void Bin::ShowPos(int pos) const {
	if ((pos > 7) || (pos < 0)) {
		std::cout << "Oct wrong position" << std::endl;
		return;
	}

	bool tmp[8] = { m_bin7 ,  m_bin6 , m_bin5 , m_bin4 , m_bin3 , m_bin2 , m_bin1 , m_bin0 };
	std::cout << tmp[pos] << std::endl;
}

void Hex::Edit(int pos, int val) {
	switch (pos) {
	case 0:
		m_hex1 = val;
		break;
	case 1:
		m_hex0 = val;
		break;
	default:
		std::cout << "Hex wrong position" << std::endl;
		break;
	}
}

void Oct::Edit(int pos, int val) {
	switch (pos) {
	case 0:
		m_oct2 = val;
		break;
	case 1:
		m_oct1 = val;
		break;
	case 2:
		std::cout << std::dec << static_cast<int>(m_oct0) << std::endl;
		break;
	default:
		std::cout << "Oct wrong position" << std::endl;
		break;
	}
}

void Bin::Edit(int pos, int val) {

}