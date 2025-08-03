#include <bits/stdc++.h>
#include "cNhanVienSX.h"
#include "cListNhanVienSX.h"
using namespace std;
cListNhanVienSX::cListNhanVienSX(){}
cListNhanVienSX::cListNhanVienSX(int so_nhanvien){
	danh_sach.resize(so_nhanvien);
}
cListNhanVienSX::~cListNhanVienSX(){}
void cListNhanVienSX::ThemNV(const cNhanVienSX&nhan_vien){
	danh_sach.push_back(nhan_vien);
}
void cListNhanVienSX::Nhap(){
	int n;
	cout<<"Nhap So Luong Nhan Vien: "; cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cNhanVienSX nv;
		cout<<"Xin Moi Nhap Thong Tin Nhan Vien Thu "<<i+1<<":"<<endl;
		nv.Nhap();
		ThemNV(nv);
	}
}
void cListNhanVienSX::TieuDe()const{
	cout<<setw(10)<<left<<"Ma"
     <<setw(20)<<left<<"Ho Ten"
     <<setw(15)<<left<<"Ngay Sinh"
     <<setw(12)<<right<<"San Pham"
     <<setw(12)<<right<<"Don Gia"
     <<setw(12)<<right<<"Luong"<<endl;

cout << string(81, '-') << endl;
}
void cListNhanVienSX::Xuat() const{
	if(danh_sach.size()==0)cout<<"Khong Co Nhan Vien Nao"<<endl;
	else{
	TieuDe();
	for(int i=0;i<danh_sach.size();i++){
		danh_sach[i].Xuat();
	}
	cout<<"---------------------------------------------------------------------------------"<<endl;
    }
} 
void cListNhanVienSX::LuongThapNhat(){
	if(danh_sach.size()==0)cout<<"Khong Co Nhan Vien Nao"<<endl;
	else{
	TieuDe();
	double min=danh_sach[0].TinhLuong();
	for(int i=0;i<danh_sach.size();i++){
		if(danh_sach[i].TinhLuong()<min)
		min=danh_sach[i].TinhLuong();
	}
	for(int i=0;i<danh_sach.size();i++){
		if(danh_sach[i].TinhLuong()==min)
		danh_sach[i].Xuat();
	}
	cout<<"---------------------------------------------------------------------------------"<<endl;
}
}
double cListNhanVienSX::TongLuong()const{
	double tong=0;
	for(int i=0;i<danh_sach.size();i++){
		tong+=danh_sach[i].TinhLuong();
	}
	return tong;
}
void cListNhanVienSX::TuoiCaoNhat(){
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
	cout<<"---------------------------------------------------------------------------------"<<endl;
}
}
void cListNhanVienSX::SapXepTangDan(){
	if(danh_sach.size()==0)cout<<"Khong Co Nhan Vien Nao De Sap Xep"<<endl;
	else{
	TieuDe();
	sort(danh_sach.begin(),danh_sach.end(),[](const cNhanVienSX& a,const cNhanVienSX& b)
	{
		return a.TinhLuong()<b.TinhLuong();
	}
	);
	for(int i=0;i<danh_sach.size();i++){
		danh_sach[i].Xuat();
	}
	cout<<"---------------------------------------------------------------------------------"<<endl;
    }
}
