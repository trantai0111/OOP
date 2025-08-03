// Lớp DatNongNghiep
#ifndef DATNONGNGHIEP_H
#define DATNONGNGHIEP_H
#include "Dat.h"

class DatNongNghiep : public Dat {
    int namSuDung;
public:
    void nhap() override;
    void xuat() const override;
    float tinhThue() const override;
    bool hetHan(int namHienTai) const override;
};

#endif