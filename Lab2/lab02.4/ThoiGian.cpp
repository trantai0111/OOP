#include "ThoiGian.h"

void ThoiGian::Nhap() {
    do {
        cout << "Nhap gio (0-23): ";
        cin >> iGio;
    } while (iGio < 0 || iGio > 23);

    do {
        cout << "Nhap phut (0-59): ";
        cin >> iPhut;
    } while (iPhut < 0 || iPhut > 59);

    do {
        cout << "Nhap giay (0-59): ";
        cin >> iGiay;
    } while (iGiay < 0 || iGiay > 59);
}

void ThoiGian::Xuat() {
    cout << (iGio < 10 ? "0" : "") << iGio << ":"
         << (iPhut < 10 ? "0" : "") << iPhut << ":"
         << (iGiay < 10 ? "0" : "") << iGiay << endl;
}

void ThoiGian::TinhCongThemMotGiay() {
    iGiay++;
    if (iGiay == 60) {
        iGiay = 0;
        iPhut++;
        if (iPhut == 60) {
            iPhut = 0;
            iGio++;
            if (iGio == 24)
                iGio = 0;
        }
    }
}
