#pragma once

#include <numeric>  // gcd()
#include <stdexcept> // invalid_argument
#include <sstream>
#include "PhanSo.h"

PhanSo::PhanSo() : iTu(0), iMau(1) {}

PhanSo::PhanSo(int Tu, int Mau = 1) : iTu(Tu), iMau(Mau) {
    if (iMau == 0) 
        throw invalid_argument("(!) Mau so khong the bang 0");

    int GCD = gcd(iTu, iMau);
    iTu = iTu / GCD;
    iMau = iMau / GCD;

    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

PhanSo operator + (const PhanSo& a, const PhanSo& b) {
    int Tu = a.iTu * b.iMau + b.iTu * a.iMau;
    int Mau = a.iMau * b.iMau;
    return PhanSo(Tu, Mau);
}

PhanSo operator - (const PhanSo& a, const PhanSo& b) {
    int Tu = a.iTu * b.iMau - b.iTu * a.iMau;
    int Mau = a.iMau * b.iMau;
    return PhanSo(Tu, Mau);
}

PhanSo operator * (const PhanSo& a, const PhanSo& b) {
    int Tu = a.iTu * b.iTu;
    int Mau = a.iMau * b.iMau;
    return PhanSo(Tu, Mau);
}

PhanSo operator / (const PhanSo& a, const PhanSo& b) {
    if (b.iTu == 0) {
        cerr << "\nLoi: Khong the thuc hien phep chia cho 0. Tra ve gia tri mac dinh 0/1" << endl;
        return PhanSo(0, 1);
    }
    int Tu = a.iTu * b.iMau;
    int Mau = a.iMau * b.iTu;
    return PhanSo(Tu, Mau);
}

bool operator == (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau == b.iTu * a.iMau);
}

bool operator != (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau != b.iTu * a.iMau);
}

bool operator >= (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau >= b.iTu * a.iMau);
}

bool operator <= (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau <= b.iTu * a.iMau);
}

bool operator > (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau > b.iTu * a.iMau);
}

bool operator < (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau < b.iTu * a.iMau);
}

ostream& operator << (ostream &os, const PhanSo& ps) {
    os << ps.iTu << '/' << ps.iMau;
    return os;
}

istream& operator >> (istream &is, PhanSo& ps) {
    string input;
    is >> input;

    size_t vitri = input.find('/');
    if (vitri != string::npos) {
        ps.iTu = stoi(input.substr(0, vitri));
        ps.iMau = stoi(input.substr(vitri+1));
    }
    else 
        ps.iTu = stoi(input);

    if (ps.iMau == 0) 
        throw invalid_argument("(!) Mau so khong the bang 0");

    int GCD = gcd(ps.iTu, ps.iMau);
    ps.iTu = ps.iTu / GCD;
    ps.iMau = ps.iMau / GCD;

    if (ps.iMau < 0) {
        ps.iTu = -ps.iTu;
        ps.iMau = -ps.iMau;
    }
    return is;
}

