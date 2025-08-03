#include "matran.h"
int main() {
    MATRAN mt;
    int chon;
    do {
        cout << "\nCHUONG TRINH XU LY MA TRAN------\n";
        cout << "1. Nhap ma tran\n";
        cout << "2. Phat sinh ma tran\n";
        cout << "3. Xuat ma tran\n";
        cout << "4. Liet ke so nguyen to\n";
        cout << "5. Dem so chinh phuong\n";
        cout << "6. Tong so hoan thien tren dong k\n";
        cout << "7. TBC so doi xung tren cot k\n";
        cout << "8. Sap xep giam dan\n";
        cout << "9. Sap xep tang tren dong k\n";
        cout << "0. Thoat\n";
        cout << "Ban chon: ";
        cin >> chon;
        switch (chon) {
        case 1:
            cin >> mt;
            break;
        case 2:
            mt.PhatSinh();
            break;
        case 3:
            cout << mt;
            break;
        case 4:
            mt.LietKeSNT();
            break;
        case 5:
            cout << "So luong SCP: " << mt.DemSCP() << endl;
            break;
        case 6: {
            int k;
            cout << "Nhap dong k: ";
            cin >> k;
            cout << "Tong SHT dong " << k << ": " << mt.TinhTongSHTTrenDong(k) << endl;
            break;
        }
        case 7: {
            int k;
            cout << "Nhap cot k: ";
            cin >> k;
            cout << "TBC SDX cot " << k << ": " << mt.TinhTBCongSDXTrenCot(k) << endl;
            break;
        }
        case 8:
            mt.SapXepGiam();
            break;
        case 9: {
            int k;
            cout << "Nhap dong k: ";
            cin >> k;
            mt.SapXepTangDong(k);
            break;
        }
        case 0:
            cout << "Dang thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);
    return 0;
}
