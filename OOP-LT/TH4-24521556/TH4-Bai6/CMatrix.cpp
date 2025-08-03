#include "CMatrix.h"
#include <iostream>
using namespace std;

CMatrix::CMatrix() {}

CMatrix::CMatrix(int r, int c, double val) : data(r, vector<double>(c, val)) {}

int CMatrix::rows() const {
    return data.size();
}

int CMatrix::cols() const {
    return data.empty() ? 0 : data[0].size();
}

vector<double>& CMatrix::operator[](int i) {
    return data[i];
}

const vector<double>& CMatrix::operator[](int i) const {
    return data[i];
}

CMatrix CMatrix::operator+(const CMatrix& other) const {
    CMatrix res(rows(), cols());
    for (int i = 0; i < rows(); ++i)
        for (int j = 0; j < cols(); ++j)
            res[i][j] = data[i][j] + other[i][j];
    return res;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
    CMatrix res(rows(), cols());
    for (int i = 0; i < rows(); ++i)
        for (int j = 0; j < cols(); ++j)
            res[i][j] = data[i][j] - other[i][j];
    return res;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
    int r = rows(), c = other.cols(), n = cols();
    CMatrix res(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            for (int k = 0; k < n; ++k)
                res[i][j] += data[i][k] * other[k][j];
    return res;
}

CVector CMatrix::operator*(const CVector& v) const {
    int r = rows(), c = cols();
    CVector res(r);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            res[i] += data[i][j] * v[j];
    return res;
}

ostream& operator<<(ostream& os, const CMatrix& m) {
    for (const auto& row : m.data) {
        for (double val : row)
            os << val << " ";
        os << "\n";
    }
    return os;
}

istream& operator>>(istream& is, CMatrix& m) {
    int r, c;
    cout << "Nhap so hang va cot: ";
    is >> r >> c;
    m.data.resize(r, vector<double>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cout << "a[" << i << "][" << j << "] = ";
            is >> m[i][j];
        }
    return is;
}
