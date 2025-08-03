#include <bits/stdc++.h>
#include "Diem.h"
#define M_PI 3.14159265358979323846
#define epsilon 0.000000001
using namespace std;
Diem::Diem():dx(0),dy(0){}
Diem::Diem(double x,double y):dx(x),dy(y){}
Diem::Diem(const Diem&A):dx(A.dx),dy(A.dy){}
Diem::~Diem(){}
void Diem::Nhap(){
	cout<<"Nhap Hoanh Do: ";
	cin>>dx;
	cout<<"Nhap Tung Do: ";
	cin>>dy;
}
void Diem::Xuat()const{
	cout<<"("<<dx<<","<<dy<<")"<<" ";
}
double Diem::TinhKhoangCach(const Diem&A)const{
	return (sqrt(pow(dx-A.dx,2)+pow(dy-A.dy,2)));
}
void Diem::TinhTien(double x,double y){
	dx+=x;
	dy+=y;
}
void Diem::PhongTo(double scale){
	dx*=scale;
	dy*=scale;
}
void Diem::ThuNho(double scale){
	dx/=scale;
	dy/=scale;
}
void Diem::Quay(const Diem& A, int alpha) {
    double rad=alpha*M_PI/180.0; 
    double vecX=dx-A.dx;
    double vecY=dy-A.dy;
    double newX=A.dx+vecX*cos(rad)-vecY*sin(rad);
    double newY=A.dy+vecX*sin(rad)+vecY*cos(rad);
    dx=newX;
    dy=newY;
}
