#include "SachGiaoKhoa.h"
#include "SachThamKhao.h"
#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    SachGiaoKhoa sgk[n];
    SachThamKhao stk[n];

    cout << "--- Nhap danh sach Sach Giao Khoa ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Sach Giao Khoa " << i + 1 << ":\n";
        sgk[i].Nhap();
    }

    cout << "--- Nhap danh sach Sach Tham Khao ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Sach Tham Khao " << i + 1 << ":\n";
        stk[i].Nhap();
    }

    cout << "\n--- Xuat danh sach Sach Giao Khoa ---\n";
    for (int i = 0; i < n; i++)
        sgk[i].Xuat();

    cout << "\n--- Xuat danh sach Sach Tham Khao ---\n";
    for (int i = 0; i < n; i++)
        stk[i].Xuat();

    double tongSGK = 0, tongSTK = 0, tongDonGiaSTK = 0;
    for (int i = 0; i < n; i++) {
        tongSGK += sgk[i].ThanhTien();
        tongSTK += stk[i].ThanhTien();
        tongDonGiaSTK += stk[i].getDonGia();
    }

    cout << "\nTong thanh tien SGK: " << tongSGK;
    cout << "\nTong thanh tien STK: " << tongSTK;
    cout << "\nTrung binh don gia STK: " << tongDonGiaSTK / n;

    string nxb;
    cout << "\nNhap NXB can tim: ";
    getline(cin, nxb);
    cout << "\nDanh sach SGK cua NXB " << nxb << ":\n";
    for (int i = 0; i < n; i++) {
        if (sgk[i].getNhaXuatBan() == nxb)
            sgk[i].Xuat();
    }

    return 0;
}
