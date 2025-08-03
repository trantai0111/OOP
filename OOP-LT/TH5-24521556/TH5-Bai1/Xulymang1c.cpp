// xulymang1c.cpp
#include "mang1c.h"
#include <cmath>
#include <ctime>
#include <algorithm>

// Kiểm tra số nguyên tố
bool MANG1C::KiemTraSNT(int x) const {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i)
        if (x % i == 0) return false;
    return true;
}

// Kiểm tra số chính phương
bool MANG1C::KiemTraSCP(int x) const {
    int sq = sqrt(x);
    return sq * sq == x;
}

// Kiểm tra số hoàn thiện
bool MANG1C::KiemTraSHT(int x) const {
    if (x <= 0) return false;
    int sum = 0;
    for (int i = 1; i < x; ++i)
        if (x % i == 0) sum += i;
    return sum == x;
}

// Kiểm tra số đối xứng
bool MANG1C::KiemTraSDX(int x) const {
    int rev = 0, tmp = x;
    while (tmp) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return rev == x;
}

MANG1C::MANG1C() : n(0), a(nullptr) {}

MANG1C::MANG1C(int n) : n(n) {
    a = new int[n] {};
}

MANG1C::MANG1C(int n, int m) : n(n) {
    a = new int[n];
    for (int i = 0; i < n; ++i) a[i] = m;
}

MANG1C::MANG1C(const MANG1C& other) : n(other.n) {
    a = new int[n];
    for (int i = 0; i < n; ++i) a[i] = other.a[i];
}

MANG1C::~MANG1C() {
    delete[] a;
}

MANG1C& MANG1C::operator=(const MANG1C& other) {
    if (this != &other) {
        delete[] a;
        n = other.n;
        a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = other.a[i];
    }
    return *this;
}

int MANG1C::GetN() const { return n; }
int MANG1C::GetA(int i) const { return a[i]; }
void MANG1C::SetN(int size) {
    delete[] a;
    n = size;
    a = new int[n] {};
}
void MANG1C::SetA(const MANG1C& other) {
    if (n != other.n) {
        delete[] a;
        n = other.n;
        a = new int[n];
    }
    for (int i = 0; i < n; ++i) a[i] = other.a[i];
}

void MANG1C::Nhap() {
    cout << "Nhap so phan tu: "; cin >> n;
    delete[] a;
    a = new int[n];
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void MANG1C::Xuat() const {
    for (int i = 0; i < n; ++i)
        cout << setw(5) << a[i];
    cout << endl;
}

istream& operator>>(istream& is, MANG1C& m) {
    m.Nhap();
    return is;
}

ostream& operator<<(ostream& os, const MANG1C& m) {
    m.Xuat();
    return os;
}

void MANG1C::PhatSinh(int min, int max) {
    srand(time(0));
    for (int i = 0; i < n; ++i)
        a[i] = min + rand() % (max - min + 1);
}

void MANG1C::LietKeSNT() const {
    for (int i = 0; i < n; ++i)
        if (KiemTraSNT(a[i]))
            cout << a[i] << " ";
    cout << endl;
}

int MANG1C::DemSCP() const {
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (KiemTraSCP(a[i])) ++count;
    return count;
}

int MANG1C::TinhTongSHT() const {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        if (KiemTraSHT(a[i])) sum += a[i];
    return sum;
}

double MANG1C::TinhTBCongSDX() const {
    int sum = 0, count = 0;
    for (int i = 0; i < n; ++i)
        if (KiemTraSDX(a[i])) {
            sum += a[i];
            ++count;
        }
    return count == 0 ? 0 : (double)sum / count;
}

bool MANG1C::KiemTraMangle() const {
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0) return false;
    return true;
}

int MANG1C::TimChanBeNhat() const {
    int min = INT_MAX;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0 && a[i] < min)
            min = a[i];
    return min == INT_MAX ? -1 : min;
}

void MANG1C::SapXepMangTang() {
    sort(a, a + n);
}

void MANG1C::XoaTaiVT(int vt) {
    if (vt < 0 || vt >= n) return;
    for (int i = vt; i < n - 1; ++i)
        a[i] = a[i + 1];
    --n;
}

void MANG1C::ThemTaiVT(int vt, int gt) {
    if (vt < 0 || vt > n) return;
    int* newA = new int[n + 1];
    for (int i = 0; i < vt; ++i) newA[i] = a[i];
    newA[vt] = gt;
    for (int i = vt; i < n; ++i) newA[i + 1] = a[i];
    delete[] a;
    a = newA;
    ++n;
}

void MANG1C::CapNhatGiaTriTaiVT(int vt, int gt) {
    if (vt >= 0 && vt < n) a[vt] = gt;
}

int MANG1C::TimKiemTuyenTinh(int gt) const {
    for (int i = 0; i < n; ++i)
        if (a[i] == gt) return i;
    return -1;
}

int MANG1C::TimKiemNhiPhan(int gt) const {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == gt) return m;
        else if (a[m] < gt) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
