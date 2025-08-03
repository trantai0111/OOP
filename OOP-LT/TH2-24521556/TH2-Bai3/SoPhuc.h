#pragma once
#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc; // Phần thực
    double ao;   // Phần ảo

public:
    // Constructor
    SoPhuc();
    SoPhuc(double t, double a);

    // Hàm nhập và xuất
    void Nhap();
    void Xuat() const;

    // Toán tử cộng, trừ, nhân, chia
    SoPhuc operator+(const SoPhuc& sp) const;
    SoPhuc operator-(const SoPhuc& sp) const;
    SoPhuc operator*(const SoPhuc& sp) const;
    SoPhuc operator/(const SoPhuc& sp) const;
};

#endif
