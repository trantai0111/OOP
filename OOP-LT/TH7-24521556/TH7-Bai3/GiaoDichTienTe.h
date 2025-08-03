#pragma once
#include "GiaoDich.h"

class GiaoDichTienTe : public GiaoDich {
private:
    double tiGia;
    string loaiTien; // "VN", "USD", "EURO"

public:
    void Nhap() override;
    void Xuat() const override;
    double ThanhTien() const override;
    string getLoaiTien() const;
};
