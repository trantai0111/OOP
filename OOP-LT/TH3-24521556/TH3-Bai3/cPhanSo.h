#pragma once
#include <iostream>
using namespace std;

class cPhanSo {
private:
    int tu;
    int mau;
public:
    cPhanSo(int = 0, int = 1);
    void Nhap();
    void Xuat() const;
    int LayTu() const;
    int LayMau() const;
    void RutGon();
    float GiaTriThuc() const;

    cPhanSo Cong(const cPhanSo&) const;
    bool LonHon(const cPhanSo&) const;
    bool NhoHon(const cPhanSo&) const;
};
bool LaNguyenTo(int n);
