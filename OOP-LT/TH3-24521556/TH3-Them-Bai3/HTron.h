#pragma once
#ifndef HTRON_H
#define HTRON_H

#include "Diem.h"

class HTRON {
private:
    DIEM O;        // T�m h�nh tr�n
    float R;       // B�n k�nh
    static int dem; // Bi?n t?nh ??m s? h�nh tr�n

public:
    // Constructor
    HTRON();                     // M?c ??nh
    HTRON(const DIEM& o, float r); // C� tham s?

    // Destructor
    ~HTRON();

    // Getter & Setter
    DIEM getO() const;
    float getR() const;
    void setO(const DIEM& o);
    void setR(float r);

    // C�c ph??ng th?c kh�c
    void Nhap();
    void Xuat() const;
    void DiChuyen(float dx, float dy);
    float TinhChuVi() const;
    float TinhDienTich() const;
    bool KiemTraHopLe() const;

    // Bi?n & h�m t?nh
    static int getSoLuongHinhTron();
};

#endif
