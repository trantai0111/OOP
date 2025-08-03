#pragma once
#include "cPhanSo.h"

class cDSPhanSo {
private:
    cPhanSo* ds;
    int n;
public:
    cDSPhanSo();
    ~cDSPhanSo();
    void Nhap();
    void Xuat() const;
    cPhanSo TinhTong() const;
    cPhanSo TimMax() const;
    cPhanSo TimMin() const;
    cPhanSo TuNguyenToMax() const;
    void SapXepTang();
    void SapXepGiam();
};
