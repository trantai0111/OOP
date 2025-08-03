#include "cTamGiac.h"

int main() {
    cTamGiac tg;
    cin >> tg;
    cout << tg << endl;

    if (tg.LaTamGiac()) {
        cout << "Loai: " << tg.LoaiTamGiac() << endl;
        cout << "Chu vi: " << tg.ChuVi() << endl;
        cout << "Dien tich: " << tg.DienTich() << endl;

        tg.TinhTien(1, 1);
        cout << "Sau khi tinh tien (1,1): " << tg << endl;

        tg.PhongTo(2);
        cout << "Sau khi phong to 2 lan: " << tg << endl;

        tg.Quay(90);
        cout << "Sau khi quay 90 do: " << tg << endl;
    }
    else {
        cout << "Khong phai la tam giac hop le.\n";
    }

    return 0;
}
