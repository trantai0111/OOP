#include"PhanSo.h"

int TimUCLN(int a, int b){
    int Min = (a > b) ? b : a;
    for (int i = Min; i > 0; i--){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 1;
}

void PhanSo::Nhap(){
    cout <<"Nhap tu so: "; cin >> iTu;
    do{
        cout <<"Nhap mau so (khac 0): "; cin >> iMau;
    }
    while (iMau == 0);
}
void PhanSo::Xuat(){
    if(iMau < 0)
        cout <<-iTu <<" / " <<-iMau << endl;
    else cout << iTu <<" / "<<iMau << endl;
}

void PhanSo::RutGon(){
    iTu /= TimUCLN(iTu, iMau);
    iMau /= TimUCLN(iTu, iMau);
}

PhanSo PhanSo::Tong(PhanSo ps){
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

PhanSo PhanSo::Hieu(PhanSo ps){
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

PhanSo PhanSo::Tich(PhanSo ps){
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}
PhanSo PhanSo::Thuong(PhanSo ps){
    PhanSo kq;
    if(ps.iTu == 0){
        cout << "Loi: Khong the chia cho phan so co tu bang 0 (phan so = 0)!" << endl;
        kq.iTu = 0;
        kq.iMau = 1;
        return kq;
    }
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

void PhanSo::SoSanh(PhanSo ps) {
    int a = iTu * ps.iMau;
    int b = ps.iTu * iMau;
    if (a > b) cout << "Phan so 1 lon hon phan so 2\n";
    else if (a < b) cout << "Phan so 2 lon hon phan so 1\n";
    else cout << "Hai phan so bang nhau\n";
}
