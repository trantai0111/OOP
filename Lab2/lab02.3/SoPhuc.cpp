#include"SoPhuc.h"

void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}

void SoPhuc::Xuat() {
    if (iAo >= 0)
        cout << iThuc << " + " << iAo << "i" << endl;
    else
        cout << iThuc << " - " << -iAo << "i" << endl;
}

SoPhuc SoPhuc::Tong(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}

SoPhuc SoPhuc::Hieu(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}

SoPhuc SoPhuc::Tich(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return kq;
}

SoPhuc SoPhuc::Thuong(SoPhuc sp) {
    SoPhuc kq;
    float mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
    if (mau == 0) {
        cout << "Loi: Khong the chia cho so phuc 0!" << endl;
        kq.iThuc = 0;
        kq.iAo = 0;
        return kq;
    }

    kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
    kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;
    return kq;
}
