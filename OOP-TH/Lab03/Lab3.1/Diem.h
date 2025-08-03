#pragma once
#include <bits/stdc++.h>
using namespace std;
class Diem{
protected:
	double dx,dy;
public:
	Diem();
	Diem(double x,double y);
	Diem(const Diem&A);
	~Diem();
	void Nhap();
	void Xuat()const;
	double TinhKhoangCach(const Diem&A)const;
	void TinhTien(double x,double y);
	void PhongTo(double scale);
	void ThuNho(double scale);
	void Quay(const Diem&A,int alpha);
	friend class cDaGiac;
};
