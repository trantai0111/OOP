#include <bits/stdc++.h>
#include "cNhanVienSX.h"
#include "cListNhanVienSX.h"
using namespace std;
int main(){
	cListNhanVienSX ds;
	ds.Nhap();
	cout<<"1.Danh Sach Nhan Vien La: "<<endl;
	ds.Xuat();
	cout<<endl<<"2.Nhan Vien Co Luong Thap Nhat La: "<<endl;
	ds.LuongThapNhat();
	cout<<endl<<"3.Tong Luong Ma Cong Ty Phai Tra Cho Cac Nhan Vien San Xuat: "<<ds.TongLuong()<<endl;
	cout<<endl<<"4.Nhan Vien Co Tuoi Cao Nhat La: "<<endl;
	ds.TuoiCaoNhat();
	cout<<endl<<"5.Danh Sach Thi Sinh Duoc Sap Xep Tang Dan Theo Luong: "<<endl;
	ds.SapXepTangDan();
	return 0;
}
