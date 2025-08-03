#include "HinhVuong.h"
#include <iostream>

using namespace std;

void CHinhVuong::Nhap()
{
	cout << "Nhap canh a: ";
	cin >> a;
}
void CHinhVuong::Xuat()
{
	cout << "Hinh vuong co canh: " << a << endl;
}
float CHinhVuong::TinhChuVi()
{
	return 4 * a;
}
float CHinhVuong::TinhDienTich()
{
	return a * a;
}