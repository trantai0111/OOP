#include "DIEM3C.h"
#include "hieu_ung.h"
#define epsilon 0.000000001

int DIEM3C::dem = 0;

DIEM3C::DIEM3C(double x, double y, double z): DIEM2C(x,y), z(0){		// Phuong thuc thiet lap
	cout << "Goi ham thiet lap DIEM3C:DIEM3C(double = 0, double = 0, double = 0). => Co " << ++dem << " DIEM3C da duoc tao." << endl;

}


DIEM3C::DIEM3C(const DIEM3C& d) : DIEM2C(d.x,d.y), z(d.z) {		// Phuong thuc thiet lap
	cout << "Goi ham thiet lap DIEM3C:DIEM3C(const DIEM3C&). => Co " << ++dem << " DIEM3C da duoc tao." << endl;
	
}


DIEM3C::~DIEM3C() {				// Phuong thuc huy
	cout << "Da huy 1 DIEM3C. => Con lai " << --dem << " DIEM3C." << endl;
}

void DIEM3C::operator = (const DIEM3C& d) {
	x = d.x;
	y = d.y;
	z = d.z;
}

int DIEM3C::GetDem() {
	return dem;
}

double DIEM3C::GetZ() const {
	return z;
}


void DIEM3C::SetZ(double z) {
	this->z = z;
}

void DIEM3C::Tinh_tien(double x, double y, double z) {
	DIEM2C::Tinh_tien(x, y);
	this->z += z;

}


bool DIEM3C::KiemTraTrungNhau(const DIEM3C& d) const {
	return (DIEM2C::KiemTraTrungNhau(d) && z == d.z);
}
double DIEM3C::TinhKhoangCach(const DIEM3C& d) const {
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2) + pow(z - d.z, 2));
}
DIEM3C DIEM3C::TimDoiXung() const {
	return DIEM3C(x == 0 ? 0 : -x, y == 0 ? 0 : -y, z == 0 ? 0 : -z);
}
bool DIEM3C::KiemTraTamGiacHopLe(const DIEM3C& d1, const DIEM3C& d2) const {
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b;
}
double DIEM3C::TinhChuViTamGiac(const DIEM3C& d1, const DIEM3C& d2) const {
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return (KiemTraTamGiacHopLe(d1, d2)) ? a + b + c : 0;
}
double DIEM3C::TinhDienTichTamGiac(const DIEM3C& d1, const DIEM3C& d2) const {
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	double p = (a + b + c) / 2;
	return  (KiemTraTamGiacHopLe(d1, d2)) ? sqrt(p * (p - a) * (p - b) * (p - c)) : 0;
}
string DIEM3C::PhanLoaiTamGiac(const DIEM3C& d1, const DIEM3C& d2) const {
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






void DIEM3C::Nhap() {
	DIEM2C::Nhap();
	cout << "Nhap cao do: ";
	cin >> z;
}


void DIEM3C::Xuat() const {
	cout << '(' << x << ',' << y  << ',' << z << ')';

}

istream& operator >> (istream& is, DIEM3C& d) {
	d.Nhap();
	return is;
}

ostream& operator << (ostream& os, const DIEM3C& d) {

	d.Xuat();
	return os;
}

