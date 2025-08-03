#pragma once
#ifndef MANG1C_H
#define MANG1C_H

#include <iostream>
#include <iomanip>
using namespace std;

class MANG1C {
private:
    int* a;     // Con trỏ cấp phát mảng động
    int n;      // Số phần tử mảng

public:
    // Các hàm kiểm tra
    bool KiemTraSNT(int) const;
    bool KiemTraSCP(int) const;
    bool KiemTraSHT(int) const;
    bool KiemTraSDX(int) const;

    // Các constructor/destructor
    MANG1C();
    MANG1C(int n);
    MANG1C(int n, int m);
    MANG1C(const MANG1C&);
    ~MANG1C();

    // Toán tử gán
    MANG1C& operator=(const MANG1C&);

    // Truy vấn & cập nhật
    int GetN() const;
    int GetA(int i) const;
    void SetN(int);
    void SetA(const MANG1C&);

    // Nhập, xuất
    void Nhap();
    void Xuat() const;
    friend istream& operator>>(istream&, MANG1C&);
    friend ostream& operator<<(ostream&, const MANG1C&);

    // Các thao tác trên mảng
    void PhatSinh(int min = 0, int max = 100);
    void LietKeSNT() const;
    int DemSCP() const;
    int TinhTongSHT() const;
    double TinhTBCongSDX() const;
    bool KiemTraMangle() const;
    int TimChanBeNhat() const;
    void SapXepMangTang();
    void XoaTaiVT(int);
    void ThemTaiVT(int, int);
    void CapNhatGiaTriTaiVT(int, int);
    int TimKiemTuyenTinh(int) const;
    int TimKiemNhiPhan(int) const;
};

#endif
