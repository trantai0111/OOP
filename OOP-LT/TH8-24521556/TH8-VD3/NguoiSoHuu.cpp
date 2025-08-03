// Cài đặt lớp NguoiSoHuu
#include "NguoiSoHuu.h"
#include <iostream>
using namespace std;

void NguoiSoHuu::nhap() {
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap nam sinh: "; cin >> namSinh; cin.ignore();
    cout << "Nhap CMND: "; getline(cin, cmnd);
    cout << "Nhap dia chi: "; getline(cin, diaChi);
}

void NguoiSoHuu::xuat() const {
    cout << hoTen << ", " << namSinh << ", " << cmnd << ", " << diaChi << endl;
}