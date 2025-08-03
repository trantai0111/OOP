#include "SachGiaoKhoa.h"
#include <iostream>
using namespace std;

void SachGiaoKhoa::Nhap() {
    Sach::Nhap();
    cout << "Nhap tinh trang (moi/cu): ";
    getline(cin, tinhTrang);
}

void SachGiaoKhoa::Xuat() const {
    Sach::Xuat();
    cout << ", Tinh trang: " << tinhTrang
        << ", Thanh tien: " << ThanhTien() << endl;
}

double SachGiaoKhoa::ThanhTien() const {
    if (tinhTrang == "moi")
        return soLuong * donGia;
    else
        return soLuong * donGia * 0.5;
}
