#pragma once
#include "NhanVien.h"
#include "NVVP.h"
#include "NVSX.h"

class CONGTY {
private:
    NhanVien** ds;
    int n; // số lượng nhân viên
public:
    CONGTY();
    ~CONGTY();

    void Nhap();                             
    void Xuat();                             
    long TinhTongLuong();                    
    void TinhLuongTungNhanVien();           
    void TimNVSXLuongThapNhat();            
    void TimNVVPTuoiCaoNhat(); 
};
