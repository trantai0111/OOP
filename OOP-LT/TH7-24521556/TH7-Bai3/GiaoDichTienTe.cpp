#include "GiaoDichTienTe.h"
#include <iostream>
using namespace std;

void GiaoDichTienTe::Nhap() {
    GiaoDich::Nhap();
    cout << "Nhap loai tien (VN/USD/EURO): ";
    getline(cin, loaiTien);
    cout << "Nhap ti gia: "; cin >> tiGia;
    cin.ignore();
}

void GiaoDichTienTe::Xuat() const {
    GiaoDich::Xuat();
    cout << ", Loai tien: " << loaiTien
        << ", Ti gia: " << tiGia
        << ", Thanh tien: " << ThanhTien() << endl;
}

double GiaoDichTienTe::ThanhTien() const {
    if (loaiTien == "USD" || loaiTien == "EURO")
        return soLuong * donGia * tiGia;
    return soLuong * donGia;
}

string GiaoDichTienTe::getLoaiTien() const {
    return loaiTien;
}
