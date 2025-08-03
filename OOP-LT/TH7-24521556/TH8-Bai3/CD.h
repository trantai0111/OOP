#pragma once
#include "SinhVien.h"

class CD : public SinhVien {
private:
    float diemTotNghiep;

public:
    void Nhap() override;
    void Xuat() override;
    bool TotNghiep() override;
};
