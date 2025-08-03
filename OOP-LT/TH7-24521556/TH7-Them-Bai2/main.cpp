#include "TRUONGDH.h"
#include <iostream>
using namespace std;

void main() {
    TRUONGDH tr;
    int chon;
    do {
        system("cls"); // Xóa màn hình để giao diện rõ ràng hơn
        cout << "====== CT QUAN LY DOI TUONG XUAT SAC CUA TRUONG =======\n";
        cout << "1. Nhap d/s DTXS\n";
        cout << "2. Xuat d/s DTXS\n";
        cout << "3. Liet ke d/s GV co tu 5 bai bao khoa hoc tro len\n";
        cout << "4. Dem SV co DRL toi da\n";
        cout << "5. Tinh tong tien thuong cua NV co 3 SKKN tro len\n";
        cout << "6. Tinh DTB cua SV co DRL duoi 50\n";
        cout << "7. Kiem tra GV chua co bai bao khoa hoc\n";
        cout << "8. Tim NV co SKKN nhieu nhat\n";
        cout << "9. Sap xep d/s DTXS tang dan theo ma so\n";
        cout << "10. Tim DTXS thuoc Khoa\n";
        cout << "11. Cap nhat thong tin DTXS co ma so tuy y\n";
        cout << "12. Them DTXS moi tai vi tri bat ky\n";
        cout << "13. Xoa DTXS co ma so tuy y\n";
        cout << "14. Xoa d/s DTXS\n";
        cout << "15. Tao file\n";
        cout << "16. Doc file\n";
        cout << "17. Doc file va luu d/s DTXS\n";
        cout << "18. Luu file d/s DTXS\n";
        cout << "0. Thoat CT\n";
        cout << "==========================\n";
        cout << "Ban chon: ";
        cin >> chon;

        switch (chon) {
        case 0:
            tr.~TRUONGDH();
            cout << "Dang thoat CT...";
            break;
        case 1:
            if (tr.GetSL() > 0)
                tr.~TRUONGDH();
            tr.Nhap();
            break;
        case 2:
            tr.Xuat();
            break;
        case 3:
            if (tr.GetSL() > 0)
                tr.LietKeGVCoTu5BaiBao();
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 4:
            if (tr.GetSL() > 0) {
                int dem = tr.DemSVCoDRLToiDa();
                if (dem > 0)
                    cout << "Co " << dem << " SV co DRL toi da\n";
                else
                    cout << "Khong co SV co DRL toi da\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 5:
            if (tr.GetSL() > 0) {
                long tongtien = tr.TinhTongTienThuongNVCo3SKKNTroLen();
                if (tongtien > 0)
                    cout << "Tong tien thuong cap cho NV co 3 SKKN tro len la " << tongtien << endl;
                else
                    cout << "Khong co NV co 3 SKKN tro len\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 6:
            if (tr.GetSL() > 0) {
                double dtb = tr.TinhDTBCuaSVCoDRLDuoi50();
                if (dtb == 0)
                    cout << "Khong co SV co DRL duoi 50\n";
                else
                    cout << "DTB cua SV co DRL duoi 50 la " << dtb << endl;
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 7:
            if (tr.GetSL() > 0) {
                if (tr.KiemTraGVChuaCoBaiBao())
                    cout << "Truong co GV chua co bai bao\n";
                else
                    cout << "Truong khong co GV chua co bai bao\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 8:
            if (tr.GetSL() > 0)
                tr.TimNVCoSKKNNhieuNhat();
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 9:
            if (tr.GetSL() > 0) {
                tr.SapXepMaSoTangDan();
                tr.Xuat();
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 10:
            if (tr.GetSL() > 0) {
                string kh;
                cin.ignore();
                cout << "Nhap Khoa can tim: ";
                getline(cin, kh);
                tr.TimDTXSThuocKhoa(kh);
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 11:
            if (tr.GetSL() > 0) {
                string ms;
                cin.ignore();
                cout << "Nhap ma so: ";
                getline(cin, ms);
                tr.CapNhatThongTinTheoMaSo(ms);
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 12: {
            DTXS* pdt;
            int vt = 1;
            pdt = tr.Nhap1();
            if (tr.GetSL() > 0) {
                do {
                    cout << "Nhap vi tri muon them DTXS tu 1 den " << tr.GetSL() + 1 << ": ";
                    cin >> vt;
                } while (vt < 1 || vt > tr.GetSL() + 1);
            }
            tr.Them(pdt, vt);
            cout << "D/s DTXS sau khi them DTXS moi tai vi tri thu " << vt << " la:\n";
            tr.Xuat();
            break;
        }
        case 13:
            if (tr.GetSL() > 0) {
                string ms;
                cout << "Nhap ma so DTXS muon xoa: ";
                cin >> ms;
                int kq = tr.Xoa(ms);
                if (kq != -1) {
                    if (tr.GetSL() > 0) {
                        cout << "D/s DTXS sau khi xoa DTXS co ma so " << ms << " la:\n";
                        tr.Xuat();
                    }
                    else
                        cout << "D/s DTXS rong\n";
                }
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 14:
            if (tr.GetSL() > 0) {
                tr.~TRUONGDH();
                cout << "Da xoa toan bo d/s DTXS\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 15: {
            string tenfile;
            cin.ignore();
            cout << "Nhap ten file: ";
            getline(cin, tenfile);
            tr.GhiFile(tenfile);
            break;
        }
        case 16: {
            string tenfile;
            cin.ignore();
            cout << "Nhap ten file: ";
            getline(cin, tenfile);
            tr.DocFile(tenfile);
            break;
        }
        case 17: {
            if (tr.GetSL() > 0)
                tr.~TRUONGDH();
            string tenfile;
            cin.ignore();
            cout << "Nhap ten file: ";
            getline(cin, tenfile);
            tr.DocFileDTXS(tenfile);
            break;
        }
        case 18:
            if (tr.GetSL() > 0) {
                string tenfile;
                cin.ignore();
                cout << "Nhap ten file: ";
                getline(cin, tenfile);
                tr.GhiFileDTXS(tenfile);
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        default:
            cout << "Ban chon sai. Moi chon lai.\n";
            break;
        }
        system("pause"); // Dừng màn hình để xem kết quả
    } while (chon != 0);
}