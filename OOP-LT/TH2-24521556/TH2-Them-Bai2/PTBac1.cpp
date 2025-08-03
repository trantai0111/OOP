#include "PTBac1.h"

// Constructor mặc định (a = 0, b = 0)
PTBac1::PTBac1() : a(0), b(0) {}

// Constructor với a = 0, b tùy ý
PTBac1::PTBac1(double b) : a(0), b(b) {}

// Constructor với a, b tùy ý
PTBac1::PTBac1(double a, double b) : a(a), b(b) {}

// Hàm nhập hệ số
void PTBac1::Nhap() {
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
}

// Hàm giải phương trình bậc 1
void PTBac1::GiaiPT() const {
    if (a == 0) {
        if (b == 0)
            cout << "Phuong trinh vo so nghiem." << endl;
        else
            cout << "Phuong trinh vo nghiem." << endl;
    }
    else {
        double x = -b / a;
        cout << "Phuong trinh co nghiem x = " << x << endl;
    }
}

// Hàm xuất phương trình
void PTBac1::Xuat() const {
    cout << "Phuong trinh: " << a << "x ";
    if (b >= 0) cout << "+ " << b;
    else cout << "- " << -b;
    cout << " = 0" << endl;

    GiaiPT();
}
