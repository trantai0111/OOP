#pragma once
#ifndef _DIEM3CMAU
#define _DIEM3CMAU

#include "DIEM3C.h"
#include "MAU.h"

class DIEM3CMAU :public DIEM3C, public MAU
{
private:
	static int dem;
public:
	~DIEM3CMAU();
	DIEM3CMAU(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEM3CMAU&) const;
	friend istream& operator >> (istream&, DIEM3CMAU&);
	friend ostream& operator << (ostream&, const DIEM3CMAU&);


};

#endif // !_DIEM3CMAU
