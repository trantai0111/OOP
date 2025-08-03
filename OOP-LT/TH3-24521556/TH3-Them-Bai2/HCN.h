#pragma once
#ifndef HCN_H
#define HCN_H

#include "Diem.h"

class HCN {
private:
    DIEM A, B, C, D; // A: trái trên, B: phải trên, C: phải dưới, D: trái dưới
    static int dem;

public:
    // Constructors
    HCN();
    HCN(const DIEM& a, const DIEM& c); // Nhập 2 đỉnh chéo A và C, tự tính B, D

    // Destructor
    ~HCN();

    // Getter
    DIEM getA() const;
    DIEM getB() const;
    DIEM getC() const;
    DIEM getD() const;

    // Setter
    void setA(const DIEM& a);
    void setC(const DIEM& c);
    void CapNhatB_D();

    // Phương thức xử lý
    void Nhap();        // Nhập A và C, tính B, D
    void Xuat() const;
    void DiChuyen(float dx, float dy);
    float TinhChuVi() const;
    float TinhDienTich() const;
    bool KiemTraHopLe() const;

    // Static
    static int getSoLuongHCN();
};

#endif
