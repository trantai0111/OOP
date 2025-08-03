#pragma once

#include "SoPhuc.h"


SoPhuc::SoPhuc() : iThuc(0.0), iAo(0.0) {}

SoPhuc::SoPhuc(float thuc, float ao = 0.0) : iThuc(thuc), iAo(ao) {}

SoPhuc operator + (const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.iThuc + b.iThuc, a.iAo + b.iAo);
}

SoPhuc operator - (const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.iThuc - b.iThuc, a.iAo - b.iAo);
}

SoPhuc operator * (const SoPhuc& a, const SoPhuc& b) {
    float thuc = a.iThuc * b.iThuc - a.iAo * b.iAo;
    float ao = a.iThuc * b.iAo + a.iAo * b.iThuc;
    return SoPhuc(thuc, ao);
}

SoPhuc operator / (const SoPhuc& a, const SoPhuc& b) {
    float mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
    float thuc = (a.iThuc * b.iThuc + a.iAo * b.iAo) / mau;
    float ao = (a.iAo * b.iThuc - a.iThuc * b.iAo) / mau;
    return SoPhuc(thuc, ao);
}

bool operator == (const SoPhuc& a, const SoPhuc& b) {
    return (a.iThuc == b.iThuc) && (a.iAo == b.iAo); 
}

bool operator != (const SoPhuc& a, const SoPhuc& b) {
    return !(a == b); 
}

ostream& operator << (ostream &os, const SoPhuc& sp) {
    os << sp.iThuc;
    if (sp.iAo >= 0) 
        os << " + " << sp.iAo << "i";
    else 
        os << " - " << -sp.iAo << "i";
    return os;
}

istream& operator >> (istream &is, SoPhuc& sp) {
    is >> sp.iThuc >> sp.iAo;
    return is;
}
