#include "cDSPhanSo.h"

int main() {
    cDSPhanSo d;
    d.Nhap();

    cout << "\nDanh sach phan so: ";
    d.Xuat();

    cout << "\nTong: ";
    d.TinhTong().Xuat();

    cout << "\nPhan so lon nhat: ";
    d.TimMax().Xuat();

    cout << "\nPhan so nho nhat: ";
    d.TimMin().Xuat();

    cout << "\nPhan so co tu la so nguyen to lon nhat: ";
    d.TuNguyenToMax().Xuat();

    cout << "\nDanh sach sau sap xep tang dan: ";
    d.SapXepTang();
    d.Xuat();

    cout << "\nDanh sach sau sap xep giam dan: ";
    d.SapXepGiam();
    d.Xuat();

    return 0;
}
