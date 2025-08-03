#include "NVVP.h"
#include <iostream>
using namespace std;

void NVVP::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> songay;
    cin.ignore();
}

void NVVP::Xuat() {
    NhanVien::Xuat();
    cout << ", So ngay lam viec: " << songay
         << ", Luong: " << TinhLuong() << endl;
}

long NVVP::TinhLuong() {
    return songay * 100000;
}

int NVVP::GetTuoi() {
    int namSinh = stoi(ngaysinh.substr(6, 4));
    return 2025 - namSinh;
}
