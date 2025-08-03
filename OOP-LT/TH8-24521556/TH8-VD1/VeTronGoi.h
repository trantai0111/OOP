// Khai báo lớp VeTronGoi
#ifndef VETRONGOI_H
#define VETRONGOI_H
#include "Ve.h"

class VeTronGoi : public Ve {
public:
    void nhap() override;
    void xuat() const override;
    int tinhTien() const override;
};

#endif