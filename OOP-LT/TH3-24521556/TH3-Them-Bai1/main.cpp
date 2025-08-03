#include "tamgiac.h"

int main() {
    cout << "Co " << DIEM::GetDem() << " diem\n";
    cout << "Co " << TAMGIAC::GetDem() << " tam giac\n";

    DIEM A, B(3), C(0, 4);
    TAMGIAC tg1, tg2(A, B, C), tg3(0, 4, -3, 0, 3, 0), tg4;

    cout << "Co " << DIEM::GetDem() << " diem\n";
    cout << "Co " << TAMGIAC::GetDem() << " tam giac\n";

    cout << "Toa do 3 dinh cua cac tam giac:\n";
    cout << tg1 << endl << tg2 << endl << tg3 << endl << tg4 << endl;

    cout << tg1 << " => " << tg1.PhanLoai() << " Chu vi: " << tg1.TinhChuVi() << " Dien tich: " << tg1.TinhDienTich() << endl;
    cout << tg2 << " => " << tg2.PhanLoai() << " Chu vi: " << tg2.TinhChuVi() << " Dien tich: " << tg2.TinhDienTich() << endl;
    cout << tg3 << " => " << tg3.PhanLoai() << " Chu vi: " << tg3.TinhChuVi() << " Dien tich: " << tg3.TinhDienTich() << endl;
    cout << tg4 << " => " << tg4.PhanLoai() << " Chu vi: " << tg4.TinhChuVi() << " Dien tich: " << tg4.TinhDienTich() << endl;

    tg4 = tg3 = tg2 = tg1;

    cout << "Toa do 3 dinh cua cac tam giac sau phep gan:\n";
    cout << tg1 << endl << tg2 << endl << tg3 << endl << tg4 << endl;

    cout << tg1 << " => " << tg1.PhanLoai() << " Chu vi: " << tg1.TinhChuVi() << " Dien tich: " << tg1.TinhDienTich() << endl;
    cout << tg2 << " => " << tg2.PhanLoai() << " Chu vi: " << tg2.TinhChuVi() << " Dien tich: " << tg2.TinhDienTich() << endl;
    cout << tg3 << " => " << tg3.PhanLoai() << " Chu vi: " << tg3.TinhChuVi() << " Dien tich: " << tg3.TinhDienTich() << endl;
    cout << tg4 << " => " << tg4.PhanLoai() << " Chu vi: " << tg4.TinhChuVi() << " Dien tich: " << tg4.TinhDienTich() << endl;
}

