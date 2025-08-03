#include "KiemChungVien.h"
#include <iostream>
using namespace std;

void KiemChungVien::nhap() {
    NhanVien::nhap();
    cout << "So loi phat hien: ";
    cin >> soLoiPhatHien; cin.ignore();
}

void KiemChungVien::xuat() const {
    NhanVien::xuat();
    cout << "So loi phat hien: " << soLoiPhatHien
         << ", Luong: " << tinhLuong() << endl;
}

double KiemChungVien::tinhLuong() const {
    return luongCoBan + soLoiPhatHien * 50000;
}