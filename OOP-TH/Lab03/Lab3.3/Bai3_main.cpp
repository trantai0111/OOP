#include <iostream>
#include "cDaThuc.h"
int main(){
	cDaThuc dt;
	dt.Nhap();
	dt.Xuat();
	int select;
	   cout<<"-------------CHUONG TRINH XU LY DA THUC-------------"<<endl;
	   cout<<"0.Ket Thuc Chuong Trinh"<<endl;
	   cout<<"1.Tinh Gia Tri P(X)"<<endl;
	   cout<<"2.Cong Hai Da Thuc"<<endl;
	   cout<<"3.Tru Hai Da Thuc"<<endl;
	   cout<<"----------------------------------------------------"<<endl;
	do{
	   cin>>select;
	   switch (select){
	   	case 0:{
	   		cout<<"Dang Thoat Chuong Trinh..............."<<endl;
			break;
		   }
		case 1:{
			double x;
			cout<<"Moi Nhap Gia Tri x can tinh: "; cin>>x;
			cout<<"Gia Tri Cua P("<<x<<") = "<<dt.TinhGiaTri(x)<<endl;
			break;
		}
		case 2:{
			cDaThuc dt2;
			cout<<"Moi Ban Nhap Da Thuc Thu 2: "<<endl;
			dt2.Nhap();
			cout<<"Da Thuc Thu 2: ";
			dt2.Xuat();
			cDaThuc Tong=dt.Cong(dt2);
			cout<<"Tong Cua Hai Da Thuc La: "<<endl;
			Tong.Xuat();
			break;
		}
		case 3:{
			cDaThuc dt2;
			cout<<"Moi Ban Nhap Da Thuc Thu 2: "<<endl;
			dt2.Nhap();
			cout<<"Da Thuc Thu 2: ";
			dt2.Xuat();
			cDaThuc Hieu=dt.Tru(dt2);
			cout<<"Hieu Cua Hai Da Thuc La: "<<endl;
			Hieu.Xuat();
			break;
		}
	   	default:{
	   		cout<<"Khong Hop Le, Xin Chon Lai....."<<endl;
			break;
		   }
	   }
	}while(select!=0);
	return 0;
}
