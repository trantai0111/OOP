#include <bits/stdc++.h>
#include "cArray.h"
using namespace std;
int main() {
    cArray a;
    cout << "========== KHOI TAO MANG ==========" << endl;
    a.PhatSinh();
    cout << "\n1. Mang vua phat sinh:\n";
    a.Xuat();
    cout << "\n========== DEM SO LAN XUAT HIEN CUA X ==========" << endl;
    int x;
    cout << "Nhap gia tri X muon dem: ";
    cin >> x;
    cout << "2. So lan xuat hien cua X trong mang: " << a.Dem(x) << endl;
    cout << "\n========== KIEM TRA MANG TANG DAN ==========" << endl;
    if (a.KiemTraTangDan())
        cout << "3. Mang tang dan.\n";
    else
        cout << "3. Mang khong tang dan.\n";
    cout << "\n========== TIM PHAN TU LE NHO NHAT ==========" << endl;
    a.SearchMinLe();
    cout << "\n========== TIM SO NGUYEN TO LON NHAT ==========" << endl;
    a.SearchMaxSNT();
    cout << "\n========== SAP XEP MANG ==========" << endl;
    a.Sort();
    cout << "\n6. Mang sau khi sap xep:\n";
    a.Xuat();
    cout << "\n========== CHUONG TRINH KET THUC ==========" << endl;
    return 0;
}

