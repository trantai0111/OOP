#ifndef TAMGIAC_H
#define TAMGIAC_H

#include <iostream>
#include <cmath>
using namespace std;

class TamGiac {
private:
    double a, b, c; // Độ dài 3 cạnh tam giác

public:
    // Constructor mặc định
    TamGiac();

    // Constructor có tham số
    TamGiac(double canh1, double canh2, double canh3);
    TamGiac(double canh1, double canh2);
    TamGiac(double canh1);

    // Hàm nhập và xuất tam giác
    void Nhap();
    void Xuat() const;

    // Kiểm tra tam giác hợp lệ
    bool LaTamGiac() const;

    // Phân loại tam giác
    string PhanLoai() const;

    // Tính chu vi tam giác
    double ChuVi() const;

    // Tính diện tích tam giác
    double DienTich() const;
};

#endif
