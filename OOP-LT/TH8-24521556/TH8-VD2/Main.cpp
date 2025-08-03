#include <iostream>
#include <vector>
#include <iomanip>
#include "LapTrinhVien.h"
#include "KiemChungVien.h"
using namespace std;

int main() {
    vector<NhanVien*> ds;
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n; cin.ignore();

    for (int i = 0; i < n; ++i) {
        cout << "\n1. Lap trinh vien\n2. Kiem chung vien\nChon loai: ";
        int loai; cin >> loai; cin.ignore();
        NhanVien* nv = nullptr;
        if (loai == 1) nv = new LapTrinhVien;
        else nv = new KiemChungVien;
        nv->nhap();
        ds.push_back(nv);
    }

    cout << "\n=== Danh sach nhan vien ===\n";
    for (auto nv : ds) nv->xuat();

    double tongLuong = 0;
    for (auto nv : ds) tongLuong += nv->tinhLuong();
    double trungBinh = tongLuong / ds.size();

    cout << "\nNhan vien co luong thap hon trung binh:\n";
    for (auto nv : ds)
        if (nv->tinhLuong() < trungBinh) nv->xuat();

    double minLuong;
    cout << "\nNhap muc luong toi thieu: ";
    cin >> minLuong;

    cout << "Nhan vien co luong <= " << minLuong << ":\n";
    for (auto nv : ds)
        if (nv->tinhLuong() <= minLuong) nv->xuat();

    for (auto nv : ds) delete nv;
    return 0;
}