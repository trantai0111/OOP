#pragma once
#include "SinhVien.h"

class DH : public SinhVien {
private:
    string tenLuanVan;
    float diemLuanVan;

public:
    void Nhap() override;
    void Xuat() override;
    bool TotNghiep() override;
};

