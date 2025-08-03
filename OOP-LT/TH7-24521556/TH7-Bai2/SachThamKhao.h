#pragma once
#include "Sach.h"

class SachThamKhao : public Sach {
private:
    double thue;
public:
    void Nhap() override;
    void Xuat() const override;
    double ThanhTien() const override;
    double getDonGia() const;
};
