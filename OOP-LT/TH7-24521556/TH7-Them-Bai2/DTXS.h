#ifndef DTXS_H
#define DTXS_H

#include <iostream>
#include <string>
using namespace std;

class DTXS {
protected:
    string maso, hoten, khoa;
public:
    DTXS();
    DTXS(string ma, string ten, string k);
    virtual ~DTXS();

    virtual void Nhap();
    virtual void Xuat();
    virtual long TinhTienThuong() = 0;

    string GetMaSo() const;
    string GetHoTen() const;
    string GetKhoa() const;
    virtual string GetLoai() = 0;

    void SetHoTen(string ten);
    void SetKhoa(string k);
};

#endif
