#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <vector>

class CVector {
private:
    std::vector<double> data;

public:
    CVector();
    CVector(int n, double val = 0);
    CVector(const std::vector<double>& v);

    int size() const;

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    double operator*(const CVector& other) const; // tích vô hướng

    double& operator[](int i);
    const double& operator[](int i) const;

    friend std::ostream& operator<<(std::ostream& os, const CVector& v);
    friend std::istream& operator>>(std::istream& is, CVector& v);
};

#endif
