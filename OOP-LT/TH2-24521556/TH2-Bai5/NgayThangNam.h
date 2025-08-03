#pragma once
#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int ngay, thang, nam;

public:
    // Constructor
    NgayThangNam();
    NgayThangNam(int d, int m, int y);

    // Hàm nhập và xuất
    void Nhap();
    void Xuat() const;

    // Thiết lập giá trị ngày tháng năm
    void SetNgay(int d);
    void SetThang(int m);
    void SetNam(int y);

    // Lấy giá trị ngày tháng năm
    int GetNgay() const;
    int GetThang() const;
    int GetNam() const;

    // Kiểm tra năm nhuận
    bool LaNamNhuan() const;

    // Lấy số ngày trong tháng
    int SoNgayTrongThang() const;

    // Tăng/Giảm ngày
    void TangNgay();
    void GiamNgay();

    // Lấy thứ trong tuần
    string ThuTrongTuan() const;
};

#endif
