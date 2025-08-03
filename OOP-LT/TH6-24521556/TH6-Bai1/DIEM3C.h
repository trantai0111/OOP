#pragma once
#ifndef _DIEM3C
#define _DIEM3C

#include "DIEM2C.h"

class DIEM3C : public DIEM2C {
protected:
	double z;
	static int dem;
public:
	DIEM3C(double = 0, double = 0, double = 0);
	DIEM3C(const DIEM3C&);
	~DIEM3C();

	static int GetDem();
	void operator = (const DIEM3C&);

	double GetZ() const;
	void SetZ(double);
	void Tinh_tien(double = 0, double = 0, double = 0);
	bool KiemTraTrungNhau(const DIEM3C&) const;
	double TinhKhoangCach(const DIEM3C&) const;
	DIEM3C TimDoiXung() const;
	bool KiemTraTamGiacHopLe(const DIEM3C&, const DIEM3C&) const;
	double TinhChuViTamGiac(const DIEM3C&, const DIEM3C&) const;
	double TinhDienTichTamGiac(const DIEM3C&, const DIEM3C&) const;
	string PhanLoaiTamGiac(const DIEM3C&, const DIEM3C&) const;

	void Nhap();
	void Xuat() const;
	friend istream& operator >> (istream& is, DIEM3C& d);
	friend ostream& operator << (ostream& os, const DIEM3C& d);


};





#endif