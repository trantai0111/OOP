#pragma once
#ifndef TAMGIAC_H_INCLUDED
#define TAMGIAC_H_INCLUDED
#include"diem.h"
class TAMGIAC{
    private:
        DIEM A, B, C;
        static int dem;
    public:
        ~TAMGIAC();
        TAMGIAC();
        TAMGIAC(const DIEM&, const DIEM&, const DIEM&);
        TAMGIAC(double, double, double, double, double, double);
        TAMGIAC(const TAMGIAC&);
        TAMGIAC& operator=(const TAMGIAC& tg);
        DIEM GetA() const;
        DIEM GetB() const;
        DIEM GetC() const;
        static int GetDem();
        void SetA(const DIEM&);
        void SetB(const DIEM&);
        void SetC(const DIEM&);
        void Nhap();
        void Xuat() const;
        friend istream& operator >>(istream& in, TAMGIAC&);
        friend ostream& operator <<(ostream& out, const TAMGIAC&);
        bool KiemTraTGHopLe() const;
        double TinhChuVi() const;
        double TinhDienTich() const;
        string PhanLoai() const;
};
#endif // TAMGIAC_H_INCLUDED
