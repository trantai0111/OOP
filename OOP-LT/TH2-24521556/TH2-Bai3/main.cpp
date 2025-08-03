#include "SoPhuc.h"

int main() {
    SoPhuc sp1, sp2;
    cout << "Nhap so phuc thu nhat:\n";
    sp1.Nhap();
    cout << "Nhap so phuc thu hai:\n";
    sp2.Nhap();

    cout << "\nSo phuc thu nhat: "; sp1.Xuat();
    cout << "So phuc thu hai: "; sp2.Xuat();

    SoPhuc tong = sp1 + sp2;
    SoPhuc hieu = sp1 - sp2;
    SoPhuc tich = sp1 * sp2;
    SoPhuc thuong = sp1 / sp2;

    cout << "\nTong: "; tong.Xuat();
    cout << "Hieu: "; hieu.Xuat();
    cout << "Tich: "; tich.Xuat();
    cout << "Thuong: "; thuong.Xuat();

    return 0;
}
