#include "DaThuc.h"
#include <iostream>
#include <iomanip>
using namespace std;

DaThuc::DaThuc() {}

DaThuc::DaThuc(const vector<double>& hs) : heSo(hs) {
    chuanHoa();
}

void DaThuc::chuanHoa() {
    while (!heSo.empty() && heSo.back() == 0)
        heSo.pop_back();
}

int DaThuc::bac() const {
    return heSo.empty() ? -1 : static_cast<int>(heSo.size()) - 1;
}

DaThuc DaThuc::operator+(const DaThuc& other) const {
    vector<double> res(max(heSo.size(), other.heSo.size()), 0);
    for (size_t i = 0; i < heSo.size(); ++i)
        res[i] += heSo[i];
    for (size_t i = 0; i < other.heSo.size(); ++i)
        res[i] += other.heSo[i];
    return DaThuc(res);
}

DaThuc DaThuc::operator-(const DaThuc& other) const {
    vector<double> res(max(heSo.size(), other.heSo.size()), 0);
    for (size_t i = 0; i < heSo.size(); ++i)
        res[i] += heSo[i];
    for (size_t i = 0; i < other.heSo.size(); ++i)
        res[i] -= other.heSo[i];
    return DaThuc(res);
}

DaThuc DaThuc::operator*(const DaThuc& other) const {
    vector<double> res(heSo.size() + other.heSo.size() - 1, 0);
    for (size_t i = 0; i < heSo.size(); ++i)
        for (size_t j = 0; j < other.heSo.size(); ++j)
            res[i + j] += heSo[i] * other.heSo[j];
    return DaThuc(res);
}

double DaThuc::operator()(double x) const {
    double result = 0, xn = 1;
    for (double coeff : heSo) {
        result += coeff * xn;
        xn *= x;
    }
    return result;
}

ostream& operator<<(ostream& os, const DaThuc& dt) {
    int b = dt.bac();
    if (b < 0) {
        os << "0";
        return os;
    }

    for (int i = b; i >= 0; --i) {
        double hs = dt.heSo[i];
        if (hs == 0) continue;

        if (i != b && hs > 0) os << " + ";
        else if (hs < 0) os << " - ";

        if (abs(hs) != 1 || i == 0)
            os << fixed << setprecision(2) << abs(hs);

        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
    }

    return os;
}

istream& operator>>(istream& is, DaThuc& dt) {
    int bac;
    cout << "Nhap bac da thuc: ";
    is >> bac;
    dt.heSo.resize(bac + 1);
    for (int i = bac; i >= 0; --i) {
        cout << "He so bac " << i << ": ";
        is >> dt.heSo[i];
    }
    dt.chuanHoa();
    return is;
}
