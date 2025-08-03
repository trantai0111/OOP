#pragma once
#include <bits/stdc++.h>
#include "cNhanVienSX.h"
using namespace std;
class cNhanVienSX;
class cListNhanVienSX: public cNhanVienSX{
private:
	vector<cNhanVienSX>danh_sach;
public:
	cListNhanVienSX();
    cListNhanVienSX(int so_nhanvien);
    ~cListNhanVienSX();
    void ThemNV(const cNhanVienSX&nhan_vien);
    void Nhap();
    void TieuDe()const;
    void Xuat() const; 
    void LuongThapNhat();
    double TongLuong()const;
    void TuoiCaoNhat();
    void SapXepTangDan();
};
