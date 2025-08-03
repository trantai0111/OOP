#pragma once
#ifndef _DIEMMAU3C
#define _DIEMMAU3C

#include "DIEM3C.h"

class DIEMMAU3C :public DIEM3C
{
private:
	static int dem;
	int r, g, b;
public:
	~DIEMMAU3C();
	DIEMMAU3C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
	static int GetDem();
	DIEMMAU3C(const DIEMMAU3C&);
	int GetR() const;
	int GetG() const;
	int GetB() const;
	void SetR(int);
	void SetG(int);
	void SetB(int);
	void SetRGB(int = 0, int = 0, int = 0);

	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEMMAU3C&) const;
	friend istream& operator >> (istream&, DIEMMAU3C&);
	friend ostream& operator << (ostream&, const DIEMMAU3C&);


};

#endif // !_DIEMMAU3C
