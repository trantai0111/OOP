#include "SachThamKhao.h"
#include <iostream>
using namespace std;

void SachThamKhao::Nhap() {
    Sach::Nhap();
    cout << "Nhap thue: ";
    cin >> thue;
    cin.ignore();
}

void SachThamKhao::Xuat() const {
    Sach::Xuat();
    cout << ", Thue: " << thue
        << ", Thanh tien: " << ThanhTien() << endl;
}

double SachThamKhao::ThanhTien() const {
    return soLuong * donGia + thue;
}

double SachThamKhao::getDonGia() const {
    return donGia;
}
