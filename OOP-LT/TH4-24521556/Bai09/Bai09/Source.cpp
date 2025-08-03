#include <iostream>
#include"TuGiac.h"
#include"HinhThoi.h"
#include"HinhVuong.h"
using namespace std;

int main() {
    CTuGiac* dsHinh[100];  
    int n;

    cout << "Nhap so hinh: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "Nhap loai hinh (1: Vuong, 2: Thoi): ";
        cin >> loai;

        if (loai == 1) dsHinh[i] = new CHinhVuong();
        else if (loai == 2) dsHinh[i] = new CHinhThoi();
        else {
            cout << "Loai hinh khong hop le!\n";
            i--; 
            continue;
        }

        dsHinh[i]->Nhap();
    }

    cout << "\n=== Danh sach cac hinh ===\n";
    for (int i = 0; i < n; i++) {
        dsHinh[i]->Xuat();
        cout << "Chu vi: " << dsHinh[i]->TinhChuVi() << "\n";
        cout << "Dien tich: " << dsHinh[i]->TinhDienTich() << "\n\n";
    }

    for (int i = 0; i < n; i++) {
        delete dsHinh[i];
    }

    return 0;
}