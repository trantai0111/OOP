#include "Sach.h"
#include <iostream>
using namespace std;

void Sach::Nhap() {
    cout << "Nhap ma sach: "; getline(cin, maSach);
    cout << "Nhap ngay nhap: "; getline(cin, ngayNhap);
    cout << "Nhap don gia: "; cin >> donGia;
    cout << "Nhap so luong: "; cin >> soLuong;
    cin.ignore();
    cout << "Nhap nha xuat ban: "; getline(cin, nhaXuatBan);
}

void Sach::Xuat() const {
    cout << "Ma sach: " << maSach << ", Ngay nhap: " << ngayNhap
        << ", Don gia: " << donGia << ", So luong: " << soLuong
        << ", NXB: " << nhaXuatBan;
}

string Sach::getNhaXuatBan() const {
    return nhaXuatBan;
}
