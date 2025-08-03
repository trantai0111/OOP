#ifndef KIEMCHUNGVEN_H
#define KIEMCHUNGVEN_H

#include "NhanVien.h"

class KiemChungVien : public NhanVien {
    int soLoiPhatHien;
public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const override;
};

#endif