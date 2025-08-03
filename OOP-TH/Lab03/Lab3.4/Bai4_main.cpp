#include<bits/stdc++.h>
#include"cListCandidate.h"
#include"cCandidate.h"
using namespace std;
int main(){
    cListCandidate ds;
	ds.Nhap();
	cout<<"Danh Sach Thi Sinh Tren 15 Diem La: "<<endl;
	ds.Xuat();
	cout<<endl<<"Thi Sinh Co Tong Diem Cao Nhat La: "<<endl;
	ds.ThiSinhDiemCaoNhat();
	cout<<endl<<"Danh Sach Thi Sinh Duoc Sap Xep Giam Dan Theo Tong Diem: "<<endl;
	ds.SapXepGiamDan();
	return 0;
}
