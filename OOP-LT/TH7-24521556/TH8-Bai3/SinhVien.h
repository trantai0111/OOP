#pragma once
#include <iostream>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    float diemTB;

public:
    virtual void Nhap();
    virtual void Xuat();
    virtual bool TotNghiep() = 0;
    float GetDiemTB() const;
    virtual ~SinhVien() {}
};
