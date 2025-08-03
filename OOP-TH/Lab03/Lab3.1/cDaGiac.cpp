#include <bits/stdc++.h>
#include "Diem.h"
#include "cDaGiac.h"
#define epsilon 0.000000001
using namespace std;
cDaGiac::cDaGiac(){}
cDaGiac::cDaGiac(int SoDinh){
	Dinh.resize(SoDinh);
}
cDaGiac::~cDaGiac(){
	Dinh.clear();
}
void cDaGiac::Nhap(){
	int n;
	cout<<"Nhap So Dinh Cua Da Giac: ";
	cin>>n;Dinh.resize(n);
	for(int i=0;i<n;i++){
		cout<<"Nhap Dinh Thu "<<i+1<<" :"<<endl;
		Dinh[i].Nhap();
	}
}
void cDaGiac::Xuat()const{
	cout<<"Da Giac Co "<<Dinh.size()<<" Dinh: "<<endl;
	for(int i=0;i<Dinh.size();i++){
		Dinh[i].Xuat();
	}
}
string cDaGiac::KiemTraLoai()const{
	string chuoikq="";
	int n=Dinh.size();
	if(n<3){
		chuoikq="Da Giac Khong Hop Le";
	}
	else if(n==3){
		Diem A=Dinh[0];
	    Diem B=Dinh[1];
	    Diem C=Dinh[2];
		double AB=A.TinhKhoangCach(B);
		double BC=B.TinhKhoangCach(C);
		double CA=C.TinhKhoangCach(A);
		if(abs(AB*AB+BC*BC-CA*CA)<=epsilon||
	        abs(AB*AB+CA*CA-BC*BC)<=epsilon||
	        abs(BC*BC+CA*CA-AB*AB)<=epsilon) {
		if(AB==BC||BC==CA||CA==AB) {
			chuoikq="Tam Giac Vuong Can";
		}
		else {
			chuoikq="Tam Giac Vuong";
		}
	    }
	    else if(AB==BC&&BC==CA) {
		chuoikq="Tam Giac Deu";
	    }
	    else if(AB==BC||BC==CA||CA==AB) {
		chuoikq="Tam Giac Can";
	    }
	    else {
		chuoikq="Tam Giac Thuong";
	    }
	}
	else if(n==4){
	Diem A=Dinh[0];
	Diem B=Dinh[1];
	Diem C=Dinh[2];
	Diem D=Dinh[3];
	double AB=A.TinhKhoangCach(B);
	double BC=B.TinhKhoangCach(C);
	double CD=C.TinhKhoangCach(D);
	double DA=D.TinhKhoangCach(A);
	//Do Dai Hai Duong Cheo
	double AC=A.TinhKhoangCach(C);
	double BD=B.TinhKhoangCach(D);
	//Tinh VecTor Chi Phuong
	Diem vAB(B.dx-A.dx,B.dy-A.dy);
	Diem vBC(C.dx-B.dx,C.dy-B.dy);
	Diem vCD(D.dx-C.dx,D.dy-C.dy);
	Diem vDA(A.dx-D.dx,A.dy-D.dy);
	Diem vAC(C.dx-A.dx,C.dy-A.dy);
	Diem vBD(D.dx-B.dx,D.dy-B.dy);
	auto TichVoHuong=[](Diem u,Diem v){
		return u.dx*v.dx+u.dy*v.dy;
	};
	auto VuongGoc=[&](Diem u, Diem v){
		return abs(TichVoHuong(u,v))<=epsilon;
	};
	auto SongSong=[&](Diem u,Diem v){
		return abs(u.dx*v.dy-u.dy*v.dx)<=epsilon;
	};
	if(AB==BC&&BC==CD&&CD==DA){
		if(VuongGoc(vAB,vBC)&&VuongGoc(vBC,vCD)){
			chuoikq="Hinh Vuong";
		}
		else if(VuongGoc(vAC,vBD)){
			chuoikq="Hinh Thoi";
		}
		else{
			chuoikq="Tu Giac Deu";
		}
	}
	else if(AB==CD&&BC==DA){
		if(VuongGoc(vAB,vBC)){
			chuoikq="Hinh Chu Nhat";
		}
		else if(SongSong(vAB,vCD)&&SongSong(vBC,vDA)){
			chuoikq="Hinh Binh Hanh";
		}
		else{
			chuoikq="Tu Giac Co Hai Canh Doi Bang Nhau";
		}
	}
	else if ((SongSong(vAB,vCD)&&!SongSong(vBC,vDA))||
	          (SongSong(vBC,vDA)&&!SongSong(vAB,vCD))){
		chuoikq="Hinh Thang";
	}
	else {
		chuoikq="Tu Giac Thuong";
	}
	}
	else{
		bool laDaGiacDeu=true;
		double DoDai0=Dinh[0].TinhKhoangCach(Dinh[1]);
		for(int i=1;i<n;i++){
			double DoDaiSoSanh=Dinh[i].TinhKhoangCach(Dinh[(i+1)%n]);
			if(abs(DoDaiSoSanh-DoDai0)>epsilon){
				laDaGiacDeu=false;
				break;
			}
		}
		if(laDaGiacDeu){
			chuoikq="Da Giac Deu";
		}
		else{
			chuoikq="Da Giac Thuong";
		}
	}
	return chuoikq;
}
double cDaGiac::TinhChuVi()const{
	int n=Dinh.size();
	double ChuVi=Dinh[0].TinhKhoangCach(Dinh[1]);
		for(int i=1;i<n;i++){
			double DoDai=Dinh[i].TinhKhoangCach(Dinh[(i+1)%n]);
			ChuVi+=DoDai;
		}
	return ChuVi;
}
double cDaGiac::TinhDienTich()const{
	int n=Dinh.size();
	if(n<3){
		return 0;
	}
	double S=0;
    for(int i=0;i<n;i++) {
        int j=(i+1)%n;
        S+=Dinh[i].dx*Dinh[j].dy-Dinh[j].dx*Dinh[i].dy;
    }
    return abs(S)/2.0;
	
}
void cDaGiac::TinhTien(double x,double y){
	for(int i=0;i<Dinh.size();i++){
		Dinh[i].TinhTien(x,y);
	}
}
void cDaGiac::PhongTo(double scale){
	for(int i=0;i<Dinh.size();i++){
		Dinh[i].PhongTo(scale);
	}
}
void cDaGiac::ThuNho(double scale){
	for(int i=0;i<Dinh.size();i++){
		Dinh[i].ThuNho(scale);
	}
}
void cDaGiac::Quay(const Diem&A,int alpha){
	for(int i=0;i<Dinh.size();i++){
		Dinh[i].Quay(A,alpha);
	}
}
