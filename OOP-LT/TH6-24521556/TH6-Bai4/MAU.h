#pragma once
#ifndef _MAU
#define _MAU
#include<iostream>
using namespace std;

class MAU {
private:
    int r, g, b; //[0, 255]
    static int dem;
public:
    ~MAU();
    MAU(int = 0, int = 0, int = 0);
    MAU(const MAU&);
    int GetR() const;
    int GetG() const;
    int GetB() const;
    static int GetDem();
    void SetR(int);
    void SetG(int);
    void SetB(int);
    void SetRGB(int, int, int);
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const MAU&) const;
    friend istream& operator>>(istream&, MAU&);
    friend ostream& operator<<(ostream&, const MAU&);
};
#endif
