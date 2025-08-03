#ifndef NV_H
#define NV_H

#include "DTXS.h"

class NV : public DTXS {
private:
    int skkn;
public:
    NV() {}
    ~NV();
    NV(string ma, string ten, string k, int s);

    void Nhap() override;
    void Xuat() override;
    long TinhTienThuong() override;

    int GetSoSKKN();
    void SetSoSKKN(int s);
    string GetLoai() override;
};

#endif
