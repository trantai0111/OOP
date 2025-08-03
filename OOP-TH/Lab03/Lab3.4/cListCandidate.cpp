#include <bits/stdc++.h>
#include "cCandidate.h"
#include "cListCandidate.h"
using namespace std;
cListCandidate::cListCandidate(){}
cListCandidate::cListCandidate(int so_thisinh){
	danh_sach.resize(so_thisinh);
}
cListCandidate::~cListCandidate(){}
void cListCandidate::ThemThiSinh(const cCandidate& thi_sinh){
	danh_sach.push_back(thi_sinh);
}
void cListCandidate::Nhap(){
	int n;
	cout<<"Nhap So Luong Thi Sinh: "; cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cCandidate ts;
		cout<<"Xin Moi Nhap Thong Tin Thi Sinh Thu "<<i+1<<":"<<endl;
		ts.Nhap();
		ThemThiSinh(ts);
	}
}
void cListCandidate::TieuDe()const{
	cout<<setw(10)<<left<<"Ma"
        <<setw(20)<<"Ho Ten"
        <<setw(15)<<"Ngay Sinh"
        <<setw(8)<<"Toan"
        <<setw(8)<<"Van"
        <<setw(8)<<"Anh"
        <<setw(10)<<"Tong"<<endl;
    cout<<string(73, '-')<<endl;
}
void cListCandidate::Xuat()const{
  bool flag=false;
  for(int i=0;i<danh_sach.size();i++){
  	if(danh_sach[i].TinhTongDiem()>15){
	flag=true;
    }
  }
  if(!flag){
  	cout<<"Khong Co Thi Sinh Nao!"<<endl;
  }
  else{
  TieuDe();
  for(int i=0;i<danh_sach.size();i++){
  	if(danh_sach[i].TinhTongDiem()>15){
	danh_sach[i].Xuat();
    }
  }
  cout<<"-------------------------------------------------------------------------"<<endl;
  }
}
void cListCandidate::ThiSinhDiemCaoNhat(){
	if(danh_sach.size()==0)cout<<"Khong Co Thi Sinh Nao!"<<endl;
	else{
	TieuDe();
	double max=danh_sach[0].TinhTongDiem();
	for(int i=0;i<danh_sach.size();i++){
		if(danh_sach[i].TinhTongDiem()>=max)
		max=danh_sach[i].TinhTongDiem();
	}
	for(int i=0;i<danh_sach.size();i++){
		if(danh_sach[i].TinhTongDiem()==max)
		danh_sach[i].Xuat();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
}
}
void cListCandidate::SapXepGiamDan(){
	if(danh_sach.size()==0)cout<<"Khong Co Thi Sinh Nao De Sap Xep"<<endl;
	else{
	TieuDe();
	sort(danh_sach.begin(),danh_sach.end(),[](const cCandidate& a,const cCandidate& b)
	{
		return a.TinhTongDiem()>b.TinhTongDiem();
	}
	);
	for(int i=0;i<danh_sach.size();i++){
		danh_sach[i].Xuat();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
    }
}
	
