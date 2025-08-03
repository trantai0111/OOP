// Khai báo lớp VeTungPhan
#ifndef VETUNGPHAN_H
#define VETUNGPHAN_H
#include "Ve.h"

class VeTungPhan : public Ve {
public:
    void nhap() override;
    void xuat() const override;
    int tinhTien() const override;
};

#endif