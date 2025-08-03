#include <bits/stdc++.h>
#include "cArray.h"
using namespace std;
bool cArray::KiemTraSNT(int y)const{
	if(y<2)return 0;
	for(int i=2;i<=sqrt(y);i++){
		if(y%i==0)return 0;
	}
	return 1;
}
cArray::cArray(int n,int m){
	if(n==0){
		a=NULL;
		this->n=0;
	}
	else{
		while(n<0){
			cout<<"Khong The Khoi Tao, Xin Nhap Lai So Phan Tu Mang > 0: ";
			cin>>n;
		}
		this->n=n;
		a=new int[this->n];
		for(int i=0;i<this->n;i++){
			a[i]=m;
		}
	}
}
cArray::cArray(const cArray& b){
	if(b.n==0){
		a=NULL;
		this->n=0;
	}
	else{
		n=b.n;
		a=new int[n];
		for(int i=0;i<n;i++){
			a[i]=b.a[i];
		}
	}
}
cArray& cArray::operator=(const cArray& b){
	delete []a;
	if(b.n==0){
		a=NULL;
		this->n=0;
	}
	else{
		n=b.n;
		a=new int[n];
		for(int i=0;i<n;i++){
			a[i]=b.a[i];
		}
	}
	return *this;
}
cArray::~cArray(){
	if(a!=NULL){
		delete[]a;
		a=NULL;
		n=0;
	}
}
int cArray::GetN()const{
	return n;
}
int* cArray::GetA()const{
	return a;
}
void cArray::SetN(int n){
	if(this->n==n)return;
	else if(n==0)this->~cArray();
	else{
		while(n<0){
			cout<<"Khong The Set Gia Tri, Xin Nhap lai so phan tu mang > 0: ";
			cin>>n;
		}
		cArray m1(n);
		int min=n<this->n? n:this->n;
		for(int i=0;i<min;i++){
			m1.a[i]=a[i];
		}
		for(int i=min;i<n;i++){
			m1.a[i]=0;
		}
		this->~cArray();
		*this=m1;
	}
}
void cArray::SetA(const cArray& c){
	*this=c;
}
void cArray::Nhap(){
	if(a!=NULL)this->~cArray();
	cout<<"Nhap So Phan Tu Cua Mang > 0: ";
	do{
		cin>>n;
		if(n<0){
			cout<<"So Phan Tu Cua Mang Khong Hop Le, Xin Nhap Lai: ";
		}
	}while(n<0);
	a= new int[n];
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
void cArray::Xuat() const{
	if(n==0)cout<<"Mang Rong"<<endl;
	else{
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
istream& operator>>(istream& is, cArray& b){
	b.Nhap();
	return is;
}
ostream& operator<<(ostream &os, const cArray& b){
	b.Xuat();
	return os;
}
void cArray::PhatSinh(){
	if(a!=NULL)this->~cArray();
	do{
		cout<<"Nhap So Phan Tu Mang > 0: ";
		cin>>n;
	}while(n<=0);
	a=new int[n];
	int mi,ma;
	cout<<"Nhap Mien Gia Tri Phat Sinh: ";
	cin>>mi>>ma;
	srand(time(0));
	for(int i=0;i<n;i++){
		a[i]=mi+rand()%(ma-mi+1);
	}
}
int cArray::Dem(int x)const{
	int countX=count(a, a + n, x);
	return countX;
}
bool cArray::KiemTraTangDan()const{
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1])
		return false;
	}
	return true;
}
void cArray::SearchMinLe()const{
	int posDau=-1,minLe;
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			posDau=i;
			minLe=a[i];
			break;
		}
	}
	if(posDau!=-1){
		for(int i=0;i<n;i++){
			if(a[i]%2!=0&&a[i]<minLe){
				posDau=i;
				minLe=a[i];
			}
		}
		cout<<"4.Phan Tu Le Be Nhat Trong Mang La a["<<posDau<<"] = "<<minLe<<endl;
	}
	else{
		cout<<"4.Mang Khong Co Phan Tu Le"<<endl;
	}
}
void cArray::SearchMaxSNT()const{
    int pos=-1,MaxSNT;
    for(int i=0;i<n;i++){
    	if(KiemTraSNT(a[i])){
    		pos=i;
    		MaxSNT=a[i];
    		break;
		}
	}
	if(pos!=-1){
		for(int i=0;i<n;i++){
			if(KiemTraSNT(a[i])&&a[i]>MaxSNT){
				pos=i;
				MaxSNT=a[i];
			}
		}
	    cout<<"5.Phan Tu So Nguyen To Lon Nhat Trong Mang La a["<<pos<<"] = "<<MaxSNT<<endl;
	}
	else{
		cout<<"5.Mang Khong Co So Nguyen To"<<endl;
	}
}
void cArray::Sort(){
	string key;
	cout<<"Hay Nhap Tu Khoa Ban Muon Sap Xep (TANG,GIAM): ";
	do{
		cin>>key;
		if(key!="TANG"&&key!="GIAM"){
			cout<<"Xin Vui Long Nhap Dung Tu Khoa: ";
		}
	}while(key!="TANG"&&key!="GIAM");
	int select;
	if(key=="TANG")select=1;
	else if(key=="GIAM")select=2;
	switch(select){
		case 1:{
			sort(a,a+n);
			break;
		}
		case 2:{
			int tam;
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(a[i]<a[j]){
						tam=a[i];
						a[i]=a[j];
						a[j]=tam;
					}
				}
			}
			break;
		}
	}
}
