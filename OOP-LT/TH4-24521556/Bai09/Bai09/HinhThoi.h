#pragma once
#include"TuGiac.h"
#include<iostream>
using namespace std;

class CHinhThoi:public CTuGiac
{
private:
	float d1, d2;
public:
	void Nhap();
	void Xuat();
	float TinhChuVi();
	float TinhDienTich();
};

