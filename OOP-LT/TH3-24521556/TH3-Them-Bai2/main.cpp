#include "HCN.h"
#include <iostream>
using namespace std;

int main() {
    HCN h1;
    cout << "Nhap hinh chu nhat:\n";
    h1.Nhap();

    cout << "\n== Thong tin HCN ==\n";
    h1.Xuat();
    cout << "\nChu vi: " << h1.TinhChuVi();
    cout << ", Dien tich: " << h1.TinhDienTich();
    cout << "\nHop le: " << (h1.KiemTraHopLe() ? "Co" : "Khong") << endl;

    h1.DiChuyen(2, -1);
    cout << "\nSau khi di chuyen (dx=2, dy=-1): ";
    h1.Xuat();
    cout << endl;

    cout << "\nSo HCN da tao: " << HCN::getSoLuongHCN() << endl;

    return 0;
}
