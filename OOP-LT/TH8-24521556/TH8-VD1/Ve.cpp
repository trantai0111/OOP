// Cài đặt lớp cơ sở Ve
#include "Ve.h"

void Ve::nhap() {
    cout << "Nhap ma ve: "; getline(cin, maVe);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap nam sinh: "; cin >> namSinh;
    cout << "Nhap so tro choi: "; cin >> soTroChoi;
    cin.ignore();
}

void Ve::xuat() const {
    cout << "Ma ve: " << maVe << ", Ho ten: " << hoTen << ", Nam sinh: " << namSinh << ", So tro choi: " << soTroChoi << endl;
}