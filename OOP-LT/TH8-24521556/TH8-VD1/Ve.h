// Khai báo lớp cơ sở Ve
#ifndef VE_H
#define VE_H
#include <iostream>
#include <string>
using namespace std;

class Ve {
protected:
    string maVe;
    string hoTen;
    int namSinh;
    int soTroChoi;
public:
    virtual void nhap();
    virtual void xuat() const;
    virtual int tinhTien() const = 0;
    string getMaVe() const { return maVe; }
};

#endif