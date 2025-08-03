#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate {
public:
    int day, month, year;

    bool isLeapYear(int y) const;
    int getDaysInMonth(int m, int y) const;
    void normalize(); // chuẩn hóa ngày tháng năm

public:
    CDate(int d = 1, int m = 1, int y = 2000);

    // Toán tử cộng, trừ ngày
    CDate operator+(int days) const;
    CDate operator-(int days) const;

    // Toán tử ++, -- (tiền tố và hậu tố)
    CDate& operator++();     // ++CDate
    CDate operator++(int);   // CDate++
    CDate& operator--();     // --CDate
    CDate operator--(int);   // CDate--

    // Khoảng cách giữa 2 ngày
    int operator-(const CDate& other) const;

    // Xuất, nhập
    friend std::ostream& operator<<(std::ostream& os, const CDate& d);
    friend std::istream& operator>>(std::istream& is, CDate& d);
};

#endif
