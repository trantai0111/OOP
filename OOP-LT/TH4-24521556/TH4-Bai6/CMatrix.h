#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <vector>
#include "CVector.h"

class CMatrix {
private:
    std::vector<std::vector<double>> data;

public:
    CMatrix();
    CMatrix(int rows, int cols, double val = 0);

    int rows() const;
    int cols() const;

    std::vector<double>& operator[](int i);
    const std::vector<double>& operator[](int i) const;

    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;
    CMatrix operator*(const CMatrix& other) const;
    CVector operator*(const CVector& v) const;

    friend std::ostream& operator<<(std::ostream& os, const CMatrix& m);
    friend std::istream& operator>>(std::istream& is, CMatrix& m);
};

#endif
