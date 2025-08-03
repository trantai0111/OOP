#include "CDate.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool CDate::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int CDate::getDaysInMonth(int m, int y) const {
    static int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m - 1];
}

CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) {
    normalize();
}

void CDate::normalize() {
    while (day > getDaysInMonth(month, year)) {
        day -= getDaysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += getDaysInMonth(month, year);
    }
}

CDate CDate::operator+(int days) const {
    CDate result = *this;
    result.day += days;
    result.normalize();
    return result;
}

CDate CDate::operator-(int days) const {
    CDate result = *this;
    result.day -= days;
    result.normalize();
    return result;
}

CDate& CDate::operator++() {
    *this = *this + 1;
    return *this;
}

CDate CDate::operator++(int) {
    CDate temp = *this;
    ++(*this);
    return temp;
}

CDate& CDate::operator--() {
    *this = *this - 1;
    return *this;
}

CDate CDate::operator--(int) {
    CDate temp = *this;
    --(*this);
    return temp;
}

static bool operator==(const CDate& a, const CDate& b) {
    return a.day == b.day && a.month == b.month && a.year == b.year;
}
static bool operator!=(const CDate& a, const CDate& b) {
    return a.day != b.day || a.month != b.month || a.year != b.year;
}

// Khoang cach giua 2 ngay tinh bang so ngay
int CDate::operator-(const CDate& other) const {
    auto isBefore = [](const CDate& a, const CDate& b) {
        return a.year < b.year || (a.year == b.year && a.month < b.month) ||
            (a.year == b.year && a.month == b.month && a.day < b.day);
        };

    CDate start = other, end = *this;
    int count = 0;
    if (isBefore(end, start)) swap(start, end);
    while (start != end) {
        ++start;
        ++count;
    }
    return count;
}

ostream& operator<<(ostream& os, const CDate& d) {
    os << setfill('0') << setw(2) << d.day << "/"
        << setw(2) << d.month << "/"
        << setw(4) << d.year;
    return os;
}

istream& operator>>(istream& is, CDate& d) {
    char ch;
    cout << "Nhap ngay (dd/mm/yyyy): ";
    is >> d.day >> ch >> d.month >> ch >> d.year;
    d.normalize();
    return is;
}
