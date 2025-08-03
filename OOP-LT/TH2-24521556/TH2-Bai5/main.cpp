#include <iostream>
#include "NgayThangNam.h"

using namespace std;

int main() {
    NgayThangNam ngay1; // Mặc định là 1/1/2000
    NgayThangNam ngay2(29, 2, 2024); // Ngày hợp lệ trong năm nhuận
    NgayThangNam ngay3(31, 4, 2023); // Ngày không hợp lệ

    cout << "\nNgay 1: "; ngay1.Xuat();
    cout << "\nNgay 2: "; ngay2.Xuat();
    cout << "\nNgay 3: "; ngay3.Xuat();

    // Nhập ngày từ bàn phím
    cout << "\nNhap ngay moi: ";
    ngay1.Nhap();
    cout << "Ngay vua nhap: "; ngay1.Xuat();

    // Kiểm tra năm nhuận
    if (ngay1.LaNamNhuan()) {
        cout << "\nNam " << ngay1.GetNam() << " la nam nhuan.";
    }
    else {
        cout << "\nNam " << ngay1.GetNam() << " khong phai nam nhuan.";
    }

    // Tăng/Giảm ngày
    ngay1.TangNgay(1);
    cout << "\nNgay sau khi tang 1 ngay: "; ngay1.Xuat();

    ngay1.GiamNgay(2);
    cout << "\nNgay sau khi giam 2 ngay: "; ngay1.Xuat();

    // Lấy thứ trong tuần
    cout << "\nThu cua ngay vua nhap la: " << ngay1.ThuTrongTuan();

    return 0;
}
