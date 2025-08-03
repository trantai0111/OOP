// Khai báo lớp NguoiSoHuu
#ifndef NGUOISOHUU_H
#define NGUOISOHUU_H
#include <string>
using namespace std;

class NguoiSoHuu {
private:
    string hoTen;
    int namSinh;
    string cmnd;
    string diaChi;
public:
    void nhap();
    void xuat() const;
};

#endif