#include "SV.h"

SV::~SV() {
    cout << "Da huy 1 SV\n";
}

SV::SV(string ms, string ht, string khoa, double tb, double rl)
    : DTXS(ms, ht, khoa), dtb(tb), drl(rl) {
}

double SV::GetDTB() {
    return dtb;
}

double SV::GetDRL() {
    return drl;
}

void SV::SetDTB(double tb) {
    while (tb < 0 || tb > 10) {
        cout << "Nhap diem trung binh: ";
        cin >> tb;
    }
    dtb = tb;
}

void SV::SetDRL(double rl) {
    while (rl < 0 || rl > 100) {
        cout << "Nhap diem ren luyen: ";
        cin >> rl;
    }
    drl = rl;
}

void SV::Nhap() {
    DTXS::Nhap();
    do {
        cout << "Nhap diem trung binh: ";
        cin >> this->dtb;
    } while (dtb < 0 || dtb > 10);

    do {
        cout << "Nhap diem ren luyen: ";
        cin >> this->drl;
    } while (drl < 0 || drl > 100);
}

void SV::Xuat() {
    DTXS::Xuat();
    cout << "\tDTB: " << dtb << "\tDRL: " << drl << endl;
}

long SV::TinhTienThuong() {
    long thuong = 0;
    if (drl >= 85)
        thuong = (dtb > 9 ? 700000 : (dtb >= 8.5 ? 500000 : 0));
    return thuong;
}

string SV::GetLoai() {
    return "SV";
}
