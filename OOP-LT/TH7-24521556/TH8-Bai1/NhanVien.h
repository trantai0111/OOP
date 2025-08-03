#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

class NhanVien {
protected:
    string hoten;
    string ngaysinh;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual long TinhLuong() = 0;
    virtual ~NhanVien() {}
    string GetHoTen();
    string GetNgaySinh();
};

#endif
