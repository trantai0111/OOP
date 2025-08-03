#include "LapTrinhVien.h"
#include <iostream>
using namespace std;

void LapTrinhVien::nhap() {
    NhanVien::nhap();
    cout << "So gio lam them: ";
    cin >> soGioLamThem; cin.ignore();
}

void LapTrinhVien::xuat() const {
    NhanVien::xuat();
    cout << "So gio lam them: " << soGioLamThem
         << ", Luong: " << tinhLuong() << endl;
}

double LapTrinhVien::tinhLuong() const {
    return luongCoBan + soGioLamThem * 200000;
}