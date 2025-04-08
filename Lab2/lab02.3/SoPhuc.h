#ifndef SOPHUC_H_INCLUDED
#define SOPHUC_H_INCLUDED

#include <iostream>
using namespace std;

class SoPhuc {
private:
    float iThuc, iAo;

public:
    void Nhap();
    void Xuat();
    SoPhuc Tong(SoPhuc sp);
    SoPhuc Hieu(SoPhuc sp);
    SoPhuc Tich(SoPhuc sp);
    SoPhuc Thuong(SoPhuc sp);
};

#endif // SOPHUC_H_INCLUDED
