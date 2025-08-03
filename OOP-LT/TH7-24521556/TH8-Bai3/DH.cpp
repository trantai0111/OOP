#include "DH.h"
void DH::Nhap() {
    SinhVien::Nhap();
    cin.ignore();
    cout << "Nhap ten luan van: "; getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: "; cin >> diemLuanVan;
}

void DH::Xuat() {
    SinhVien::Xuat();
    cout << ", Ten luan van: " << tenLuanVan << ", Diem luan van: " << diemLuanVan << endl;
}

bool DH::TotNghiep() {
    return tongTinChi >= 170 && diemTB >= 5 && diemLuanVan >= 5;
}