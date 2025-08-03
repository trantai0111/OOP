// Main xử lý danh sách vé
#include <iostream>
#include <vector>
#include <algorithm>
#include "VeTronGoi.h"
#include "VeTungPhan.h"
using namespace std;

int main() {
    vector<Ve*> danhSach;
    int n;
    cout << "Nhap so luong ve: "; cin >> n; cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "\n1. Ve Tron Goi\n2. Ve Tung Phan\nChon loai ve: ";
        int loai; cin >> loai; cin.ignore();
        Ve* ve = nullptr;
        if (loai == 1) ve = new VeTronGoi();
        else ve = new VeTungPhan();
        ve->nhap();
        danhSach.push_back(ve);
    }
    cout << "\nDanh sach ve:\n";
    for (Ve* ve : danhSach) ve->xuat();
    for (Ve* ve : danhSach) delete ve;
    return 0;
}