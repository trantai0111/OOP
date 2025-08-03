#include "NhanVien.h"
#include <iostream>
using namespace std;

void NhanVien::Nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaysinh);
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << hoten << ", Ngay sinh: " << ngaysinh;
}

string NhanVien::GetHoTen() {
    return hoten;
}

string NhanVien::GetNgaySinh() {
    return ngaysinh;
}
