#pragma once
#include <bits/stdc++.h>
#include "cNhanVienVP.h"
using namespace std;
class cNhanVienVP;
class cListNhanVienVP: public cNhanVienVP{
private:
	vector<cNhanVienVP>danh_sach;
public:
	cListNhanVienVP();
    cListNhanVienVP(int so_nhanvien);
    ~cListNhanVienVP();
    void ThemNV(const cNhanVienVP&nhan_vien);
    void Nhap();
    void TieuDe()const;
    void Xuat() const; 
    void LuongCaoNhat();
    double TongLuong()const;
    void TuoiCaoNhat();
    void SapXepTangDan();
};
