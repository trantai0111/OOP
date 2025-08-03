#pragma once
#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;
class Diem;
class cDaGiac:public Diem{
private:
	vector<Diem> Dinh;
public:
	cDaGiac();
	cDaGiac(int SoDinh);
	~cDaGiac();
	void Nhap();
	void Xuat()const;
	string KiemTraLoai()const;
	double TinhChuVi()const;
	double TinhDienTich()const;
	void TinhTien(double x,double y);
	void PhongTo(double scale);
	void ThuNho(double scale);
	void Quay(const Diem&A,int alpha);
};
