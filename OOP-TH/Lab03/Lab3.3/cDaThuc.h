#pragma once
#include <bits/stdc++.h>
using namespace std;
class cDaThuc{
private:
	int Bac;
	vector<double> HeSo;
public:
	cDaThuc();
	cDaThuc(int n);
	void Nhap();
	void Xuat()const;
	double TinhGiaTri(double x)const;
	cDaThuc Cong(const cDaThuc& other)const;
	cDaThuc Tru(const cDaThuc& other)const;
};
