#include "CD.h"
void CD::Nhap() {
    SinhVien::Nhap();
    cout << "Nhap diem thi tot nghiep: "; cin >> diemTotNghiep;
}

void CD::Xuat() {
    SinhVien::Xuat();
    cout << ", Diem tot nghiep: " << diemTotNghiep << endl;
}

bool CD::TotNghiep() {
    return tongTinChi >= 120 && diemTB >= 5 && diemTotNghiep >= 5;
}