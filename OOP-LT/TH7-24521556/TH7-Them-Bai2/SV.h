#ifndef SV_H
#define SV_H

#include "DTXS.h"

class SV : public DTXS {
private:
    double drl;
    double dtb;
public:
    SV() {}
    ~SV();
    SV(string ma, string ten, string k, double d, double t);

    void Nhap() override;
    void Xuat() override;
    long TinhTienThuong() override;

    double GetDRL();
    double GetDTB();
    string GetLoai() override;

    void SetDRL(double d);
    void SetDTB(double t);
};

#endif
