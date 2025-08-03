// Lớp cơ sở Dat
#ifndef DAT_H
#define DAT_H
#include "NguoiSoHuu.h"

class Dat {
protected:
    string soGCN;
    NguoiSoHuu nguoi;
    int soThua, soTo;
    string diaChi;
    float dienTich;
    string ngayCap;
    float donGiaThue;
public:
    virtual void nhap();
    virtual void xuat() const;
    virtual float tinhThue() const = 0;
    virtual bool hetHan(int namHienTai) const { return false; }
};

#endif