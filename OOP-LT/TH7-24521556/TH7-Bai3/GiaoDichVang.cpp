#include "GiaoDichVang.h"

void GiaoDichVang::Nhap() {
    GiaoDich::Nhap();
    cout << "Nhap loai vang: ";
    getline(cin, loaiVang);
}

void GiaoDichVang::Xuat() const {
    GiaoDich::Xuat();
    cout << ", Loai vang: " << loaiVang
        << ", Thanh tien: " << ThanhTien() << endl;
}

double GiaoDichVang::ThanhTien() const {
    return soLuong * donGia;
}
