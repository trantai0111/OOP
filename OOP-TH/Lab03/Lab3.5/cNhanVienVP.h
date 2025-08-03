#pragma once
#include <bits/stdc++.h>
using namespace std;
class cNhanVienVP{
protected:
	string ma,ten,ngay_sinh;
	double luong;
public:
	cNhanVienVP();
    cNhanVienVP(string ma,string ten,string ngay_sinh,double luong);
    ~cNhanVienVP();
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
    void setluong(double salary);
    string GetMa()const;
    string GetTen()const; 
    string GetNgaySinh()const;
    double GetLuong()const; 
    friend class cListNhanVienVP;
};
