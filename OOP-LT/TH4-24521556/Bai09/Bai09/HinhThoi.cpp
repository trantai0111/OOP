#include "HinhThoi.h"

#include <iostream>

using namespace std;

void CHinhThoi::Nhap()
{
    cout << "Nhap canh hinh thoi a = ";
    cin >> a;
    cout << "Nhap duong cheo thu nhat d1 = ";
    cin >> d1;
    cout << "Nhap duong cheo thu hai d2 = ";
    cin >> d2;
}
void CHinhThoi::Xuat()
{
    cout << "Hinh thoi - canh: a = " << a << ", d1 = " << d1 << ", d2 = " << d2 << endl;
}
float CHinhThoi::TinhChuVi()
{
    return 4 * a;
}
float CHinhThoi::TinhDienTich()
{
    return 0.5 * d1 * d2;
}