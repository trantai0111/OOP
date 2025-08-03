#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H

#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
    int soGioLamThem;
public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const override;
};

#endif