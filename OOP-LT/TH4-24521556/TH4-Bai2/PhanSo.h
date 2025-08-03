#pragma once

#include <iostream>
using namespace std;


class PhanSo {
private:
    int iTu;    // Tử số.
    int iMau;   // Mẫu số.

public:
    PhanSo();
    PhanSo(int Tu, int Mau);

    friend PhanSo operator + (const PhanSo& a, const PhanSo& b);
    friend PhanSo operator - (const PhanSo& a, const PhanSo& b);
    friend PhanSo operator * (const PhanSo& a, const PhanSo& b);
    friend PhanSo operator / (const PhanSo& a, const PhanSo& b);

    friend bool operator == (const PhanSo& a, const PhanSo& b);
    friend bool operator != (const PhanSo& a, const PhanSo& b);
    friend bool operator >= (const PhanSo& a, const PhanSo& b);
    friend bool operator <= (const PhanSo& a, const PhanSo& b);
    friend bool operator >  (const PhanSo& a, const PhanSo& b);
    friend bool operator <  (const PhanSo& a, const PhanSo& b);

    friend ostream& operator << (ostream &os, const PhanSo& ps);
    friend istream& operator >> (istream &is, PhanSo& ps);
};
