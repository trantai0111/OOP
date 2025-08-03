#include "DIEM2C.h"
#include "hieu_ung.h"
#define epsilon 0.000000001

int DIEM2C::dem = 0;

DIEM2C::DIEM2C(double x, double y) {		// Phuong thuc thiet lap
	cout << "Goi ham thiet lap DIEM2C:DIEM2C(double = 0, double = 0). => Co " << ++dem << " DIEM2C da duoc tao." << endl;
	this->x = x;
	this->y = y;
}


DIEM2C::DIEM2C(const DIEM2C& d) {		// Phuong thuc thiet lap
	cout << "Goi ham thiet lap DIEM2C:DIEM2C(const DIEM2C&). => Co " << ++dem << " DIEM2C da duoc tao." << endl;
	this->x = d.x;
	this->y = d.y;
}


DIEM2C::~DIEM2C() {				// Phuong thuc huy
	cout << "Da huy 1 DIEM2C. => Con lai " << --dem << " DIEM2C." << endl;
}

void DIEM2C::operator = (const DIEM2C& d) {
	x = d.x;
	y = d.y;
}

int DIEM2C::GetDem() {
	return dem;
}

// ============ Cac phuong thuc truy van va cap nhat (get/set) de cap quyen doc /ghi gia tri cho cac thuoc tinh toa do =============
double DIEM2C::GetX() const {
	return x;
}

double DIEM2C::GetY() const {
	return y;
}

void DIEM2C::SetX(double x) {
	this->x = x;
}

void DIEM2C::SetY(double y ) {
	this->y = y;
}

void DIEM2C::SetXY(double x, double y) {
	this->x = x;
	this->y = y;
}

void DIEM2C::Tinh_tien(double x, double y) {
	this->x += x;
	this->y += y;

}


bool DIEM2C::KiemTraTrungNhau(const DIEM2C& d) const {
	return x == d.x && y == d.y;
}
double DIEM2C::TinhKhoangCach(const DIEM2C& d) const {
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
DIEM2C DIEM2C::TimDoiXung() const {
	return DIEM2C(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}
bool DIEM2C::KiemTraTamGiacHopLe(const DIEM2C& d1 , const DIEM2C& d2) const {
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b;
}
double DIEM2C::TinhChuViTamGiac(const DIEM2C& d1, const DIEM2C& d2) const {
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return (KiemTraTamGiacHopLe(d1, d2)) ? a + b + c : 0;
}
double DIEM2C::TinhDienTichTamGiac(const DIEM2C& d1, const DIEM2C& d2) const {
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	double p = (a + b + c) / 2;
	return  (KiemTraTamGiacHopLe(d1, d2)) ? sqrt(p * (p - a) * (p - b) * (p - c)) : 0;
}
string DIEM2C::PhanLoaiTamGiac(const DIEM2C& d1, const DIEM2C& d2) const {
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	string chuoiKq = "";
	if (!KiemTraTamGiacHopLe(d1, d2))
		chuoiKq = "Tam giac khong hop le";
	else if (a == b && b == c)
		chuoiKq = "Tam giac deu";
	else if (a == b || b == c || c == a)
	{
		if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
			chuoiKq = "Tam giac vuong can";
		else
			chuoiKq = "Tam giac can";
	}
	else if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
		chuoiKq = "Tam giac vuong";
	else
		chuoiKq = "Tam giac thuong";
	return chuoiKq;
}






void DIEM2C::Nhap() {
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}


void DIEM2C::Xuat() const{
	cout << '(' << x << ',' << y << ')';

}

istream& operator >> (istream& is, DIEM2C& d) {
	d.Nhap();
	return is;  
}

ostream& operator << (ostream& os, const DIEM2C& d) {

	d.Xuat();
	return os;  
}






