#include "tamgiac.h"

int TAMGIAC::dem = 0;

TAMGIAC::~TAMGIAC() {
    cout << "Da huy 1 tam giac => Con " << --dem << " tam giac\n";
}

TAMGIAC::TAMGIAC() : A(0, 0), B(1, 0), C(0, 1) {
    cout << "Goi ham thiet lap TAMGIAC::TAMGIAC() => Co " << ++dem << " tam giac\n";
}

TAMGIAC::TAMGIAC(const DIEM& A, const DIEM& B, const DIEM& C) : A(A), B(B), C(C) {
    cout << "Goi ham thiet lap TAMGIAC::TAMGIAC(const DIEM& A, const DIEM& B, const DIEM& C) => Co " << ++dem << " tam giac\n";
}

TAMGIAC::TAMGIAC(double xA, double yA, double xB, double yB, double xC, double yC)
    : A(xA, yA), B(xB, yB), C(xC, yC) {
    cout << "Goi ham thiet lap TAMGIAC::TAMGIAC(double xA, double yA, double xB, double yB, double xC, double yC) => Co " << ++dem << " tam giac\n";
}

TAMGIAC::TAMGIAC(const TAMGIAC& tg) : A(tg.A), B(tg.B), C(tg.C) {
    cout << "Goi ham thiet lap TAMGIAC::TAMGIAC(const TAMGIAC& tg) => Co " << ++dem << " tam giac\n";
}

TAMGIAC& TAMGIAC::operator=(const TAMGIAC& tg) {
    cout << "Goi ham nap chong toan tu gan TAMGIAC::operator=(const TAMGIAC&)\n";
    A = tg.A;
    B = tg.B;
    C = tg.C;
    return *this;
}

DIEM TAMGIAC::GetA() const {
    return A;
}

DIEM TAMGIAC::GetB() const {
    return B;
}

DIEM TAMGIAC::GetC() const {
    return C;
}

int TAMGIAC::GetDem() {
    return dem;
}

void TAMGIAC::SetA(const DIEM& A) {
    this->A = A;
}

void TAMGIAC::SetB(const DIEM& B) {
    this->B = B;
}

void TAMGIAC::SetC(const DIEM& C) {
    this->C = C;
}

void TAMGIAC::Nhap() {
    cout << "Nhap lan luot toa do 3 diem tam giac: \n";
    A.Nhap();
    B.Nhap();
    C.Nhap();
}

void TAMGIAC::Xuat() const {
    cout << "Tam giac qua 3 dinh A(" << A << "), B(" << B << "), C(" << C << ")";
}

istream& operator>>(istream& is, TAMGIAC& tg) {
    tg.Nhap();
    return is;
}

ostream& operator<<(ostream& os, const TAMGIAC& tg) {
    tg.Xuat();
    return os;
}

bool TAMGIAC::KiemTraTGHopLe() const {
    return A.KiemTraTGHopLe(B, C);
}

double TAMGIAC::TinhChuVi() const {
    return A.TinhChuVi(B, C);
}

double TAMGIAC::TinhDienTich() const {
    return A.TinhDienTich(B, C);
}

string TAMGIAC::PhanLoai() const {
    return A.PhanLoaiTG(B, C);
}
