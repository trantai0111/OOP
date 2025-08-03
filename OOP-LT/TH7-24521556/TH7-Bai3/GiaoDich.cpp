#include "GiaoDich.h"

GiaoDich::GiaoDich() : maGD(""), ngayGD(""), donGia(0), soLuong(0) {}

void GiaoDich::Nhap() {
    cout << "Nhap ma giao dich: "; getline(cin, maGD);
    cout << "Nhap ngay giao dich: "; getline(cin, ngayGD);
    cout << "Nhap don gia: "; cin >> donGia;
    cout << "Nhap so luong: "; cin >> soLuong;
    cin.ignore();
}

void GiaoDich::Xuat() const {
    cout << "Ma GD: " << maGD << ", Ngay: " << ngayGD
        << ", Don gia: " << donGia << ", So luong: " << soLuong;
}

string GiaoDich::getMaGD() const {
    return maGD;
}

double GiaoDich::getDonGia() const {
    return donGia;
}