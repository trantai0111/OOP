#include "DTXS.h"
#include <iostream>
using namespace std;

DTXS::~DTXS() {
    cout << "Da huy 1 DTXS\n";
}

DTXS::DTXS() {}

DTXS::DTXS(string ms, string ht, string kh) : maso(ms), hoten(ht), khoa(kh) {}

string DTXS::GetMaSo() const {
    return maso;
}

string DTXS::GetHoTen() const {
    return hoten;
}

string DTXS::GetKhoa() const {
    return khoa;
}

void DTXS::SetHoTen(string ht) {
    hoten = ht;
}

void DTXS::SetKhoa(string kh) {
    khoa = kh;
}

void DTXS::Nhap() {
    cin.ignore();
    cout << "Nhap ma so: ";
    getline(cin, maso);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap khoa: ";
    getline(cin, khoa);
}

void DTXS::Xuat() {
    cout << "MS: " << maso
        << "\tTen: " << hoten
        << "\tKhoa: " << khoa
        << "\tLoai: " << GetLoai()
        << "\tThuong: " << TinhTienThuong();
}
