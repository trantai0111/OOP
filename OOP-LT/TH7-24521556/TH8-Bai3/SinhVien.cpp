#include "SinhVien.h"

void SinhVien::Nhap() {
    cin.ignore();
    cout << "Nhap ma SV: "; getline(cin, maSV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap dia chi: "; getline(cin, diaChi);
    cout << "Nhap tong tin chi: "; cin >> tongTinChi;
    cout << "Nhap diem TB: "; cin >> diemTB;
}

void SinhVien::Xuat() {
    cout << "Ma SV: " << maSV << ", Ho ten: " << hoTen << ", Dia chi: " << diaChi;
    cout << ", Tong tin chi: " << tongTinChi << ", Diem TB: " << diemTB;
}

float SinhVien::GetDiemTB() const {
    return diemTB;
}