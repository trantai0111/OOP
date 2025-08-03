#include "DIEMMAU3C.h"
int DIEMMAU3C::dem = 0;


DIEMMAU3C::DIEMMAU3C(double x, double y, double z, int r, int g, int b) : DIEM3C(x, y,z), r(r), g(g), b(b) {		// Phuong thuc thiet lap
	cout << "Goi ham thiet lap DIEMMAU3C:DIEMMAU3C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0). => Co " << ++dem << " DIEMMAU3C da duoc tao." << endl;

}



DIEMMAU3C::~DIEMMAU3C() {				// Phuong thuc huy
	cout << "Da huy 1 DIEMMAU3C. => Con lai " << --dem << " DIEMMAU3C." << endl;
}


int DIEMMAU3C::GetDem() {
	return dem;
}


DIEMMAU3C::DIEMMAU3C(const DIEMMAU3C& m)
{
	SetRGB(m.r, m.g, m.g);
	cout << "Goi ham thiet lap sao chep DIEMMAU3C::DIEMMAU3C(const DIEMMAU3C&) => Co " << ++dem << " DIEMMAU3C\n";
}

int DIEMMAU3C::GetR() const
{
	return r;
}
int DIEMMAU3C::GetG() const
{
	return g;
}
int DIEMMAU3C::GetB() const
{
	return b;
}


void DIEMMAU3C::SetR(int r)
{
	if (r < 0) r = 0;
	if (r > 255) r = 255;
	this->r = r;
}
void DIEMMAU3C::SetG(int g)
{
	if (g < 0) g = 0;
	if (g > 255) g = 255;
	this->g = g;
}

void DIEMMAU3C::SetB(int b)
{
	if (b < 0) b = 0;
	if (b > 255) b = 255;
	this->b = b;
}
void DIEMMAU3C::SetRGB(int r, int g, int b) {
	SetR(r);
	SetG(g);
	SetB(b);
}



void DIEMMAU3C::Nhap() {
	DIEM3C::Nhap();
	do
	{
		cout << "Nhap 3 thong so mau RGB tu 0 den 255: ";
		cin >> r >> g >> b;
	} while (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255);


}

void DIEMMAU3C::Xuat() const
{
	DIEM3C::Xuat();
	cout << " - Mau RGB(" << r << ", " << g << ", " << b << ")";
}

bool DIEMMAU3C::KiemTraTrung(const DIEMMAU3C& d) const {
	return DIEM3C::KiemTraTrungNhau(d) && r == d.r && g == d.g && b == d.b;
}

istream& operator >> (istream& is, DIEMMAU3C& d) {
	d.Nhap();
	return is;
}

ostream& operator << (ostream& os, const DIEMMAU3C& d) {

	d.Xuat();
	return os;
}