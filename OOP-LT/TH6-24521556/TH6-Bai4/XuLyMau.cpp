#include"MAU.h"
int MAU::dem = 0;
MAU::~MAU()
{
	cout << "Da huy 1 mau => Con " << --dem << " mau \n";
}
MAU::MAU(int r, int g, int b) :r(r), g(g), b(b) {
	cout << "Goi ham thiet lap MAU::MAU(r,g,b) => Co " << ++dem << " mau\n";
}

MAU::MAU(const MAU& m)
{
	SetRGB(m.r, m.g, m.g);
	cout << "Goi ham thiet lap sao chep MAU::MAU(const MAU&) => Co " << ++dem << " mau\n";
}

int MAU::GetR() const
{
	return r;
}
int MAU::GetG() const
{
	return g;
}
int MAU::GetB() const
{
	return b;
}

int MAU::GetDem()
{
	return dem;
}
void MAU::SetR(int r)
{
	if (r < 0) r = 0;
	if (r > 255) r = 255;
	this->r = r;
}
void MAU::SetG(int g)
{
	if (g < 0) g = 0;
	if (g > 255) g = 255;
	this->g = g;
}

void MAU::SetB(int b)
{
	if (b < 0) b = 0;
	if (b > 255) b = 255;
	this->b = b;
}
void MAU::SetRGB(int r, int g, int b) {
	SetR(r);
	SetG(g);
	SetB(b);
}

void MAU::Nhap()
{
	do
	{
		cout << "Nhap 3 thong so mau RGB tu 0 den 255: ";
		cin >> r >> g >> b;
	} while (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255);

}

void MAU::Xuat() const
{
	cout << " - Mau RGB(" << r << ", " << g << ", " << b << ")";
}

bool MAU::KiemTraTrung(const MAU& m) const
{
	return r == m.r && g == m.g && b == m.b;
}

istream& operator >> (istream& is, MAU& m)
{
	m.Nhap();
	return is;
}

ostream& operator << (ostream& os, const MAU& m)
{
	m.Xuat();
	return os;
}