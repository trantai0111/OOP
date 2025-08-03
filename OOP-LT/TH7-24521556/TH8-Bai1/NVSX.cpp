#include "NVSX.h"
#include <iostream>
using namespace std;

void NVSX::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongcb;
    cout << "Nhap so san pham: ";
    cin >> soSP;
    cin.ignore();
}

void NVSX::Xuat() {
    NhanVien::Xuat();
    cout << ", Luong can ban: " << luongcb << ", So san pham: " << soSP
         << ", Luong: " << TinhLuong() << endl;
}

long NVSX::TinhLuong() {
    return luongcb + soSP * 5000;
}
