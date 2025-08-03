#include<bits/stdc++.h>
#include"cCandidate.h"
using namespace std;
cCandidate::cCandidate():ma(""), ten(""), ngay_sinh(""), diem_toan(0), diem_van(0), diem_anh(0){}
cCandidate::cCandidate(string ma, string ten, string ngay_sinh, double diem_toan, double diem_van, double diem_anh):
ma(ma), ten(ten), ngay_sinh(ngay_sinh), diem_toan(diem_toan), diem_van(diem_van), diem_anh(diem_anh){}
cCandidate::~cCandidate(){}
float cCandidate::TinhTongDiem()const{
	return diem_toan + diem_van + diem_anh;
}
bool cCandidate::kiemtra_ma()const{
	for(int i = 0;i < ma.length(); i++) {
			if(ma[i]==' '||!isalnum(ma[i])) {
				return false;
			}
		}
	return true;
}
bool cCandidate::kiemtra_ten()const {
		for(int i = 0;i < ten.length(); i++) {
			if(!isalpha(ten[i]) && ten[i]!=' ') {
				return false;
			}
		}
		return true;
}
bool cCandidate::kiemtra_ngaysinh()const{
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
void cCandidate::Chuanhoa(string &s) 
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
void cCandidate::Nhap(){
	    cout<<"Moi Nhap Ma Thi Sinh: "; 
	    do {
			getline(cin,ma);
			if(!kiemtra_ma()) {
				cout<<"Ma thi sinh khong hop le, xin moi nhap lai: ";
			}
		} while(!kiemtra_ma());
	    cout<<"Moi nhap ho va ten thi sinh: ";
		do {
			getline(cin,ten);
			if(!kiemtra_ten()) {
				cout<<"Ho va ten thi sinh khong hop le, xin moi nhap lai: ";
			}
		} while(!kiemtra_ten());
		Chuanhoa(ten);
		cout<<"Moi nhap ngay,thang,nam sinh (dd/mm/yyyy) thi sinh: ";
		do {
			getline(cin,ngay_sinh);
			if(!kiemtra_ngaysinh()) {
				cout<<"ngay,thang,nam sinh (dd/mm/yyyy) khong hop le, xin moi nhap lai: ";
			}
		} while(!kiemtra_ngaysinh());
	    cout<<"Moi nhap diem toan,van,anh: ";
		do {
			cin>>diem_toan>>diem_van>>diem_anh;
			if((10<diem_toan || diem_toan<0) || (10<diem_van||diem_van<0) || (10<diem_anh||diem_anh<0)) {
				cout<<"Diem khong hop le, xin moi nhap lai: "<<endl;
			}
		} while((10<diem_toan || diem_toan<0) || (10<diem_van||diem_van<0) || (10<diem_anh||diem_anh<0));
		cin.ignore();
		cout<<endl;
}
void cCandidate::Xuat()const{
	cout<<setw(10)<<left<<ma 
        <<setw(20)<<left<<ten
        <<setw(15)<<left<<ngay_sinh
        <<setw(2)<<right<<diem_toan
        <<setw(8)<<right<<diem_van
        <<setw(8)<<right<<diem_anh
        <<setw(10)<<right<<TinhTongDiem()<<endl;
}
void cCandidate::setMa(string ms){
	cCandidate temp(ms,ten,ngay_sinh,diem_toan,diem_van,diem_anh);
	if(temp.kiemtra_ma()){
		ma=ms;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cCandidate::setTen(string hoten){
	cCandidate temp(ma,hoten,ngay_sinh,diem_toan,diem_van,diem_anh);
	if(temp.kiemtra_ten()){
		ten=hoten;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cCandidate::setNgaySinh(string ns){
	cCandidate temp(ma,ten,ns,diem_toan,diem_van,diem_anh);
	if(temp.kiemtra_ngaysinh()){
		ngay_sinh=ns;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cCandidate::setdiemtoan(double toan){
	if(toan<=10&&toan>=0){
		diem_toan=toan;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cCandidate::setdiemvan(double van){
	if(van<=10&&van>=0){
		diem_van=van;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
void cCandidate::setdiemanh(double anh){
	if(anh<=10&&anh>=0){
		diem_anh=anh;
	}
	else{
		cout<<"Khong The Set Do Khong Hop Le, Giu Nguyen Nhu Cu! "<<endl;
	}
}
string cCandidate::GetMa()const{
	return ma;
}
string cCandidate::GetTen()const{
	return ten;
}
string cCandidate::GetNgaySinh()const{
	return ngay_sinh;
}
double cCandidate::GetDiemToan()const{
	return diem_toan;
}
double cCandidate::GetDiemVan()const{
	return diem_van;
}
double cCandidate::GetDiemAnh()const{
	return diem_anh;
}
