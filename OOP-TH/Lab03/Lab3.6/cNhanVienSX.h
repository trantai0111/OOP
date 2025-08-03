#pragma once
#include <bits/stdc++.h>
using namespace std;
class cNhanVienSX{
protected:
	string ma,ten,ngay_sinh;
	int san_pham;
	double don_gia,luong;
public:
	cNhanVienSX();
    cNhanVienSX(string ma,string ten,string ngay_sinh,int san_pham,double don_gia);
    ~cNhanVienSX();
    double TinhLuong()const;
    bool kiemtra_ma()const;
	bool kiemtra_ten()const;
	bool kiemtra_ngaysinh()const;
	void Chuanhoa(string &s);
    void Nhap();
    void Xuat()const;
    int LayNamSinh(string namsinh);
    void setMa(string ms);
    void setTen(string hoten);
    void setNgaySinh(string ns); 
    void setSanPham(int sp);
    void setDonGia(double dongia);
    string GetMa()const;
    string GetTen()const; 
    string GetNgaySinh()const;
    int GetSanPham()const;
    double GetDonGia()const;
    double GetLuong()const;
    friend class cListNhanVienSX;
};
