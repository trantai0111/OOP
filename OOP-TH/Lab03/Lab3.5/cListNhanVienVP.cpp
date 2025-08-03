#include <bits/stdc++.h>
#include "cNhanVienVP.h"
#include "cListNhanVienVP.h"
using namespace std;
cListNhanVienVP::cListNhanVienVP(){}
cListNhanVienVP::cListNhanVienVP(int so_nhanvien){
	danh_sach.resize(so_nhanvien);
}
cListNhanVienVP::~cListNhanVienVP(){}
void cListNhanVienVP::ThemNV(const cNhanVienVP&nhan_vien){
	danh_sach.push_back(nhan_vien);
}
void cListNhanVienVP::Nhap(){
	int n;
	cout<<"Nhap So Luong Nhan Vien: "; cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cNhanVienVP nv;
		cout<<"Xin Moi Nhap Thong Tin Nhan Vien Thu "<<i+1<<":"<<endl;
		nv.Nhap();
		ThemNV(nv);
	}
}
void cListNhanVienVP::TieuDe()const{
	cout<<setw(10)<<left<<"Ma"
        <<setw(20)<<"Ho Ten"
        <<setw(15)<<"Ngay Sinh"
        <<setw(8)<<"Luong"<<endl;
    cout<<string(73, '-')<<endl;
}
void cListNhanVienVP::Xuat() const{
	if(danh_sach.size()==0)cout<<"Khong Co Nhan Vien Nao"<<endl;
	else{
	TieuDe();
	for(int i=0;i<danh_sach.size();i++){
		danh_sach[i].Xuat();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
    }
} 
void cListNhanVienVP::LuongCaoNhat(){
	if(danh_sach.size()==0)cout<<"Khong Co Nhan Vien Nao"<<endl;
	else{
	TieuDe();
	double max=danh_sach[0].luong;
	for(int i=0;i<danh_sach.size();i++){
		if(danh_sach[i].luong>=max)
		max=danh_sach[i].luong;
	}
	for(int i=0;i<danh_sach.size();i++){
		if(danh_sach[i].luong==max)
		danh_sach[i].Xuat();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
}
}
double cListNhanVienVP::TongLuong()const{
	double tong=0;
	for(int i=0;i<danh_sach.size();i++){
		tong+=danh_sach[i].luong;
	}
	return tong;
}
void cListNhanVienVP::TuoiCaoNhat(){
	if(danh_sach.size()==0)cout<<"Khong Co Nhan Vien Nao"<<endl;
	else{
	TieuDe();
	int tuoiMax=2025-danh_sach[0].LayNamSinh(danh_sach[0].ngay_sinh);
	for(int i=0;i<danh_sach.size();i++){
		int tuoi=2025-danh_sach[i].LayNamSinh(danh_sach[i].ngay_sinh);
		if(tuoi>=tuoiMax);
		tuoiMax=tuoi;
	}
	for(int i=0;i<danh_sach.size();i++){
		int tuoi=2025-danh_sach[i].LayNamSinh(danh_sach[i].ngay_sinh);
		if(tuoi==tuoiMax)
		danh_sach[i].Xuat();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
}
}
void cListNhanVienVP::SapXepTangDan(){
	if(danh_sach.size()==0)cout<<"Khong Co Nhan Vien Nao De Sap Xep"<<endl;
	else{
	TieuDe();
	sort(danh_sach.begin(),danh_sach.end(),[](const cNhanVienVP& a,const cNhanVienVP& b)
	{
		return a.luong<b.luong;
	}
	);
	for(int i=0;i<danh_sach.size();i++){
		danh_sach[i].Xuat();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
    }
}
