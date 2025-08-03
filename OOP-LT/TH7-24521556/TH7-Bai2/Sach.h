#pragma once
#include <string>
#include <iostream> 
using namespace std;

class Sach {
protected:
    string maSach;
    string ngayNhap;
    double donGia;
    int soLuong;
    string nhaXuatBan;
public:
    virtual void Nhap();
    virtual void Xuat() const;
    virtual double ThanhTien() const = 0; // Hàm thuần ảo
    string getNhaXuatBan() const;
};
