#include "mang1c.h"
#include <iostream>
using namespace std;

void main() {
    MANG1C m1c;
    int chon;
    do {
        cout << "CHUONG TRINH XU LY MANG 1 CHIEU------\n";
        cout << "1. Nhap mang\n";
        cout << "2. Phat sinh mang\n";
        cout << "3. Xuat mang\n";
        cout << "4. Cap nhat so phan tu mang goi ham SetN(n)\n";
        cout << "5. Liet ke cac phan tu la SNT\n";
        cout << "6. Dem so luong cac phan tu la SCP\n";
        cout << "7. Tinh tong gia tri cac phan tu la SHT\n";
        cout << "8. Tinh TB cong gia tri cac phan tu la SDX\n";
        cout << "9. Kiem tra mang toan phan tu le\n";
        cout << "10. Tim phan tu chan be nhat\n";
        cout << "11. Sap xep mang tang dan\n";
        cout << "12. Xoa phan tu tai vi tri\n";
        cout << "13. Them phan tu tai vi tri\n";
        cout << "14. Xoa mang\n";
        cout << "15. Cap nhat gia tri phan tu tai vi tri\n";
        cout << "16. Tim kiem tuyen tinh\n";
        cout << "17. Tim kiem nhi phan\n";
        cout << "0. Thoat CT\n";
        cout << "Ban chon: ";
        cin >> chon;

        switch (chon) {
        case 0:
            cout << "Dang thoat CT\n";
            break;
        case 1:
            cin >> m1c;
            break;
        case 2:
            m1c.PhatSinh();
            break;
        case 3:
            cout << m1c;
            break;
        case 4: {
            int n;
            cout << "Nhap so phan tu moi: ";
            cin >> n;
            m1c.SetN(n);
            break;
        }
        case 5:
            m1c.LietKeSNT();
            break;
        case 6:
            cout << "So luong SCP: " << m1c.DemSCP() << endl;
            break;
        case 7:
            cout << "Tong SHT: " << m1c.TinhTongSHT() << endl;
            break;
        case 8:
            cout << "TBC SDX: " << m1c.TinhTBCongSDX() << endl;
            break;
        case 9:
            cout << (m1c.KiemTraMangle() ? "Toan le" : "Khong toan le") << endl;
            break;
        case 10:
            cout << "Chan be nhat: " << m1c.TimChanBeNhat() << endl;
            break;
        case 11:
            m1c.SapXepMangTang();
            break;
        case 12: {
            int vt;
            cout << "Nhap vi tri can xoa: ";
            cin >> vt;
            m1c.XoaTaiVT(vt);
            break;
        }
        case 13: {
            int vt, gt;
            cout << "Nhap vi tri va gia tri can them: ";
            cin >> vt >> gt;
            m1c.ThemTaiVT(vt, gt);
            break;
        }
        case 14:
            m1c.SetN(0);
            break;
        case 15: {
            int vt, gt;
            cout << "Nhap vi tri va gia tri moi: ";
            cin >> vt >> gt;
            m1c.CapNhatGiaTriTaiVT(vt, gt);
            break;
        }
        case 16: {
            int gt;
            cout << "Nhap gia tri can tim: ";
            cin >> gt;
            cout << "Vi tri: " << m1c.TimKiemTuyenTinh(gt) << endl;
            break;
        }
        case 17: {
            int gt;
            cout << "Nhap gia tri can tim: ";
            cin >> gt;
            cout << "Vi tri: " << m1c.TimKiemNhiPhan(gt) << endl;
            break;
        }
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);
}
