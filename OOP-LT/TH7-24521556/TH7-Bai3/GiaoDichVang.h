#pragma once
#include "GiaoDich.h"

class GiaoDichVang : public GiaoDich {
private:
    string loaiVang;

public:
    void Nhap() override;
    void Xuat() const override;
    double ThanhTien() const override;
};
