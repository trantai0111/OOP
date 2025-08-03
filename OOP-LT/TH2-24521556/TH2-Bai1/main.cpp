#include "Xulyphanso.cpp"

int main() {
    cout << "Nhap phan so 1 (a hoac a/b): ";
    PhanSo ps1;     cin >> ps1;

    cout << "Nhap phan so 2 (a hoac a/b): ";
    PhanSo ps2;     cin >> ps2;

    cout << "--> Phan so 1 : " << ps1 << '\n';
    cout << "--> Phan so 2 : " << ps2 << '\n';
    cout << "--> Tong 2 phan so: " << ps1 + ps2 << '\n';
    cout << "--> Hieu 2 phan so: " << ps1 - ps2 << '\n';
    cout << "--> Tich 2 phan so: " << ps1 * ps2 << '\n';
    cout << "--> Thuong 2 phan so: " << ps1 / ps2 << '\n';

    return 0;

}