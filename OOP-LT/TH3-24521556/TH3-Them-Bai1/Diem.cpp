#include "diem.h"
int DIEM::dem = 0;

DIEM::~DIEM()
{
    cout << "Goi ham huy 1 diem => Con " << --dem << " diem\n";
}

DIEM::DIEM() : x(0), y(0)
{
    cout << "Goi ham thiet lap DIEM::DIEM() => Co " << ++dem << " diem\n";
}

DIEM::DIEM(double x) : x(x), y(0)
{
    cout << "Goi ham thiet lap DIEM::DIEM(x) => Co " << ++dem << " diem\n";
}

DIEM::DIEM(double x, double y) : x(x), y(y)
{
    cout << "Goi ham thiet lap DIEM::DIEM(x, y) => Co " << ++dem << " diem\n";
}

//DIEM::DIEM(double x = 0, double y = 0) : x(x), y(y)
//{
//    cout << "Goi ham thiet lap DIEM::DIEM(x=0, y=0) => Co " << ++dem << " diem\n";
//}

DIEM::DIEM(const DIEM& d) : x(d.x), y(d.y)
{
    cout << "Goi ham thiet lap sao chep DIEM::DIEM(const DIEM&) => Co " << ++dem << " diem\n";
}

DIEM& DIEM::operator=(const DIEM& d)
{
    cout << "Goi ham nap chong toan tu gan DIEM::operator=(const DIEM&)\n";
    x = d.x;
    y = d.y;
    return *this;
}

double DIEM::GetX() const { return x; }
double DIEM::GetY() const { return y; }
int DIEM::GetDem() { return dem; }

void DIEM::SetX(double x) { this->x = x; }
void DIEM::SetY(double y) { this->y = y; }
void DIEM::SetXY(double x, double y) {
    SetX(x);
    SetY(y);
}

void DIEM::Nhap()
{
    cout << "Nhap hoanh do va tung do: ";
    cin >> x >> y;
}

void DIEM::Xuat() const
{
    cout << x << "," << y;
}

istream& operator>>(istream& is, DIEM& d)
{
    //cout << "Nhap hoanh do va tung do: ";
    //is >> d.x >> d.y;
    d.Nhap();
    return is;
}

ostream& operator<<(ostream& os, const DIEM& d)
{
    //os << d.x << "," << d.y;
    d.Xuat();
    return os;
}

void DIEM::DiChuyen(double dx, double dy)
{
    x += dx;
    y += dy;
}

bool DIEM::KiemTraTrung(DIEM d) const
{
    return x == d.x && y == d.y;
}

double DIEM::TinhKhoangCach(const DIEM& d) const
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

DIEM DIEM::TimDiemDoiXung() const
{
    return DIEM(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}

bool DIEM::KiemTraTGHopLe(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b;
}

double DIEM::TinhChuVi(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return KiemTraTGHopLe(d1, d2) ? a + b + c : 0;
}

double DIEM::TinhDienTich(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    double p = TinhChuVi(d1, d2) / 2;
    return KiemTraTGHopLe(d1, d2) ? sqrt(p * (p - a) * (p - b) * (p - c)) : 0;
}

string DIEM::PhanLoaiTG(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    string loaiTG = "";
    if (!KiemTraTGHopLe(d1, d2))
        loaiTG = "TG khong hop le";
    else if (a == b && b == c)
        loaiTG = "TG deu";
    else if (a == b || b == c || c == a)
    {
        if (a * a + b * b - c * c <= epsilon || a * a + c * c - b * b <= epsilon || c * c + b * b - a * a <= epsilon)
            loaiTG = "TG vuong can";
        else
            loaiTG = "TG can";
    }
    else if (a * a + b * b - c * c <= epsilon || a * a + c * c - b * b <= epsilon || c * c + b * b - a * a <= epsilon)
        loaiTG = "TG vuong";
    else
        loaiTG = "TG thuong";
    return loaiTG;
}
