#pragma once
#ifndef _TRUONGDH
#define _TRUONGDH

#include "DTXS.h"
#include <fstream>  // Th? vi?n x? lý file
#include <string>
using namespace std;

class TRUONGDH {
private:
    DTXS** pdtxs;  // M?ng con tr? ??n các ??i t??ng DTXS (SV, GV, NV)
    int sl;        // S? l??ng ??i t??ng

public:
    ~TRUONGDH();
    TRUONGDH();

    int GetSL();
    void Nhap();
    void Xuat();
    DTXS* Nhap1();

    void LietKeGVCoTu5BaiBao();
    int DemSVCoDRLToiDa();
    long TinhTongTienThuongNVCo3SKKNTroLen();
    double TinhDTBCuaSVCoDRLDuoi50();
    bool KiemTraGVChuaCoBaiBao();
    void TimNVCoSKKNNhieuNhat();

    string DoiChuoiInHoa(string);
    string DoiChuoiInThuong(string);

    void SapXepMaSoTangDan();
    void TimDTXSThuocKhoa(string);
    void CapNhatThongTinTheoMaSo(string);

    void Them(DTXS*, int);
    int Xoa(string);

    void GhiFile(string);
    void DocFile(string);
    void DocFileDTXS(string);
    void GhiFileDTXS(string);
};

#endif
