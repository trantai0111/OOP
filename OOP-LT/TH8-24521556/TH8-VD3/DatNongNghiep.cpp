// Cài đặt lớp DatNongNghiep
#include "DatNongNghiep.h"
#include <iostream>
using namespace std;

void DatNongNghiep::nhap() {
    Dat::nhap();
    cout << "Nhap nam su dung: "; cin >> namSuDung; cin.ignore();
}

void DatNongNghiep::xuat() const {
    Dat::xuat();
    cout << "Nam su dung: " << namSuDung << endl;
}

float DatNongNghiep::tinhThue() const {
    return dienTich * donGiaThue;
}

bool DatNongNghiep::hetHan(int namHienTai) const {
    return namSuDung < namHienTai;
}