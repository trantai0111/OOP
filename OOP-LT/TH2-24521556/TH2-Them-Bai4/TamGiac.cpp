#include "TamGiac.h"

// Constructor mặc định
TamGiac::TamGiac() : a(1), b(1), c(1) {}

// Constructor có tham số
TamGiac::TamGiac(double canh1, double canh2, double canh3) : a(canh1), b(canh2), c(canh3) {}
TamGiac::TamGiac(double canh1, double canh2) : a(canh1), b(canh2), c(1) {}
TamGiac::TamGiac(double canh1) : a(canh1), b(1), c(1) {}

// Hàm nhập tam giác
void TamGiac::Nhap() {
    cout << "Nhap do dai 3 canh tam giac: ";
    cin >> a >> b >> c;
}

// Hàm xuất thông tin tam giác
void TamGiac::Xuat() const {
    cout << "Tam giac co do dai 3 canh: " << a << ", " << b << ", " << c << endl;
    if (LaTamGiac()) {
        cout << "Phan loai: " << PhanLoai() << endl;
        cout << "Chu vi: " << ChuVi() << endl;
        cout << "Dien tich: " << DienTich() << endl;
    }
    else {
        cout << "Ba canh nay khong tao thanh tam giac hop le." << endl;
    }
}

// Kiểm tra tam giác hợp lệ
bool TamGiac::LaTamGiac() const {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Phân loại tam giác
string TamGiac::PhanLoai() const {
    if (!LaTamGiac()) return "Khong hop le";
    if (a == b && b == c) return "Tam giac deu";
    if (a == b || b == c || a == c) return "Tam giac can";
    if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2))
        return "Tam giac vuong";
    return "Tam giac thuong";
}

// Tính chu vi tam giác
double TamGiac::ChuVi() const {
    return LaTamGiac() ? a + b + c : 0;
}

// Tính diện tích tam giác
double TamGiac::DienTich() const {
    if (!LaTamGiac()) return 0;
    double p = ChuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
