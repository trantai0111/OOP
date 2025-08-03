#include "HCN.h"
#include <iostream>
using namespace std;

int HCN::dem = 0;

// Constructor mặc định
HCN::HCN() : A(0, 0), C(1, -1) {
    CapNhatB_D();
    dem++;
}

// Constructor có tham số
HCN::HCN(const DIEM& a, const DIEM& c) : A(a), C(c) {
    CapNhatB_D();
    dem++;
}

// Destructor
HCN::~HCN() {
    dem--;
}

// Getter
DIEM HCN::getA() const { return A; }
DIEM HCN::getB() const { return B; }
DIEM HCN::getC() const { return C; }
DIEM HCN::getD() const { return D; }

// Setter
void HCN::setA(const DIEM& a) { A = a; CapNhatB_D(); }
void HCN::setC(const DIEM& c) { C = c; CapNhatB_D(); }

// Cập nhật B và D dựa trên A và C
void HCN::CapNhatB_D() {
    B = DIEM(C.getX(), A.getY()); // Phải trên
    D = DIEM(A.getX(), C.getY()); // Trái dưới
}

// Nhập từ người dùng
void HCN::Nhap() {
    do {
        cout << "Nhap diem A (goc trai tren):\n";
        A.Nhap();
        cout << "Nhap diem C (goc phai duoi):\n";
        C.Nhap();
        CapNhatB_D();
        if (!KiemTraHopLe())
            cout << "Toa do khong hop le! A phai o trai tren va C o phai duoi.\n";
    } while (!KiemTraHopLe());
}

// Xuất thông tin
void HCN::Xuat() const {
    cout << "A"; A.Xuat();
    cout << ", B"; B.Xuat();
    cout << ", C"; C.Xuat();
    cout << ", D"; D.Xuat();
}

// Di chuyển
void HCN::DiChuyen(float dx, float dy) {
    A.DiChuyen(dx, dy);
    C.DiChuyen(dx, dy);
    CapNhatB_D();
}

// Tính chu vi
float HCN::TinhChuVi() const {
    float dai = abs(B.getX() - A.getX());
    float rong = abs(A.getY() - D.getY());
    return 2 * (dai + rong);
}

// Tính diện tích
float HCN::TinhDienTich() const {
    float dai = abs(B.getX() - A.getX());
    float rong = abs(A.getY() - D.getY());
    return dai * rong;
}

// Kiểm tra hợp lệ: A trái trên, C phải dưới
bool HCN::KiemTraHopLe() const {
    return A.getX() < C.getX() && A.getY() > C.getY();
}

// Trả về số lượng HCN đã tạo
int HCN::getSoLuongHCN() {
    return dem;
}
