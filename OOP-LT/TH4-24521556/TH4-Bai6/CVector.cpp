#include "CVector.h"
#include <iostream>
using namespace std;

CVector::CVector() {}

CVector::CVector(int n, double val) : data(n, val) {}

CVector::CVector(const vector<double>& v) : data(v) {}

int CVector::size() const {
    return data.size();
}

CVector CVector::operator+(const CVector& other) const {
    CVector res(size());
    for (int i = 0; i < size(); ++i)
        res[i] = data[i] + other[i];
    return res;
}

CVector CVector::operator-(const CVector& other) const {
    CVector res(size());
    for (int i = 0; i < size(); ++i)
        res[i] = data[i] - other[i];
    return res;
}

double CVector::operator*(const CVector& other) const {
    double sum = 0;
    for (int i = 0; i < size(); ++i)
        sum += data[i] * other[i];
    return sum;
}

double& CVector::operator[](int i) {
    return data[i];
}

const double& CVector::operator[](int i) const {
    return data[i];
}

ostream& operator<<(ostream& os, const CVector& v) {
    for (double val : v.data)
        os << val << " ";
    return os;
}

istream& operator>>(istream& is, CVector& v) {
    int n;
    cout << "Nhap so chieu vector: ";
    is >> n;
    v.data.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "v[" << i << "] = ";
        is >> v[i];
    }
    return is;
}
