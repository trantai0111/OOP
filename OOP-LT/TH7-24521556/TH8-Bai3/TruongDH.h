#pragma once
#include <vector>
#include "CD.h"
#include "DH.h"

class TruongDH {
private:
    vector<SinhVien*> ds;

public:
    ~TruongDH();
    void NhapDS();
    void XuatDS();
    void XuatDSTotNghiep();
    void XuatDSKhongTotNghiep();
    void DSSVDH_DiemTBCaoNhat();
    void DSSVCD_DiemTBCaoNhat();
    void DemKhongTotNghiep();
};