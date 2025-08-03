#include "DIEMMAU3C.h"

int main() {
    cout << "So diem mau 3C hien tai la: " << DIEMMAU3C::GetDem() << endl;
    DIEMMAU3C d1, d2(1), d3(1, 2), d4(1, 2, 6, 123), d5(1, 2, 6, 32, 64, 128), d6(2, 3, 4, 123, 245, 232), * d7 = new DIEMMAU3C;
    cout << "So diem mau 3C hien tai la: " << DIEMMAU3C::GetDem() << endl;
    cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << "\nd5: " << d5 << "\nd6: " << d6 << "\nd7: " << *d7 << endl;
    //--------------------------------
    cout << "Nhap lai toa do diem mau 3C d1:\n";
    cin >> d1;
    cout << "d1_moi: " << d1 << endl;
    //--------------------------------
    if (d1.DIEM3C::KiemTraTrungNhau(*d7))
        cout << "d1 va d7 trung hoanh do, tung do va cao do\n";
    else
        cout << "d1 va d7 khong trung hoanh do, tung do va cao do\n";
    //--------------------------------
    if (d1.KiemTraTrung(*d7))
        cout << "d1 va d7 trung hoanh do, tung do, cao do va mau\n";
    else
        cout << "d1 va d7 khong trung hoanh do, tung do, cao do va mau\n";
    //--------------------------------
    delete d7;
    cout << "So diem mau 3C hien tai la: " << DIEMMAU3C::GetDem() << endl;

    return 0;
}