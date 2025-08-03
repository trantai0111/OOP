#include "TamGiac.h"

int main() {
    TamGiac tg;

    // Nhập tam giác từ người dùng
    tg.Nhap();

    // Xuất thông tin tam giác
    cout << "\nThông tin tam giác:\n";
    tg.Xuat();

    return 0;
}
