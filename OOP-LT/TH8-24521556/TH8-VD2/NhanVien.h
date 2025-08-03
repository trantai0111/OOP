#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

class NhanVien {
protected:
    string maNV, hoTen, sdt, email;
    int tuoi;
    double luongCoBan;
public:
    virtual void nhap();
    virtual void xuat() const;
    virtual double tinhLuong() const = 0;
    virtual ~NhanVien() {}
};

#endif