#include"PhanSo.h"

int main() {
    PhanSo ps1, ps2, kq;

    cout << "Nhap phan so 1:\n";
    ps1.Nhap();
    cout << "Nhap phan so 2:\n";
    ps2.Nhap();

    cout << "Phan so 1: "; ps1.Xuat();
    cout << "Phan so 2: "; ps2.Xuat();

    kq = ps1.Tong(ps2); cout << "Tong: "; kq.Xuat();
    kq = ps1.Hieu(ps2); cout << "Hieu: "; kq.Xuat();
    kq = ps1.Tich(ps2); cout << "Tich: "; kq.Xuat();
    kq = ps1.Thuong(ps2); cout << "Thuong: "; kq.Xuat();

    cout << "So sanh: "; ps1.SoSanh(ps2);

    return 0;
}
