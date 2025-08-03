#pragma once
#include <bits/stdc++.h>
using namespace std;
class cArray{
private:
	int* a;
	int n;
	bool KiemTraSNT(int y)const;
public:
	cArray(int=0,int=0);
    cArray(const cArray& b); 
    cArray& operator=(const cArray& b);
    ~cArray();
    int GetN()const;
    int* GetA()const; 
    void SetN(int n);
    void SetA(const cArray& c);
    void Nhap(); 
    void Xuat() const;
    friend istream& operator>>(istream& is, cArray& b);
    friend ostream& operator<<(ostream &os, const cArray& b);
    void PhatSinh();
    int Dem(int x)const;
    bool KiemTraTangDan()const;
    void SearchMinLe()const;
    void SearchMaxSNT()const;
    void Sort(); 		
};
