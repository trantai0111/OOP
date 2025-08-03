#ifndef NVSX_H
#define NVSX_H

#include "NhanVien.h"

class NVSX : public NhanVien {
    long luongcb;
    int soSP;
public:
    void Nhap() override;
    void Xuat() override;
    long TinhLuong() override;
};

#endif
