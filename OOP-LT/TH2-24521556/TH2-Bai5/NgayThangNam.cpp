#include "NgayThangNam.h"

// Constructor mặc định
NgayThangNam::NgayThangNam() : ngay(1), thang(1), nam(2000) {}

// Constructor có tham số
NgayThangNam::NgayThangNam(int d, int m, int y) {
    if (KiemTraHopLe(d, m, y)) {
        ngay = d;
        thang = m;
        nam = y;
    }
    else {
        ngay = 1;
        thang = 1;
        nam = 2000;
    }
}

// Kiểm tra năm nhuận
bool NgayThangNam::NamNhuan(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Số ngày trong tháng
int NgayThangNam::SoNgayTrongThang(int m, int y) {
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && NamNhuan(y)) return 29;
    return daysInMonth[m];
}

// Kiểm tra ngày hợp lệ
bool NgayThangNam::KiemTraHopLe(int d, int m, int y) {
    return (m >= 1 && m <= 12 && d >= 1 && d <= SoNgayTrongThang(m, y));
}

// Nhập ngày tháng năm
void NgayThangNam::Nhap() {
    int d, m, y;
    do {
        cout << "Nhap ngay: "; cin >> d;
        cout << "Nhap thang: "; cin >> m;
        cout << "Nhap nam: "; cin >> y;
    } while (!KiemTraHopLe(d, m, y));
    ngay = d;
    thang = m;
    nam = y;
}

// Xuất ngày tháng năm
void NgayThangNam::Xuat() const {
    cout << ngay << "/" << thang << "/" << nam << endl;
}

// Tăng ngày
void NgayThangNam::TangNgay() {
    ngay++;
    if (!KiemTraHopLe(ngay, thang, nam)) {
        ngay = 1;
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
}

// Giảm ngày
void NgayThangNam::GiamNgay() {
    ngay--;
    if (ngay == 0) {
        thang--;
        if (thang == 0) {
            thang = 12;
            nam--;
        }
        ngay = SoNgayTrongThang(thang, nam);
    }
}

// Lấy thứ trong tuần (Giả sử 01/01/2000 là thứ 7)
string NgayThangNam::LayThuTrongTuan() {
    int totalDays = 0;
    for (int i = 2000; i < nam; i++) {
        totalDays += NamNhuan(i) ? 366 : 365;
    }
    for (int i = 1; i < thang; i++) {
        totalDays += SoNgayTrongThang(i, nam);
    }
    totalDays += ngay - 1;
    string thu[] = { "Thu 7", "Chu Nhat", "Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6" };
    return thu[totalDays % 7];
}
