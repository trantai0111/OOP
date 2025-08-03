#pragma once
#include "Sach.h"
class SachGiaoKhoa : public Sach
{
private:
    string tinhTrang; // "moi" hoặc "cu"
public:
    void Nhap() override;
    void Xuat() const override;
    double ThanhTien() const override;
};

