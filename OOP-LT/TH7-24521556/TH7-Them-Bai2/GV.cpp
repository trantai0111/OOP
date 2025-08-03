#include "GV.h"

GV::~GV() {
    cout << "Da huy 1 GV\n";
}

GV::GV(string ms, string ht, string khoa, int sobb)
    : DTXS(ms, ht, khoa), sobb(sobb) {
}

int GV::GetSoBB() {
    return sobb;
}

void GV::SetSoBB(int bb) {
    sobb = bb;
}

void GV::Nhap() {
    DTXS::Nhap();
    cout << "Nhap so bai bao: ";
    cin >> sobb;
}

void GV::Xuat() {
    DTXS::Xuat();
    cout << "\tBB: " << sobb << endl;
}

long GV::TinhTienThuong() {
    return 500000 * sobb ;
}

string GV::GetLoai() {
    return "GV";
}
