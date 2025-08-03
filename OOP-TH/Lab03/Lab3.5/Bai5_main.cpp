#include <bits/stdc++.h>
#include "cNhanVienVP.h"
#include "cListNhanVienVP.h"
using namespace std;
int main(){
	cListNhanVienVP ds;
	ds.Nhap();
	cout<<"1.Danh Sach Nhan Vien La: "<<endl;
	ds.Xuat();
	cout<<endl<<"2.Nhan Vien Co Luong Cao Nhat La: "<<endl;
	ds.LuongCaoNhat();
	cout<<endl<<"3.Tong Luong Ma Cong Ty Phai Tra Cho Cac Nhan Vien Van Phong: "<<ds.TongLuong()<<endl;
	cout<<endl<<"4.Nhan Vien Co Tuoi Cao Nhat La: "<<endl;
	ds.TuoiCaoNhat();
	cout<<endl<<"5.Danh Sach Thi Sinh Duoc Sap Xep Tang Dan Theo Luong: "<<endl;
	ds.SapXepTangDan();
	return 0;
}
