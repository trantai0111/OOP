#include <bits/stdc++.h>
#include "cDaThuc.h"
using namespace std;
cDaThuc::cDaThuc():Bac(0),HeSo({0}){}
cDaThuc::cDaThuc(int n):Bac(n),HeSo(n+1,0){}
void cDaThuc::Nhap(){
	cout<<"Xin Moi Nhap Bac Cua Da Thuc: ";
	do{
	cin>>Bac;
	if(Bac<0)cout<<"Bac Khong Hop Le, Xin Nhap Lai: ";
    }while(Bac<0);
	HeSo.resize(Bac+1);
	for(int i=0;i<=Bac;i++){
		cout<<"Nhap He So a["<<i<<"]: ";
		cin>>HeSo[i];
	}
}
void cDaThuc::Xuat()const{
	int Mu=Bac;
    cout<<"P(X) = ";
    bool DaCoHeSoDauTien=false; 
    for(int i=0;i<=Bac;i++) {
        if(HeSo[i]!= 0) {
            if(DaCoHeSoDauTien) {
                if(HeSo[i]>0) cout<<"+ ";
                else cout<<"- ";
            } else{
                if(HeSo[i]<0) cout << "-";
                DaCoHeSoDauTien=true;
            }
            double hs=abs(HeSo[i]);
            if(Mu==0) cout<<hs;
            else if(Mu==1) {
                if(hs==1) cout<<"x";
                else cout<<hs<<"x";
            } else{
                if(hs==1) cout<<"x^"<<Mu;
                else cout<<hs<<"x^"<<Mu;
            }
            cout<<" ";
        }
        Mu--;
    }

    if (!DaCoHeSoDauTien)cout<<"0";
    cout << endl;
}
double cDaThuc::TinhGiaTri(double x)const{
	int Mu=Bac;
	double GiaTri=0;
	for(int i=0;i<=Bac;i++){
		GiaTri+=HeSo[i]*pow(x,Mu);
		Mu--;
	}
	return GiaTri;
}
cDaThuc cDaThuc::Cong(const cDaThuc&other)const{
    int MaxBac=max(this->Bac,other.Bac);
    cDaThuc KetQua(MaxBac);
    if(this->Bac==other.Bac){
    	for(int i=0;i<=MaxBac;i++){
    		KetQua.HeSo[i]=this->HeSo[i]+other.HeSo[i];
		}
	}
	else if(this->Bac<other.Bac){
		int n=other.Bac-this->Bac;
		for(int i=0;i<n;i++){
			KetQua.HeSo[i]=other.HeSo[i];
		}
		for(int i=0;i<=this->Bac;i++){
			KetQua.HeSo[i+n]=this->HeSo[i]+other.HeSo[i+n];
		}
	}
	else {
		int n=this->Bac-other.Bac;
		for(int i=0;i<n;i++){
			KetQua.HeSo[i]=this->HeSo[i];
		}
		for(int i=0;i<=other.Bac;i++){
			KetQua.HeSo[i+n]=this->HeSo[i+n]+other.HeSo[i];
		}
	}
	return KetQua;
}
cDaThuc cDaThuc::Tru(const cDaThuc&other)const{
    int MaxBac=max(this->Bac,other.Bac);
    cDaThuc KetQua(MaxBac);
    if(this->Bac==other.Bac){
    	for(int i=0;i<=MaxBac;i++){
    		KetQua.HeSo[i]=this->HeSo[i]-other.HeSo[i];
		}
	}
	else if(this->Bac<other.Bac){
		int n=other.Bac-this->Bac;
		for(int i=0;i<n;i++){
			KetQua.HeSo[i]=other.HeSo[i];
		}
		for(int i=0;i<=this->Bac;i++){
			KetQua.HeSo[i+n]=this->HeSo[i]-other.HeSo[i+n];
		}
	}
	else {
		int n=this->Bac-other.Bac;
		for(int i=0;i<n;i++){
			KetQua.HeSo[i]=this->HeSo[i];
		}
		for(int i=0;i<=other.Bac;i++){
			KetQua.HeSo[i+n]=this->HeSo[i+n]-other.HeSo[i];
		}
	}
	return KetQua;
}
	
