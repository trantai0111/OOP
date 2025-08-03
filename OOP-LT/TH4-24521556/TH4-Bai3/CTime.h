#ifndef CTIME_H
#define CTIME_H

#include <iostream>

class CTime {
private:
    int hour, minute, second;

    void normalize(); // Chuẩn hóa thời gian về dạng hợp lệ (giây, phút, giờ)

public:
    CTime(int h = 0, int m = 0, int s = 0);

    // Toán tử cộng và trừ số giây
    CTime operator+(int seconds) const;
    CTime operator-(int seconds) const;

    // Toán tử ++, -- tiền tố
    CTime& operator++();     // ++CTime
    CTime& operator--();     // --CTime

    // Toán tử ++, -- hậu tố
    CTime operator++(int);   // CTime++
    CTime operator--(int);   // CTime--

    // Toán tử xuất và nhập
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);
    friend std::istream& operator>>(std::istream& is, CTime& t);
};

#endif
