#pragma once
#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string maGD, ngayGD;
    double donGia;
    int soLuong;

public:
    GiaoDich();
    virtual void Nhap();
    virtual void Xuat() const;
    virtual double ThanhTien() const = 0;
    string getMaGD() const;
    double getDonGia() const;
};
