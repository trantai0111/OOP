#include <iostream>
#include "CONGTY.h"
using namespace std;

int main() {
    CONGTY ct;
    int choice;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Nhap danh sach nhan vien\n";
        cout << "2. Tinh luong cho tung nhan vien\n";
        cout << "3. Xuat danh sach nhan vien\n";
        cout << "4. Tinh tong luong cong ty\n";
        cout << "5. Tim nhan vien san xuat luong thap nhat\n";
        cout << "6. Tim nhan vien van phong tuoi cao nhat\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ct.Nhap();
            break;
        case 2:
            ct.TinhLuongTungNhanVien();
            break;
        case 3:
            ct.Xuat();
            break;
        case 4:
            cout << "Tong luong cong ty phai tra: " << ct.TinhTongLuong() << endl;
            break;
        case 5:
            ct.TimNVSXLuongThapNhat();
            break;
        case 6:
            ct.TimNVVPTuoiCaoNhat();
            break;
        case 0:
            cout << "Ket thuc chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }

    } while (choice != 0);

    return 0;
}
