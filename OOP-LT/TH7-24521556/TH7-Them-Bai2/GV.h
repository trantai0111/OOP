#ifndef GV_H
#define GV_H

#include "DTXS.h"

class GV : public DTXS {
private:
    int sobb; 
public:
    GV() {}
    GV(string ma, string ten, string k, int b); 
    ~GV(); 

    void Nhap() override;
    void Xuat() override;
    long TinhTienThuong() override;

    int GetSoBB();
    void SetSoBB(int b);
    string GetLoai() override;
};

#endif
