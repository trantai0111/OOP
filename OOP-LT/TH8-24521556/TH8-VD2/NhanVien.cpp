#include "NhanVien.h"
#include <iostream>
using namespace std;

void NhanVien::nhap() {
    cout << "Ma NV: "; getline(cin, maNV);
    cout << "Ho ten: "; getline(cin, hoTen);
    cout << "Tuoi: "; cin >> tuoi; cin.ignore();
    cout << "SDT: "; getline(cin, sdt);
    cout << "Email: "; getline(cin, email);
    cout << "Luong co ban: "; cin >> luongCoBan; cin.ignore();
}

void NhanVien::xuat() const {
    cout << "Ma NV: " << maNV << ", Ho ten: " << hoTen << ", Tuoi: " << tuoi
         << ", SDT: " << sdt << ", Email: " << email << ", Luong co ban: " << luongCoBan << endl;
}