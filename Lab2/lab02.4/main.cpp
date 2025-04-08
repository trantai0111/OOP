#include "ThoiGian.h"

int main() {
    ThoiGian tg;
    cout << "Nhap thoi gian:\n";
    tg.Nhap();

    cout << "Thoi gian vua nhap: ";
    tg.Xuat();

    tg.TinhCongThemMotGiay();
    cout << "Thoi gian sau khi cong 1 giay: ";
    tg.Xuat();

    return 0;
}
