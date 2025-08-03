#include "cDSPhanSo.h"
#include <algorithm>

cDSPhanSo::cDSPhanSo() {
    ds = nullptr;
    n = 0;
}

cDSPhanSo::~cDSPhanSo() {
    delete[] ds;
}

void cDSPhanSo::Nhap() {
    cout << "Nhap so luong phan so: ";
    cin >> n;
    ds = new cPhanSo[n];
    for (int i = 0; i < n; ++i) {
        cout << "Phan so thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void cDSPhanSo::Xuat() const {
    for (int i = 0; i < n; ++i) {
        ds[i].Xuat();
        cout << "  ";
    }
    cout << endl;
}

cPhanSo cDSPhanSo::TinhTong() const {
    cPhanSo tong;
    for (int i = 0; i < n; ++i)
        tong = tong.Cong(ds[i]);
    return tong;
}

cPhanSo cDSPhanSo::TimMax() const {
    cPhanSo max = ds[0];
    for (int i = 1; i < n; ++i)
        if (ds[i].LonHon(max))
            max = ds[i];
    return max;
}

cPhanSo cDSPhanSo::TimMin() const {
    cPhanSo min = ds[0];
    for (int i = 1; i < n; ++i)
        if (ds[i].NhoHon(min))
            min = ds[i];
    return min;
}

cPhanSo cDSPhanSo::TuNguyenToMax() const {
    cPhanSo ketQua(0, 1);
    bool coNguyenTo = false;
    for (int i = 0; i < n; ++i) {
        int tu = ds[i].LayTu();
        if (LaNguyenTo(abs(tu))) {
            if (!coNguyenTo || abs(tu) > abs(ketQua.LayTu())) {
                ketQua = ds[i];
                coNguyenTo = true;
            }
        }
    }
    return ketQua;
}

void cDSPhanSo::SapXepTang() {
    sort(ds, ds + n, [](cPhanSo a, cPhanSo b) {
        return a.GiaTriThuc() < b.GiaTriThuc();
        });
}

void cDSPhanSo::SapXepGiam() {
    sort(ds, ds + n, [](cPhanSo a, cPhanSo b) {
        return a.GiaTriThuc() > b.GiaTriThuc();
        });
}
