#include"SoPhuc.h"

int main() {
    SoPhuc sp1, sp2, kq;

    cout << "Nhap so phuc thu nhat:\n";
    sp1.Nhap();
    cout << "Nhap so phuc thu hai:\n";
    sp2.Nhap();

    cout << "\nSo phuc 1: ";
    sp1.Xuat();
    cout << "So phuc 2: ";
    sp2.Xuat();

    kq = sp1.Tong(sp2);
    cout << "\nTong: ";
    kq.Xuat();

    kq = sp1.Hieu(sp2);
    cout << "Hieu: ";
    kq.Xuat();

    kq = sp1.Tich(sp2);
    cout << "Tich: ";
    kq.Xuat();

    kq = sp1.Thuong(sp2);
    cout << "Thuong: ";
    kq.Xuat();

    return 0;
}

