#pragma once
#ifndef PTBAC1_H
#define PTBAC1_H

#include <iostream>
using namespace std;

class PTBac1 {
private:
    double a, b;

public:
    // Constructor mặc định
    PTBac1();

    // Constructor với hệ số a = 0, b tùy ý
    PTBac1(double b);

    // Constructor với hệ số a, b tùy ý
    PTBac1(double a, double b);

    // Nhập hệ số
    void Nhap();

    // Giải phương trình
    void GiaiPT() const;

    // Xuất phương trình
    void Xuat() const;
};

#endif
