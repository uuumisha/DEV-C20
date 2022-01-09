#include "inc/Bochka.h"

Bochka::Bochka(double spirt, double all) {
	m_spirt = spirt;
	m_all = all;
}

double Bochka::GetConc() const {
	return (m_spirt / m_all );
}

void Bochka::Pereliv(Bochka &b, double cup_mass = 0) {
	m_all += cup_mass;
	m_spirt += b.GetConc() * cup_mass;
	b.Substract(cup_mass);
}

void Bochka::Substract(double delta) {
	m_spirt -= delta * GetConc();
	m_all -= delta;
}