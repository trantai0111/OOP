#pragma once
#ifndef DIEM_H
#define DIEM_H

#include <iostream>
#include <cmath>
using namespace std;

class DIEM {
private:
    float x, y;

public:
    // Constructor
    DIEM();
    DIEM(float x, float y);

    // Nhập và xuất điểm
    void Nhap();
    void Xuat() const;

    // Getter & Setter
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    // Di chuyển điểm
    void DiChuyen(float dx, float dy);

    // Kiểm tra hai điểm trùng nhau
    bool KiemTraTrung(const DIEM& d) const;

    // Tính khoảng cách giữa hai điểm
    float TinhKhoangCach(const DIEM& d) const;

    // Tìm điểm đối xứng qua trục tung và hoành
    DIEM DoiXungQuaTrucHoanh() const;
    DIEM DoiXungQuaTrucTung() const;

    // Kiểm tra ba điểm có tạo thành tam giác không
    static bool KiemTraTamGiac(const DIEM& d1, const DIEM& d2, const DIEM& d3);

    // Tính chu vi và diện tích tam giác
    static float TinhChuVi(const DIEM& d1, const DIEM& d2, const DIEM& d3);
    static float TinhDienTich(const DIEM& d1, const DIEM& d2, const DIEM& d3);

    // Phân loại tam giác
    static void PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2, const DIEM& d3);
};

#endif
