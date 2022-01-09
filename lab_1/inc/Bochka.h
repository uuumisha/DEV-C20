class Bochka {
private:
	double m_spirt;
	double m_all;
public:
	Bochka(double spirt, double all);
	void Pereliv(Bochka &b, double cup_mass);
	double GetConc() const;
	void Substract(double delta);
};