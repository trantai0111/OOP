#include<bits/stdc++.h>
#include "cNhanVienSX.h"
using namespace std;
cNhanVienSX::cNhanVienSX():ma(""), ten(""), ngay_sinh(""), san_pham(0),don_gia(0){}
cNhanVienSX::cNhanVienSX(string ma,string ten,string ngay_sinh,int san_pham,double don_gia):
ma(ma),ten(ten), ngay_sinh(ngay_sinh), san_pham(san_pham),don_gia(don_gia){}
cNhanVienSX::~cNhanVienSX(){}
double cNhanVienSX::TinhLuong()const{
	return don_gia*san_pham;
}
bool cNhanVienSX::kiemtra_ma()const{
	for(int i = 0;i < ma.length(); i++) {
			if(ma[i]==' '||!isalnum(ma[i])) {
				return false;
			}
		}
	return true;
}
bool cNhanVienSX::kiemtra_ten()const {
		for(int i = 0;i < ten.length(); i++) {
			if(!isalpha(ten[i]) && ten[i]!=' ') {
				return false;
			}
		}
		return true;
}
bool cNhanVienSX::kiemtra_ngaysinh()const{
	if (ngay_sinh.length() != 10) return false;  
        for (int i=0; i<ngay_sinh.length(); i++) {
        if ((i==2||i == 5) && ngay_sinh[i] != '/') {
            return false;
        }
        else if (i != 2 && i != 5 && !isdigit(ngay_sinh[i])) {
            return false;
        }
    }
    return true;
} 
void cNhanVienSX::Chuanhoa(string &s) 
{
    for (char &c:s) 
        c=tolower(c);
    for (int i=0;i<s.length();i++) 
        if (i == 0 || s[i - 1]==' ') 
            s[i]=toupper(s[i]);
    auto xoaspace=[](string &str) {
        string temp="";
        for (char c:str) {
            if (c != ' ')
                temp+=c;
        }
        str=temp;
    };
    xoaspace(s);
    string result="";
    result+=s[0];
    for (int i=1;i<s.length();i++) {
        if (isupper(s[i])) 
            result+=' ';
        result+=s[i];
    }
    s=result; 
}
void cNhanVienSX::Nhap(){
	cout<<"Moi Nhap Ma Nhan Vien: "; 
	    do {
			getline(cin,ma);
			if(!kiemtra_ma()) {
				cout<<"Ma Nhan Vien khong hop le, xin moi nhap lai: ";
			}
		} while(!kiemtra_ma());
	    cout<<"Moi nhap Ho Va Ten Nhan Vien: ";
		do {
			getline(cin,ten);
			if(!kiemtra_ten()) {
				cout<<"Ho va ten nhan vien khong hop le, xin moi nhap lai: ";
			}
		} while(!kiemtra_ten());
		Chuanhoa(ten);
		cout<<"Moi nhap ngay,thang,nam sinh (dd/mm/yyyy) nhan vien: ";
		do {
			getline(cin,ngay_sinh);
			if(!kiemtra_ngaysinh()) {
				cout<<"ngay,thang,nam sinh (dd/mm/yyyy) khong hop le, xin moi nhap lai: ";
			}
		} while(!kiemtra_ngaysinh());
	    cout<<"Moi nhap So Luong San Pham: ";
		do {
			cin>>san_pham;
			if(san_pham<0) {
				cout<<"So Luong khong hop le, xin moi nhap lai: ";
			}
		} while(san_pham<0);
		cout<<"Moi Nhap Gia Tien Cua San Pham: ";
		do {
			cin>>don_gia;
			if(don_gia<0) {
				cout<<"Gia Tien khong hop le, xin moi nhap lai: ";
			}
		} while(don_gia<0);
		cin.ignore();
		cout<<endl;
}
void cNhanVienSX::Xuat()const{
	cout<<setw(10)<<left<<ma
     <<setw(20)<<left<<ten
     <<setw(15)<<left<<ngay_sinh
     <<setw(12)<<right<<san_pham
     <<setw(12)<<right<<fixed<<setprecision(0)<<don_gia
     <<setw(12)<<right<<fixed<<setprecision(0)<<TinhLuong()
     <<endl;
}
void cNhanVienSX::setMa(string ms){
	cNhanVienSX temp(ms,ten,ngay_sinh,san_pham,don_gia);
	if(temp.kiemtra_ma()){
		ma=ms;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
int cNhanVienSX::LayNamSinh(string namsinh){
	string nam="";
	for(int i=6;i<=9;i++){
		nam+=namsinh[i];
	}
	int result=stol(nam);
	return result;
}
void cNhanVienSX::setTen(string hoten){
	cNhanVienSX temp(ma,hoten,ngay_sinh,san_pham,don_gia);
	if(temp.kiemtra_ten()){
		ten=hoten;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cNhanVienSX::setNgaySinh(string ns){
	cNhanVienSX temp(ma,ten,ns,san_pham,don_gia);
	if(temp.kiemtra_ngaysinh()){
		ngay_sinh=ns;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cNhanVienSX::setSanPham(int sp){
	if(sp>=0){
		san_pham=sp;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cNhanVienSX::setDonGia(double dongia){
	if(dongia>=0){
		don_gia=dongia;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
string cNhanVienSX::GetMa()const{
	return ma;
}
string cNhanVienSX::GetTen()const{
	return ten;
}
string cNhanVienSX::GetNgaySinh()const{
	return ngay_sinh;
}
int cNhanVienSX::GetSanPham()const{
	return san_pham;
}
double cNhanVienSX::GetDonGia()const{
	return don_gia;
}
double cNhanVienSX::GetLuong()const{
	return san_pham*don_gia;
}
