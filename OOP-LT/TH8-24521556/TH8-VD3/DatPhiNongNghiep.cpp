// Cài đặt lớp DatPhiNongNghiep
#include "DatPhiNongNghiep.h"
#include <iostream>
using namespace std;

void DatPhiNongNghiep::nhap() {
    Dat::nhap();
}

void DatPhiNongNghiep::xuat() const {
    Dat::xuat();
}

float DatPhiNongNghiep::tinhThue() const {
    return dienTich * donGiaThue;
}