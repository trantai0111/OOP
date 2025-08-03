#pragma once
#ifndef _DIEM2C
#define _DIEM2C

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>  // Thư viện chứa rand() và srand()
#include <ctime>    // Thư viện chứa time()
#include <iomanip>

using namespace std;


class DIEM2C {
protected: 
	double x, y;
	static int dem;
public:
	DIEM2C(double = 0, double = 0);
	DIEM2C(const DIEM2C&);
	~DIEM2C();
	
	static int GetDem();
	void operator = (const DIEM2C&);

	double GetX() const;
	double GetY() const;
	void SetX(double);
	void SetY(double);
	void SetXY(double, double);
	void Tinh_tien(double, double);
	bool KiemTraTrungNhau(const DIEM2C&) const;
	double TinhKhoangCach(const DIEM2C&) const;
	DIEM2C TimDoiXung() const;
	bool KiemTraTamGiacHopLe(const DIEM2C&, const DIEM2C&) const;
	double TinhChuViTamGiac(const DIEM2C&, const DIEM2C&) const;
	double TinhDienTichTamGiac(const DIEM2C&, const DIEM2C&) const;
	string PhanLoaiTamGiac(const DIEM2C&, const DIEM2C&) const;

	void Nhap();
	void Xuat() const;
	friend istream& operator >> (istream& is, DIEM2C& d);
	friend ostream& operator << (ostream& os, const DIEM2C& d);


};





#endif