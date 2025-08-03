// Cài đặt lớp VeTungPhan
#include "VeTungPhan.h"
#include <iostream>
using namespace std;

void VeTungPhan::nhap() {
    Ve::nhap();
}

void VeTungPhan::xuat() const {
    Ve::xuat();
    cout << "Loai ve: Tung Phan, Tien: " << tinhTien() << endl;
}

int VeTungPhan::tinhTien() const {
    return 70000 + 20000 * soTroChoi;
}