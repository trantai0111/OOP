#include "Diem.h"

int main() {
    DIEM d1, d2, d3;

    cout << "Nhap diem d1:\n";
    d1.Nhap();
    cout << "Nhap diem d2:\n";
    d2.Nhap();
    cout << "Nhap diem d3:\n";
    d3.Nhap();

    cout << "Toa do cac diem vua nhap:\n";
    cout << "d1 = "; d1.Xuat(); cout << endl;
    cout << "d2 = "; d2.Xuat(); cout << endl;
    cout << "d3 = "; d3.Xuat(); cout << endl;

    cout << "\nKhoang cach d1 - d2: " << d1.TinhKhoangCach(d2) << endl;
    cout << "Khoang cach d2 - d3: " << d2.TinhKhoangCach(d3) << endl;
    cout << "Khoang cach d3 - d1: " << d3.TinhKhoangCach(d1) << endl;

    if (DIEM::KiemTraTamGiac(d1, d2, d3)) {
        cout << "\nChu vi tam giac: " << DIEM::TinhChuVi(d1, d2, d3) << endl;
        cout << "Dien tich tam giac: " << DIEM::TinhDienTich(d1, d2, d3) << endl;
        DIEM::PhanLoaiTamGiac(d1, d2, d3);
    }
    else {
        cout << "\nBa diem khong tao thanh tam giac." << endl;
    }

    return 0;
}
