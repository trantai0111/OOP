// Lớp DatPhiNongNghiep
#ifndef DATPHINONGNGHIEP_H
#define DATPHINONGNGHIEP_H
#include "Dat.h"

class DatPhiNongNghiep : public Dat {
public:
    void nhap() override;
    void xuat() const override;
    float tinhThue() const override;
};

#endif