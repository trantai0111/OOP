#include <iostream>
#include "NgayThangNam.h"
using namespace std;

// Hàm hỗ trợ nằm ngoài class
bool NamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int SoNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return NamNhuan(nam) ? 29 : 28;
        default: return 0;
    }
}

// Định nghĩa các hàm của class
void NgayThangNam::Nhap() {
    do {
        cout << "Nhap ngay: "; cin >> iNgay;
        cout << "Nhap thang: "; cin >> iThang;
        cout << "Nhap nam: "; cin >> iNam;

        if (iThang < 1 || iThang > 12 || iNgay < 1 || iNgay > SoNgayTrongThang(iThang, iNam)) {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai!\n";
        } else break;
    } while (true);
}

void NgayThangNam::Xuat() {
    cout << "Ngay/Thang/Nam: " << iNgay << "/" << iThang << "/" << iNam << endl;
}

void NgayThangNam::NgayThangNamTiepTheo() {
    iNgay++;
    if (iNgay > SoNgayTrongThang(iThang, iNam)) {
        iNgay = 1;
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    cout << "Ngay tiep theo la: " << iNgay << "/" << iThang << "/" << iNam << endl;
}
