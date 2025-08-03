#include "HTron.h"
#include <iostream>
using namespace std;

int main() {
    HTRON h1, h2;
    cout << "Nhap hinh tron h1:\n";
    h1.Nhap();

    cout << "\nNhap hinh tron h2:\n";
    h2.Nhap();

    cout << "\n== Thong tin cac hinh tron ==\n";
    cout << "Hinh tron h1: ";
    h1.Xuat();
    cout << "\nChu vi: " << h1.TinhChuVi();
    cout << ", Dien tich: " << h1.TinhDienTich();
    cout << "\nHop le: " << (h1.KiemTraHopLe() ? "Co" : "Khong") << endl;

    cout << "\nHinh tron h2: ";
    h2.Xuat();
    cout << "\nChu vi: " << h2.TinhChuVi();
    cout << ", Dien tich: " << h2.TinhDienTich();
    cout << "\nHop le: " << (h2.KiemTraHopLe() ? "Co" : "Khong") << endl;

    cout << "\nSo hinh tron da tao: " << HTRON::getSoLuongHinhTron() << endl;

    return 0;
}
