class Hex {
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;
	void Show() const;
	void ShowPos(int pos) const;
	void Edit(int pos, int val);
	friend union MyByte;
};

class Dec {
	unsigned char m_dec;
	void Show() const;
	friend union MyByte;
};

class Oct {
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;
	void Show() const;
	void ShowPos(int pos) const;
	void Edit(int pos, int val);
	friend union MyByte;
};

class Bin {
	bool m_bin0 : 1;
	bool m_bin1 : 1;
	bool m_bin2 : 1;
	bool m_bin3 : 1;
	bool m_bin4 : 1;
	bool m_bin5 : 1;
	bool m_bin6 : 1;
	bool m_bin7 : 1;
	void Show() const;
	void ShowPos(int pos) const;
	void Edit(int pos, int val);
	friend union MyByte;
};

 union MyByte {
 private:
	 Hex m_hex;
	 Dec m_dec;
	 Oct m_oct;
	 Bin m_bin;
	 unsigned char m_val;
 public:
	 MyByte(unsigned char val);
	 void ShowHex() const { m_hex.Show(); }
	 void ShowDec() const { m_dec.Show(); }
	 void ShowOct() const { m_oct.Show(); }
	 void ShowBin() const { m_bin.Show(); }
	 void ShowHexPos(int pos) const { m_hex.ShowPos(pos); }
	 void ShowOctPos(int pos) const { m_oct.ShowPos(pos); }
	 void ShowBinPos(int pos) const { m_bin.ShowPos(pos); }
	 void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
	 void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
	 void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
};


