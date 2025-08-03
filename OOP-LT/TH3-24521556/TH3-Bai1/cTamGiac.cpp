#include "cTamGiac.h"

int cTamGiac::dem = 0;

cTamGiac::~cTamGiac() {
    dem--;
}

cTamGiac::cTamGiac() {
    A = B = C = { 0, 0 };
    dem++;
}

cTamGiac::cTamGiac(Diem a, Diem b, Diem c) : A(a), B(b), C(c) {
    dem++;
}

cTamGiac::cTamGiac(const cTamGiac& tg) : A(tg.A), B(tg.B), C(tg.C) {
    dem++;
}

int cTamGiac::GetDem() {
    return dem;
}

void cTamGiac::Nhap() {
    cout << "Nhap diem A (x y): "; cin >> A.x >> A.y;
    cout << "Nhap diem B (x y): "; cin >> B.x >> B.y;
    cout << "Nhap diem C (x y): "; cin >> C.x >> C.y;
}

void cTamGiac::Xuat() const {
    cout << "A(" << A.x << ", " << A.y << "), ";
    cout << "B(" << B.x << ", " << B.y << "), ";
    cout << "C(" << C.x << ", " << C.y << ")\n";
}

double cTamGiac::DoDai(Diem P1, Diem P2) const {
    return sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
}

bool cTamGiac::LaTamGiac() const {
    double a = DoDai(B, C);
    double b = DoDai(A, C);
    double c = DoDai(A, B);
    return (a + b > c && a + c > b && b + c > a);
}

string cTamGiac::LoaiTamGiac() const {
    if (!LaTamGiac()) return "Khong phai tam giac";

    double a = DoDai(B, C);
    double b = DoDai(A, C);
    double c = DoDai(A, B);

    bool vuong = fabs(a * a + b * b - c * c) < 1e-6 ||
        fabs(a * a + c * c - b * b) < 1e-6 ||
        fabs(b * b + c * c - a * a) < 1e-6;

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6) return "Tam giac deu";
    if (vuong && (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)) return "Tam giac vuong can";
    if (vuong) return "Tam giac vuong";
    if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6) return "Tam giac can";

    return "Tam giac thuong";
}

double cTamGiac::ChuVi() const {
    return DoDai(A, B) + DoDai(B, C) + DoDai(C, A);
}

double cTamGiac::DienTich() const {
    return 0.5 * fabs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}

void cTamGiac::TinhTien(double dx, double dy) {
    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}

void cTamGiac::PhongTo(double k) {
    A.x *= k; A.y *= k;
    B.x *= k; B.y *= k;
    C.x *= k; C.y *= k;
}

void cTamGiac::ThuNho(double k) {
    if (k != 0) PhongTo(1.0 / k);
}

void cTamGiac::Quay(double goc) {
    double rad = goc * 3.14 / 180.0;

    auto QuayDiem = [rad](Diem& d) {
        double x = d.x * cos(rad) - d.y * sin(rad);
        double y = d.x * sin(rad) + d.y * cos(rad);
        d.x = x;
        d.y = y;
        };

    QuayDiem(A); QuayDiem(B); QuayDiem(C);
}

istream& operator>>(istream& is, cTamGiac& tg) {
    cout << "Nhap diem A (x y): "; is >> tg.A.x >> tg.A.y;
    cout << "Nhap diem B (x y): "; is >> tg.B.x >> tg.B.y;
    cout << "Nhap diem C (x y): "; is >> tg.C.x >> tg.C.y;
    return is;
}

ostream& operator<<(ostream& os, const cTamGiac& tg) {
    os << "A(" << tg.A.x << ", " << tg.A.y << "), "
        << "B(" << tg.B.x << ", " << tg.B.y << "), "
        << "C(" << tg.C.x << ", " << tg.C.y << ")";
    return os;
}
