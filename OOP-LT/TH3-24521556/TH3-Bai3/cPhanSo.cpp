#include "cPhanSo.h"

int UCLN(int a, int b) {
    if (b == 0) return abs(a);
    return UCLN(b, a % b);
}

cPhanSo::cPhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = (mau == 0) ? 1 : mau;
    RutGon();
}

void cPhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> tu;
    do {
        cout << "Nhap mau (khac 0): ";
        cin >> mau;
        if (mau == 0)
            cout << "Mau khong hop le! Nhap lai.\n";
    } while (mau == 0);
    RutGon();
}

void cPhanSo::Xuat() const {
    cout << tu << "/" << mau;
}

int cPhanSo::LayTu() const {
    return tu;
}

int cPhanSo::LayMau() const {
    return mau;
}

void cPhanSo::RutGon() {
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

float cPhanSo::GiaTriThuc() const {
    return (float)tu / mau;
}

cPhanSo cPhanSo::Cong(const cPhanSo& ps) const {
    int tuMoi = tu * ps.mau + ps.tu * mau;
    int mauMoi = mau * ps.mau;
    return cPhanSo(tuMoi, mauMoi);
}

bool cPhanSo::LonHon(const cPhanSo& ps) const {
    return GiaTriThuc() > ps.GiaTriThuc();
}

bool cPhanSo::NhoHon(const cPhanSo& ps) const {
    return GiaTriThuc() < ps.GiaTriThuc();
}

bool LaNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}
