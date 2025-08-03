#include "DaThuc.h"
#include <iostream>
using namespace std;

int main() {
    DaThuc f, g;

    cout << "Nhap da thuc f(x):\n";
    cin >> f;
    cout << "Nhap da thuc g(x):\n";
    cin >> g;

    cout << "\nf(x) = " << f << endl;
    cout << "g(x) = " << g << endl;

    DaThuc tong = f + g;
    DaThuc hieu = f - g;
    DaThuc tich = f * g;

    cout << "\nf(x) + g(x) = " << tong << endl;
    cout << "f(x) - g(x) = " << hieu << endl;
    cout << "f(x) * g(x) = " << tich << endl;

    double x;
    cout << "\nNhap x de tinh f(x): ";
    cin >> x;
    cout << "f(" << x << ") = " << f(x) << endl;

    return 0;
}
