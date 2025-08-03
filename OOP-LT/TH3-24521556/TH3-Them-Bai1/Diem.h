#pragma once
#ifndef _DIEM
#define _DIEM
#include <iostream>
#include <math.h>
#define epsilon 0.000000001
using namespace std;

class DIEM
{
private:
    double x, y;
    static int dem;

public:
    ~DIEM();
    DIEM();
    DIEM(double);
    DIEM(double, double);
    //DIEM(double = 0, double = 0);
    DIEM(const DIEM&);
    DIEM& operator=(const DIEM&);
    double GetX() const;
    double GetY() const;
    static int GetDem();
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void Nhap();
    void Xuat() const;
    friend istream& operator>>(istream&, DIEM&);
    friend ostream& operator<<(ostream&, const DIEM&);
    void DiChuyen(double, double);
    bool KiemTraTrung(DIEM) const;
    double TinhKhoangCach(const DIEM&) const;
    DIEM TimDiemDoiXung() const;
    bool KiemTraTGHopLe(const DIEM&, const DIEM&) const;
    double TinhChuVi(const DIEM&, const DIEM&) const;
    double TinhDienTich(const DIEM&, const DIEM&) const;
    string PhanLoaiTG(const DIEM&, const DIEM&) const;
};

#endif
