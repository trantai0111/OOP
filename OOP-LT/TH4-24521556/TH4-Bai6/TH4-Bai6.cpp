#include "CVector.h"
#include "CMatrix.h"
#include <iostream>
using namespace std;

int main() {
    CMatrix A, B;
    CVector v;

    cout << "Nhap ma tran A:\n";
    cin >> A;

    cout << "Nhap vector v:\n";
    cin >> v;

    cout << "\nA * v = " << A * v << endl;

    cout << "\nNhap ma tran B cung kich thuoc tuong thich voi A de nhan:\n";
    cin >> B;

    cout << "\nA * B = \n" << A * B;

    return 0;
}
