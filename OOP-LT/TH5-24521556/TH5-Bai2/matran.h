#pragma once
#ifndef MATRAN_H
#define MATRAN_H

#include <iostream>
#include <iomanip>
using namespace std;

class MATRAN {
private:
    int sd, sc;     // số dòng và số cột
    int** p;        // con trỏ vùng nhớ động chứa ma trận

public:
    // Constructor & Destructor
    MATRAN();
    MATRAN(int d, int c);
    MATRAN(const MATRAN&);
    ~MATRAN();

    // Toán tử gán
    MATRAN& operator=(const MATRAN&);

    // Truy vấn & cập nhật
    int GetSD() const;
    int GetSC() const;
    int GetGT(int i, int j) const;
    void SetGT(int i, int j, int val);
    void SetSD(int d);
    void SetSC(int c);

    // Nhập, xuất
    void Nhap();
    void Xuat() const;
    friend istream& operator>>(istream&, MATRAN&);
    friend ostream& operator<<(ostream&, const MATRAN&);

    // Các chức năng xử lý
    void PhatSinh(int min = 0, int max = 100);
    void LietKeSNT() const;
    int DemSCP() const;
    int TinhTongSHTTrenDong(int k) const;
    double TinhTBCongSDXTrenCot(int k) const;
    void SapXepGiam();
    void SapXepTangDong(int k);

    // Các hàm hỗ trợ kiểm tra
    bool KiemTraSNT(int) const;
    bool KiemTraSCP(int) const;
    bool KiemTraSHT(int) const;
    bool KiemTraSDX(int) const;
};

#endif 