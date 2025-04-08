#ifndef PHANSO_H_INCLUDED
#define PHANSO_H_INCLUDED

#include<iostream>
using namespace std;

class PhanSo{
    private:
        int iTu, iMau;
    public:
        void Nhap();
        void Xuat();
        void RutGon();
        PhanSo Tong(PhanSo ps);
        PhanSo Hieu(PhanSo ps);
        PhanSo Tich(PhanSo ps);
        PhanSo Thuong(PhanSo ps);
        void SoSanh(PhanSo ps);
};

#endif // PHANSO_H_INCLUDED
