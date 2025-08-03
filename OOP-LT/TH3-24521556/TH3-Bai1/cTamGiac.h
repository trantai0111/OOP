#ifndef CTAMGIAC_H
#define CTAMGIAC_H

#include <iostream>
#include <cmath>
using namespace std;

struct Diem {
    double x, y;
};

class cTamGiac {
private:
    Diem A, B, C;
    static int dem;

    double DoDai(Diem, Diem) const;

public:
    ~cTamGiac();
    cTamGiac();
    cTamGiac(Diem, Diem, Diem);
    cTamGiac(const cTamGiac&);

    static int GetDem();

    void Nhap();
    void Xuat() const;

    bool LaTamGiac() const;
    string LoaiTamGiac() const;

    double ChuVi() const;
    double DienTich() const;

    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double goc);

    friend istream& operator>>(istream&, cTamGiac&);
    friend ostream& operator<<(ostream&, const cTamGiac&);
};

#endif
