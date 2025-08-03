#include "matran.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

MATRAN::MATRAN() : sd(0), sc(0), p(nullptr) {}

MATRAN::MATRAN(int d, int c) : sd(d), sc(c) {
    p = new int* [sd];
    for (int i = 0; i < sd; ++i)
        p[i] = new int[sc] {};
}

MATRAN::MATRAN(const MATRAN& m) : sd(m.sd), sc(m.sc) {
    p = new int* [sd];
    for (int i = 0; i < sd; ++i) {
        p[i] = new int[sc];
        for (int j = 0; j < sc; ++j)
            p[i][j] = m.p[i][j];
    }
}

MATRAN::~MATRAN() {
    for (int i = 0; i < sd; ++i)
        delete[] p[i];
    delete[] p;
}

MATRAN& MATRAN::operator=(const MATRAN& m) {
    if (this != &m) {
        for (int i = 0; i < sd; ++i) delete[] p[i];
        delete[] p;

        sd = m.sd;
        sc = m.sc;
        p = new int* [sd];
        for (int i = 0; i < sd; ++i) {
            p[i] = new int[sc];
            for (int j = 0; j < sc; ++j)
                p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

int MATRAN::GetSD() const { return sd; }
int MATRAN::GetSC() const { return sc; }
int MATRAN::GetGT(int i, int j) const { return p[i][j]; }
void MATRAN::SetSD(int d) { sd = d; }
void MATRAN::SetSC(int c) { sc = c; }
void MATRAN::SetGT(int i, int j, int gt) { p[i][j] = gt; }

void MATRAN::Nhap() {
    cout << "Nhap so dong: "; cin >> sd;
    cout << "Nhap so cot: "; cin >> sc;
    p = new int* [sd];
    for (int i = 0; i < sd; ++i) {
        p[i] = new int[sc];
        for (int j = 0; j < sc; ++j) {
            cout << "p[" << i << "][" << j << "] = ";
            cin >> p[i][j];
        }
    }
}

void MATRAN::Xuat() const {
    for (int i = 0; i < sd; ++i) {
        for (int j = 0; j < sc; ++j)
            cout << setw(4) << p[i][j];
        cout << endl;
    }
}

istream& operator>>(istream& is, MATRAN& m) {
    m.Nhap();
    return is;
}

ostream& operator<<(ostream& os, const MATRAN& m) {
    m.Xuat();
    return os;
}

void MATRAN::PhatSinh(int mi, int ma) {
    srand(time(NULL));
    for (int i = 0; i < sd; ++i)
        for (int j = 0; j < sc; ++j)
            p[i][j] = mi + rand() % (ma - mi + 1);
}

bool MATRAN::KiemTraSNT(int x) const {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

bool MATRAN::KiemTraSCP(int x) const {
    int r = sqrt(x);
    return r * r == x;
}

bool MATRAN::KiemTraSHT(int x) const {
    int sum = 0;
    for (int i = 1; i <= x / 2; ++i)
        if (x % i == 0) sum += i;
    return sum == x;
}

bool MATRAN::KiemTraSDX(int x) const {
    int y = x, rev = 0;
    while (y) {
        rev = rev * 10 + y % 10;
        y /= 10;
    }
    return x == rev;
}

void MATRAN::LietKeSNT() const {
    for (int i = 0; i < sd; ++i)
        for (int j = 0; j < sc; ++j)
            if (KiemTraSNT(p[i][j])) cout << p[i][j] << " ";
    cout << endl;
}

int MATRAN::DemSCP() const {
    int count = 0;
    for (int i = 0; i < sd; ++i)
        for (int j = 0; j < sc; ++j)
            if (KiemTraSCP(p[i][j])) ++count;
    return count;
}

int MATRAN::TinhTongSHTTrenDong(int k) const {
    int sum = 0;
    if (k >= 0 && k < sd)
        for (int j = 0; j < sc; ++j)
            if (KiemTraSHT(p[k][j])) sum += p[k][j];
    return sum;
}

double MATRAN::TinhTBCongSDXTrenCot(int k) const {
    int sum = 0, count = 0;
    if (k >= 0 && k < sc)
        for (int i = 0; i < sd; ++i)
            if (KiemTraSDX(p[i][k])) {
                sum += p[i][k];
                ++count;
            }
    return count ? (double)sum / count : 0;
}

void MATRAN::SapXepGiam() {
    int* temp = new int[sd * sc];
    int idx = 0;
    for (int i = 0; i < sd; ++i)
        for (int j = 0; j < sc; ++j)
            temp[idx++] = p[i][j];
    sort(temp, temp + sd * sc, greater<int>());
    idx = 0;
    for (int i = 0; i < sd; ++i)
        for (int j = 0; j < sc; ++j)
            p[i][j] = temp[idx++];
    delete[] temp;
}

void MATRAN::SapXepTangDong(int k) {
    if (k >= 0 && k < sd)
        sort(p[k], p[k] + sc);
}
