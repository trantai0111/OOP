#include "DIEMMAU2C.h"
int DIEMMAU2C::dem = 0;


DIEMMAU2C::DIEMMAU2C(double x, double y, int r, int g, int b) : DIEM2C(x, y), MAU(r,g,b) {		// Phuong thuc thiet lap
	cout << "Goi ham thiet lap DIEMMAU2C:DIEMMAU2C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0). => Co " << ++dem << " DIEMMAU2C da duoc tao." << endl;

}



DIEMMAU2C::~DIEMMAU2C() {				// Phuong thuc huy
	cout << "Da huy 1 DIEMMAU2C. => Con lai " << --dem << " DIEMMAU2C." << endl;
}


int DIEMMAU2C::GetDem() {
	return dem;
}

void DIEMMAU2C::Nhap() {
	DIEM2C::Nhap();
	MAU::Nhap();
}

void DIEMMAU2C::Xuat() const
{
	DIEM2C::Xuat();
	MAU::Xuat();
}

bool DIEMMAU2C::KiemTraTrung(const DIEMMAU2C& d) const {
	return DIEM2C::KiemTraTrungNhau(d) && MAU::KiemTraTrung(d);
}

istream& operator >> (istream& is, DIEMMAU2C& d) {
	d.Nhap();
	return is;
}

ostream& operator << (ostream& os, const DIEMMAU2C& d) {

	d.Xuat();
	return os;
}