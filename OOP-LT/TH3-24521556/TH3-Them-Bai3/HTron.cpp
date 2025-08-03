#include "HTron.h"
#include <iostream>
using namespace std;

int HTRON::dem = 0;

// Constructor mặc định
HTRON::HTRON() : O(), R(1) {
    dem++;
}

// Constructor có tham số
HTRON::HTRON(const DIEM& o, float r) : O(o), R(r) {
    dem++;
}

// Destructor
HTRON::~HTRON() {
    dem--;
}

// Getter & Setter
DIEM HTRON::getO() const { return O; }
float HTRON::getR() const { return R; }
void HTRON::setO(const DIEM& o) { O = o; }
void HTRON::setR(float r) { R = r; }

// Nhập hình tròn
void HTRON::Nhap() {
    cout << "Nhap tam hinh tron:\n";
    O.Nhap();
    do {
        cout << "Nhap ban kinh R > 0: ";
        cin >> R;
    } while (R <= 0);
}

// Xuất hình tròn
void HTRON::Xuat() const {
    cout << "Tam: ";
    O.Xuat();
    cout << ", Ban kinh: " << R;
}

// Di chuyển hình tròn
void HTRON::DiChuyen(float dx, float dy) {
    O.DiChuyen(dx, dy);
}

// Tính chu vi
float HTRON::TinhChuVi() const {
    return 2 * 3.1415926535 * R;
}

// Tính diện tích
float HTRON::TinhDienTich() const {
    return 3.1415926535 * R * R;
}

// Kiểm tra hợp lệ
bool HTRON::KiemTraHopLe() const {
    return R > 0;
}

// Trả về số lượng hình tròn
int HTRON::getSoLuongHinhTron() {
    return dem;
}
