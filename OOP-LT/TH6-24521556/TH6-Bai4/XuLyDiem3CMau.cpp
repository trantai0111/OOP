#include "DIEM3CMAU.h"
int DIEM3CMAU::dem = 0;


DIEM3CMAU::DIEM3CMAU(double x, double y, double z, int r, int g, int b) : DIEM3C(x, y,z), MAU(r,g,b) {		// Phuong thuc thiet lap
	cout << "Goi ham thiet lap DIEM3CMAU:DIEM3CMAU(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0). => Co " << ++dem << " DIEM3CMAU da duoc tao." << endl;

}



DIEM3CMAU::~DIEM3CMAU() {				// Phuong thuc huy
	cout << "Da huy 1 DIEM3CMAU. => Con lai " << --dem << " DIEM3CMAU." << endl;
}


int DIEM3CMAU::GetDem() {
	return dem;
}

void DIEM3CMAU::Nhap() {
	DIEM3C::Nhap();
	MAU::Nhap();
}

void DIEM3CMAU::Xuat() const
{
	DIEM3C::Xuat();
	MAU::Xuat();
}

bool DIEM3CMAU::KiemTraTrung(const DIEM3CMAU& d) const {
	return DIEM3C::KiemTraTrungNhau(d) && MAU::KiemTraTrung(d);
}

istream& operator >> (istream& is, DIEM3CMAU& d) {
	d.Nhap();
	return is;
}

ostream& operator << (ostream& os, const DIEM3CMAU& d) {

	d.Xuat();
	return os;
}