#pragma once
#include <bits/stdc++.h>
using namespace std;
class cCandidate{
protected:
	string ma,ten,ngay_sinh;
	double diem_toan,diem_van,diem_anh;
public:
	cCandidate();
	cCandidate(string ma,string ten,string ngay_sinh,double diem_toan,double diem_van,double diem_anh);
	~cCandidate();
	float TinhTongDiem()const;
	bool kiemtra_ma()const;
	bool kiemtra_ten()const;
	bool kiemtra_ngaysinh()const;
	void Chuanhoa(string &s);
	void Nhap();
	void Xuat()const;
	void setMa(string ms);
	void setTen(string hoten);
	void setNgaySinh(string ns);
	void setdiemtoan(double toan);
	void setdiemvan(double van);
	void setdiemanh(double anh);
	string GetMa()const;
	string GetTen()const;
	string GetNgaySinh()const;
	double GetDiemToan()const;
	double GetDiemVan()const;
	double GetDiemAnh()const;
};
