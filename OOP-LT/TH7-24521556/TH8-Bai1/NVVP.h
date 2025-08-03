#ifndef NVVP_H
#define NVVP_H

#include "NhanVien.h"

class NVVP : public NhanVien {
    int songay;
public:
    void Nhap() override;
    void Xuat() override;
    long TinhLuong() override;
    int GetTuoi();
};

#endif
