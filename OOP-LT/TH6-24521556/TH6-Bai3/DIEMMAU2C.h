#pragma once
#ifndef _DIEMMAU2C
#define _DIEMMAU2C

#include "DIEM2C.h"
#include "MAU.h"

class DIEMMAU2C :public DIEM2C, public MAU
{
private:
	static int dem;
public:
	~DIEMMAU2C();
	DIEMMAU2C(double = 0, double = 0, int = 0, int = 0, int = 0);
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEMMAU2C&) const;
	friend istream& operator >> (istream&, DIEMMAU2C&);
	friend ostream& operator << (ostream&, const DIEMMAU2C&);


};

#endif // !_DIEMMAU2C
