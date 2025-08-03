// Cài đặt lớp cơ sở Dat
#include "Dat.h"
#include <iostream>
using namespace std;

void Dat::nhap() {
    cout << "Nhap so GCN: "; getline(cin, soGCN);
    nguoi.nhap();
    cout << "Nhap so thua: "; cin >> soThua;
    cout << "Nhap so to: "; cin >> soTo; cin.ignore();
    cout << "Nhap dia chi: "; getline(cin, diaChi);
    cout << "Nhap dien tich: "; cin >> dienTich; cin.ignore();
    cout << "Nhap ngay cap: "; getline(cin, ngayCap);
    cout << "Nhap don gia thue: "; cin >> donGiaThue; cin.ignore();
}

void Dat::xuat() const {
    cout << "So GCN: " << soGCN << ", Dia chi: " << diaChi << ", Dien tich: " << dienTich << endl;
    nguoi.xuat();
}