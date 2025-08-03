#include<bits/stdc++.h>
#include "cNhanVienVP.h"
using namespace std;
cNhanVienVP::cNhanVienVP():ma(""), ten(""), ngay_sinh(""), luong(0){}
cNhanVienVP::cNhanVienVP(string ma,string ten,string ngay_sinh,double luong):
ma(ma),ten(ten), ngay_sinh(ngay_sinh), luong(luong){}
cNhanVienVP::~cNhanVienVP(){}
bool cNhanVienVP::kiemtra_ma()const{
	for(int i = 0;i < ma.length(); i++) {
			if(ma[i]==' '||!isalnum(ma[i])) {
				return false;
			}
		}
	return true;
}
bool cNhanVienVP::kiemtra_ten()const {
		for(int i = 0;i < ten.length(); i++) {
			if(!isalpha(ten[i]) && ten[i]!=' ') {
				return false;
			}
		}
		return true;
}
bool cNhanVienVP::kiemtra_ngaysinh()const{
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
void cNhanVienVP::Chuanhoa(string &s) 
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
void cNhanVienVP::Nhap(){
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
	    cout<<"Moi nhap muc luong cua nhan vien: ";
		do {
			cin>>luong;
			if(luong<0) {
				cout<<"Luong khong hop le, xin moi nhap lai: ";
			}
		} while(luong<0);
		cin.ignore();
		cout<<endl;
}
void cNhanVienVP::Xuat()const{
	cout<<setw(10)<<left<<ma 
        <<setw(20)<<left<<ten
        <<setw(15)<<left<<ngay_sinh
        <<setw(2)<<right<<fixed<<setprecision(0)<<luong<<endl;
}
void cNhanVienVP::setMa(string ms){
	cNhanVienVP temp(ms,ten,ngay_sinh,luong);
	if(temp.kiemtra_ma()){
		ma=ms;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
int cNhanVienVP::LayNamSinh(string namsinh){
	string nam="";
	for(int i=6;i<=9;i++){
		nam+=namsinh[i];
	}
	int result=stol(nam);
	return result;
}
void cNhanVienVP::setTen(string hoten){
	cNhanVienVP temp(ma,hoten,ngay_sinh,luong);
	if(temp.kiemtra_ten()){
		ten=hoten;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cNhanVienVP::setNgaySinh(string ns){
	cNhanVienVP temp(ma,ten,ns,luong);
	if(temp.kiemtra_ngaysinh()){
		ngay_sinh=ns;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cNhanVienVP::setluong(double salary){
	if(salary>=0){
		luong=salary;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
string cNhanVienVP::GetMa()const{
	return ma;
}
string cNhanVienVP::GetTen()const{
	return ten;
}
string cNhanVienVP::GetNgaySinh()const{
	return ngay_sinh;
}
double cNhanVienVP::GetLuong()const{
	return luong;
}
