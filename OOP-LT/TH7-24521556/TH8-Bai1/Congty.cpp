#include "CONGTY.h"
#include <iostream>
using namespace std;

CONGTY::CONGTY() {
    ds = nullptr;
    n = 0;
}

CONGTY::~CONGTY() {
    for (int i = 0; i < n; ++i) {
        delete ds[i];
    }
    delete[] ds;
}

void CONGTY::Nhap() {
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore();
    ds = new NhanVien * [n];

    for (int i = 0; i < n; ++i) {
        int loai;
        cout << "\nNhap loai nhan vien (1. NVVP, 2. NVSX): ";
        cin >> loai;
        cin.ignore();

        if (loai == 1) ds[i] = new NVVP();
        else ds[i] = new NVSX();

        ds[i]->Nhap();
    }
}

void CONGTY::Xuat() {
    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    for (int i = 0; i < n; ++i) {
        ds[i]->Xuat();
        cout << "\tLuong: " << ds[i]->TinhLuong() << endl;
    }
}

long CONGTY::TinhTongLuong() {
    long tong = 0;
    for (int i = 0; i < n; ++i) {
        tong += ds[i]->TinhLuong();
    }
    return tong;
}

void CONGTY::TinhLuongTungNhanVien() {
    cout << "\n=== LUONG NHAN VIEN ===\n";
    for (int i = 0; i < n; ++i) {
        cout << ds[i]->GetHoTen() << ": " << ds[i]->TinhLuong() << endl;
    }
}

void CONGTY::TimNVSXLuongThapNhat() {
    NVSX* min = nullptr;
    for (int i = 0; i < n; ++i) {
        NVSX* sx = dynamic_cast<NVSX*>(ds[i]);
        if (sx) {
            if (!min || sx->TinhLuong() < min->TinhLuong()) {
                min = sx;
            }
        }
    }
    if (min) {
        cout << "\nNhan vien san xuat co luong thap nhat:\n";
        min->Xuat();
        cout << "\tLuong: " << min->TinhLuong() << endl;
    }
}

void CONGTY::TimNVVPTuoiCaoNhat() {
    NVVP* max = nullptr;
    for (int i = 0; i < n; ++i) {
        NVVP* vp = dynamic_cast<NVVP*>(ds[i]);
        if (vp) {
            if (!max || vp->GetTuoi() > max->GetTuoi()) {
                max = vp;
            }
        }
    }
    if (max) {
        cout << "\nNhan vien van phong co tuoi cao nhat:\n";
        max->Xuat();
        cout << "\tTuoi: " << max->GetTuoi() << endl;
    }
}
