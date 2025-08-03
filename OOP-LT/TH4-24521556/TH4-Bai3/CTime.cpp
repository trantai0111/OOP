#include "CTime.h"
#include <iostream>
#include <iomanip>
using namespace std;

CTime::CTime(int h, int m, int s) : hour(h), minute(m), second(s) {
    normalize();
}

void CTime::normalize() {
    if (second < 0 || minute < 0 || hour < 0) {
        second = minute = hour = 0;
        return;
    }

    minute += second / 60;
    second %= 60;

    hour += minute / 60;
    minute %= 60;

    hour %= 24;
}

CTime CTime::operator+(int seconds) const {
    CTime result = *this;
    result.second += seconds;
    result.normalize();
    return result;
}

CTime CTime::operator-(int seconds) const {
    CTime result = *this;
    int total = result.hour * 3600 + result.minute * 60 + result.second - seconds;
    if (total < 0) total += 24 * 3600; // quay vong
    result.hour = total / 3600;
    result.minute = (total % 3600) / 60;
    result.second = total % 60;
    return result;
}

CTime& CTime::operator++() {
    *this = *this + 1;
    return *this;
}

CTime& CTime::operator--() {
    *this = *this - 1;
    return *this;
}

CTime CTime::operator++(int) {
    CTime temp = *this;
    *this = *this + 1;
    return temp;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    *this = *this - 1;
    return temp;
}

ostream& operator<<(ostream& os, const CTime& t) {
    os << setfill('0') << setw(2) << t.hour << ":"
        << setw(2) << t.minute << ":"
        << setw(2) << t.second;
    return os;
}

istream& operator>>(istream& is, CTime& t) {
    cout << "Nhap gio: ";
    is >> t.hour;
    cout << "Nhap phut: ";
    is >> t.minute;
    cout << "Nhap giay: ";
    is >> t.second;
    t.normalize();
    return is;
}
