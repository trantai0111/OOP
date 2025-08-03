#include "SoPhuc.h"

// Constructor mặc định
SoPhuc::SoPhuc() : thuc(0), ao(0) {}

// Constructor có tham số
SoPhuc::SoPhuc(double t, double a) : thuc(t), ao(a) {}

// Hàm nhập
void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}

// Hàm xuất
void SoPhuc::Xuat() const {
    cout << "(" << thuc << ", " << ao << "i)" << endl;
}

// Toán tử cộng
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
    return SoPhuc(thuc + sp.thuc, ao + sp.ao);
}

// Toán tử trừ
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
    return SoPhuc(thuc - sp.thuc, ao - sp.ao);
}

// Toán tử nhân
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
    return SoPhuc(thuc * sp.thuc - ao * sp.ao, thuc * sp.ao + ao * sp.thuc);
}

// Toán tử chia
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
    double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
    return SoPhuc((thuc * sp.thuc + ao * sp.ao) / mau, (ao * sp.thuc - thuc * sp.ao) / mau);
}
