#include "Vehicle.h"

int main() {
    // Tạo các đối tượng
    Vehicle xe1("Nguyen Van A", "Xe may", 30000, 150);
    Vehicle xe2("Tran Thi B", "O to", 500000, 250);
    Vehicle xe3;

    // Nhập thông tin cho xe3
    cout << "Nhap thong tin xe3:\n";
    xe3.Nhap();

    // Xuất thông tin các xe
    cout << "\nDanh sach xe:\n";
    cout << left << setw(15) << "Chu xe" << setw(15) << "Loai xe" << setw(12) << "Tri gia"
        << setw(10) << "Dung tich" << setw(10) << "Thue" << endl;
    xe1.Xuat();
    xe2.Xuat();
    xe3.Xuat();

    return 0;
}
