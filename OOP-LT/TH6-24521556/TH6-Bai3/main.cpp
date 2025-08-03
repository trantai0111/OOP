#include "DIEMMAU2C.h"

int main() {
	cout << "So diem mau 2C hien tai la: " << DIEMMAU2C::GetDem() << endl;
    DIEMMAU2C d1, d2(1), d3(1, 2), d4(1, 2, 123), d5(2, 3, 123, 245), d6(5, 3, 92, 225, 232), * d7 = new DIEMMAU2C;
    cout << "So diem mau 2C hien tai la: " << DIEMMAU2C::GetDem() << endl;
    cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << "\nd5: " << d5 << "\nd6: " << d6 << "\nd7: " << *d7 << endl;
    //--------------------------------
    cout << "Nhap lai toa do diem mau 2C d1:\n";
    cin >> d1;
    cout << "d1_moi: " << d1 << endl;
    //--------------------------------
    if (d1.DIEM2C::KiemTraTrungNhau(*d7))
        cout << "d1 va d7 trung hoanh do, tung do\n";
    else
        cout << "d1 va d7 khong trung hoanh do, tung do\n";
    //--------------------------------
    if (d1.MAU::KiemTraTrung(*d7))
        cout << "d1 va d7 trung mau\n";
    else
        cout << "d1 va d7 khong trung mau\n";
    //--------------------------------
    if (d1.KiemTraTrung(*d7))
        cout << "d1 va d7 trung hoanh do, tung do va mau\n";
    else
        cout << "d1 va d7 khong trung hoanh do, tung do va mau\n";
    //--------------------------------
    delete d7;
    cout << "So diem mau 2C hien tai la: " << DIEMMAU2C::GetDem() << endl;

	return 0;
}