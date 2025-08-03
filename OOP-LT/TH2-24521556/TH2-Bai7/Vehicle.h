#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle {
private:
    string chuXe;
    string loaiXe;
    double triGia;
    int dungTich;

public:
    // Constructor
    Vehicle();
    Vehicle(string chuXe, string loaiXe, double triGia, int dungTich);

    // Nhập thông tin từ bàn phím
    void Nhap();

    // Xuất thông tin xe
    void Xuat() const;

    // Tính thuế trước bạ
    double TinhThue() const;
};

#endif
