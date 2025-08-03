#include "Vehicle.h"

// Constructor mặc định
Vehicle::Vehicle() : chuXe(""), loaiXe(""), triGia(0.0), dungTich(0) {}

// Constructor có tham số
Vehicle::Vehicle(string chuXe, string loaiXe, double triGia, int dungTich) {
    this->chuXe = chuXe;
    this->loaiXe = loaiXe;
    this->triGia = (triGia >= 0) ? triGia : 0;
    this->dungTich = (dungTich >= 0) ? dungTich : 0;
}

// Nhập dữ liệu từ bàn phím
void Vehicle::Nhap() {
    cout << "Nhap chu xe: ";
    getline(cin, chuXe);
    cout << "Nhap loai xe: ";
    getline(cin, loaiXe);
    cout << "Nhap tri gia xe: ";
    cin >> triGia;
    cout << "Nhap dung tich xy lanh: ";
    cin >> dungTich;
    cin.ignore(); // Xóa bộ đệm
}

// Xuất thông tin xe
void Vehicle::Xuat() const {
    cout << left << setw(15) << chuXe << setw(15) << loaiXe << setw(12) << triGia
        << setw(10) << dungTich << setw(10) << TinhThue() << endl;
}

// Tính thuế trước bạ
double Vehicle::TinhThue() const {
    if (dungTich < 100) {
        return triGia * 0.01;
    }
    else if (dungTich <= 200) {
        return triGia * 0.03;
    }
    else {
        return triGia * 0.05;
    }
}
