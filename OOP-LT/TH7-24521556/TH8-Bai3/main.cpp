#include "TruongDH.h"

int main() {
    TruongDH truong;
    int chon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xuat danh sach sinh vien\n";
        cout << "3. Xuat sinh vien du dieu kien tot nghiep\n";
        cout << "4. Xuat sinh vien khong du dieu kien tot nghiep\n";
        cout << "5. SV DH diem TB cao nhat\n";
        cout << "6. SV CD diem TB cao nhat\n";
        cout << "7. Dem sinh vien khong tot nghiep\n";
        cout << "0. Thoat\n";
        cout << "Chon: "; cin >> chon;

        switch (chon) {
        case 1: truong.NhapDS(); break;
        case 2: truong.XuatDS(); break;
        case 3: truong.XuatDSTotNghiep(); break;
        case 4: truong.XuatDSKhongTotNghiep(); break;
        case 5: truong.DSSVDH_DiemTBCaoNhat(); break;
        case 6: truong.DSSVCD_DiemTBCaoNhat(); break;
        case 7: truong.DemKhongTotNghiep(); break;
        }
    } while (chon != 0);

    return 0;
}
