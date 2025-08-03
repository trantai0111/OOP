// Cài đặt lớp VeTronGoi
#include "VeTronGoi.h"
#include <iostream>
using namespace std;

void VeTronGoi::nhap() {
    Ve::nhap();
}

void VeTronGoi::xuat() const {
    Ve::xuat();
    cout << "Loai ve: Tron Goi, Tien: " << tinhTien() << endl;
}

int VeTronGoi::tinhTien() const {
    return 200000;
}