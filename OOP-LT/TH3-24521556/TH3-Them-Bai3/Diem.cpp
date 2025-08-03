#include "Diem.h"

// Constructor mặc định
DIEM::DIEM() : x(0), y(0) {}

// Constructor có tham số
DIEM::DIEM(float x, float y) : x(x), y(y) {}

// Hàm nhập điểm
void DIEM::Nhap() {
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}

// Hàm xuất điểm
void DIEM::Xuat() const {
    cout << "(" << x << ", " << y << ")";
}

// Getter & Setter
float DIEM::getX() const { return x; }
float DIEM::getY() const { return y; }
void DIEM::setX(float x) { this->x = x; }
void DIEM::setY(float y) { this->y = y; }

// Hàm di chuyển điểm
void DIEM::DiChuyen(float dx, float dy) {
    x += dx;
    y += dy;
}

// Kiểm tra hai điểm trùng nhau
bool DIEM::KiemTraTrung(const DIEM& d) const {
    return (x == d.x && y == d.y);
}

// Tính khoảng cách giữa hai điểm
float DIEM::TinhKhoangCach(const DIEM& d) const {
    return sqrt(pow(d.x - x, 2) + pow(d.y - y, 2));
}

// Tìm điểm đối xứng qua trục hoành
DIEM DIEM::DoiXungQuaTrucHoanh() const {
    return DIEM(x, -y);
}

// Tìm điểm đối xứng qua trục tung
DIEM DIEM::DoiXungQuaTrucTung() const {
    return DIEM(-x, y);
}

// Kiểm tra ba điểm có tạo thành tam giác không
bool DIEM::KiemTraTamGiac(const DIEM& d1, const DIEM& d2, const DIEM& d3) {
    float a = d1.TinhKhoangCach(d2);
    float b = d2.TinhKhoangCach(d3);
    float c = d3.TinhKhoangCach(d1);
    return (a + b > c && a + c > b && b + c > a);
}

// Tính chu vi tam giác
float DIEM::TinhChuVi(const DIEM& d1, const DIEM& d2, const DIEM& d3) {
    return d1.TinhKhoangCach(d2) + d2.TinhKhoangCach(d3) + d3.TinhKhoangCach(d1);
}

// Tính diện tích tam giác
float DIEM::TinhDienTich(const DIEM& d1, const DIEM& d2, const DIEM& d3) {
    float a = d1.TinhKhoangCach(d2);
    float b = d2.TinhKhoangCach(d3);
    float c = d3.TinhKhoangCach(d1);
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Phân loại tam giác
void DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2, const DIEM& d3) {
    if (!KiemTraTamGiac(d1, d2, d3)) {
        cout << "Ba diem khong tao thanh tam giac." << endl;
        return;
    }

    float a = d1.TinhKhoangCach(d2);
    float b = d2.TinhKhoangCach(d3);
    float c = d3.TinhKhoangCach(d1);

    if (a == b && b == c)
        cout << "Tam giac deu." << endl;
    else if (a == b || b == c || c == a)
        cout << "Tam giac can." << endl;
    else if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
        cout << "Tam giac vuong." << endl;
    else
        cout << "Tam giac thuong." << endl;
}
