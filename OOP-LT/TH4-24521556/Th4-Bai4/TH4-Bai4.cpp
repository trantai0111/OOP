#include "CDate.h"
#include <iostream>
#include <cmath>
using namespace std;

// Lai suat don gian: A = P * (1 + r * t)
double tinhLaiSuat(double tienGoc, double laiSuatNam, int soNgay) {
    double r = laiSuatNam / 100.0;
    double t = soNgay / 365.0;
    return tienGoc * (1 + r * t);
}

int main() {
    CDate ngayGui, ngayRut;
    double soTienGoc, laiSuat;

    cin >> ngayGui;
    cin >> ngayRut;
    cout << "So tien gui ban dau: ";
    cin >> soTienGoc;
    cout << "Lai suat (%/nam): ";
    cin >> laiSuat;

    int soNgay = ngayRut - ngayGui;
    cout << "So ngay gui: " << soNgay << endl;

    double soTienLanh = tinhLaiSuat(soTienGoc, laiSuat, soNgay);
    cout << "Tong so tien nhan duoc: " << soTienLanh << endl;

    return 0;
}
