#include "NV.h"

NV::~NV() {
    cout << "Da huy 1 NV\n";
}

NV::NV(string ms, string ht, string khoa, int skkn)
    : DTXS(ms, ht, khoa), skkn(skkn) {
}

int NV::GetSoSKKN() {
    return skkn;
}

void NV::SetSoSKKN(int s) {
    skkn = s;
}

void NV::Nhap() {
    DTXS::Nhap();
    cout << "Nhap so SKKN: ";
    cin >> skkn;
}

void NV::Xuat() {
    DTXS::Xuat();
    cout << "\tSKKN: " << skkn << endl;
}

long NV::TinhTienThuong() {
    return 500000 * skkn;
}

string NV::GetLoai() {
    return "NV";
}
