#include "ThoiGian.h"

void ThoiGian::Nhap() {
	cout << "Vui long nhap thoi gian (gio phut giay) : ";
	cin >> ThoiGian.iGio >> ThoiGian.iPhut >> ThoiGian.iGiay;
}
void ThoiGian::Xuat() {
	if (Thoigian.iGiay >= 60) {
		ThoiGian.iPhut += (ThoiGian.iGiay / 60);
		ThoiGian.iGiay %= 60;
	}
	if (Thoigian.iPhut >= 60) {
		ThoiGian.iGio += (ThoiGian.iPhut / 60);
		ThoiGian.iPhut %= 60;
	}
	if (Thoigian.iGio >= 24) {
		ThoiGian.iPhut %= 24;
	}
	
}