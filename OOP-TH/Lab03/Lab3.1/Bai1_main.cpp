#include "Diem.h"
#include "cDaGiac.h"
#include <bits/stdc++.h>
using namespace std;
int main(){
	cDaGiac dg;
	dg.Nhap();
	dg.Xuat();
	int select;
	do{
	cout<<"\n-------------------------CHUONG TRINH XU LY DA GIAC-------------------------\n";
	cout<<"0.Ket Thuc Chuong Trinh"<<endl;
	cout<<"1.Phan Loai Da Giac, Tinh Chu Vi Va Dien Tich"<<endl;
	cout<<"2.Tinh Tien, Quay, Phong To Va Thu Nho Da Giac"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cin>>select;
	switch(select){
		case 0:{
			cout<<"Ket Thuc Chuong Trinh......................."<<endl;
			break;
		}
		case 1:{
			cout<<"Phan Loai: "<<dg.KiemTraLoai()<<endl;
			cout<<"Chu Vi: "<<dg.TinhChuVi()<<endl;
			cout<<"Dien Tich: "<<dg.TinhDienTich()<<endl;
			break;
		}
		case 2:{
			int chon;
			cout<<"Cac Phep Bien Doi Bao Gom: "<<endl;
			cout<<"1.Tinh Tien"<<endl;
			cout<<"2.Quay"<<endl;
			cout<<"3.Phong To"<<endl;
			cout<<"4.Thu Nho"<<endl;
			cout<<"Xin Moi Chon Phep Bien Doi: ";cin>>chon;
			if(chon==1){
				double x,y;
				cout<<"Xin Moi Nhap Toa Do Can Tinh Tien: ";cin>>x>>y;
				dg.TinhTien(x,y);
				cout<<"Da Giac Sau Khi Tinh Tien La: "<<endl;
				dg.Xuat();
			}
			else if(chon==2){
				Diem a; int alpha;
				cout<<"Xin Moi Nhap Toa Do Tam: "<<endl;
				a.Nhap();
				cout<<"Xin Moi Nhap Goc Quay: ";cin>>alpha;
				dg.Quay(a,alpha);
				cout<<"Da Giac Sau Khi Quay La: "<<endl;
				dg.Xuat();
			}
			else if(chon==3){
				double scale;
				cout<<"Xin Moi Nhap So Lan Phong To: ";cin>>scale;
				dg.PhongTo(scale);
				cout<<"Da Giac Sau Khi Phong To La: "<<endl;
				dg.Xuat();
			}
			else{
				double scale;
				cout<<"Xin Moi Nhap So Lan Thu Nho: ";cin>>scale;
				dg.ThuNho(scale);
				cout<<"Da Giac Sau Khi Thu Nho La: "<<endl;
				dg.Xuat();
			}
			break;
		}
		default:{
			cout<<"Khong Hop Le,Xin Nhap Lai........"<<endl;
			break;
		}
	}
    }while(select!=0);
    return 0;
}
