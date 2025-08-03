#include "TruongDH.h"
#include <limits>

TruongDH::~TruongDH() {
    for (auto sv : ds) delete sv;
}

void TruongDH::NhapDS() {
    int n, loai;
    cout << "Nhap so sinh vien: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "\n1. CD | 2. DH: "; cin >> loai;
        SinhVien* sv = nullptr;
        if (loai == 1) sv = new CD();
        else sv = new DH();
        sv->Nhap();
        ds.push_back(sv);
    }
}

void TruongDH::XuatDS() {
    for (auto sv : ds) sv->Xuat();
}

void TruongDH::XuatDSTotNghiep() {
    for (auto sv : ds)
        if (sv->TotNghiep()) sv->Xuat();
}

void TruongDH::XuatDSKhongTotNghiep() {
    for (auto sv : ds)
        if (!sv->TotNghiep()) sv->Xuat();
}

void TruongDH::DSSVDH_DiemTBCaoNhat() {
    float max = -1;
    for (auto sv : ds) {
        DH* dh = dynamic_cast<DH*>(sv);
        if (dh && dh->GetDiemTB() > max) max = dh->GetDiemTB();
    }
    for (auto sv : ds) {
        DH* dh = dynamic_cast<DH*>(sv);
        if (dh && dh->GetDiemTB() == max) dh->Xuat();
    }
}

void TruongDH::DSSVCD_DiemTBCaoNhat() {
    float max = -1;
    for (auto sv : ds) {
        CD* cd = dynamic_cast<CD*>(sv);
        if (cd && cd->GetDiemTB() > max) max = cd->GetDiemTB();
    }
    for (auto sv : ds) {
        CD* cd = dynamic_cast<CD*>(sv);
        if (cd && cd->GetDiemTB() == max) cd->Xuat();
    }
}

void TruongDH::DemKhongTotNghiep() {
    int cd = 0, dh = 0;
    for (auto sv : ds) {
        if (!sv->TotNghiep()) {
            if (dynamic_cast<CD*>(sv)) ++cd;
            else if (dynamic_cast<DH*>(sv)) ++dh;
        }
    }
    cout << "So sinh vien CD khong tot nghiep: " << cd << endl;
    cout << "So sinh vien DH khong tot nghiep: " << dh << endl;
}