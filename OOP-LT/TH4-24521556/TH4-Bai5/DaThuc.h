#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
#include <vector>

class DaThuc {
private:
    std::vector<double> heSo; // hệ số từ bậc 0 đến bậc n

    void chuanHoa(); // loại bỏ hệ số 0 ở bậc cao nhất nếu có

public:
    DaThuc(); // khởi tạo rỗng
    DaThuc(const std::vector<double>& hs); // khởi tạo với vector hệ số

    int bac() const; // trả về bậc của đa thức

    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;

    double operator()(double x) const; // tính giá trị tại x

    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt);
    friend std::istream& operator>>(std::istream& is, DaThuc& dt);
};

#endif
