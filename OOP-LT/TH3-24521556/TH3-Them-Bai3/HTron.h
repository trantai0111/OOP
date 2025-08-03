#pragma once
#ifndef HTRON_H
#define HTRON_H

#include "Diem.h"

class HTRON {
private:
    DIEM O;        // Tâm hình tròn
    float R;       // Bán kính
    static int dem; // Bi?n t?nh ??m s? hình tròn

public:
    // Constructor
    HTRON();                     // M?c ??nh
    HTRON(const DIEM& o, float r); // Có tham s?

    // Destructor
    ~HTRON();

    // Getter & Setter
    DIEM getO() const;
    float getR() const;
    void setO(const DIEM& o);
    void setR(float r);

    // Các ph??ng th?c khác
    void Nhap();
    void Xuat() const;
    void DiChuyen(float dx, float dy);
    float TinhChuVi() const;
    float TinhDienTich() const;
    bool KiemTraHopLe() const;

    // Bi?n & hàm t?nh
    static int getSoLuongHinhTron();
};

#endif
