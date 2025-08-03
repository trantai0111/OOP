#pragma once 
#include <bits/stdc++.h>
#include "cCandidate.h"
using namespace std;
class cCandidate;
class cListCandidate: public cCandidate{
private:
	vector<cCandidate> danh_sach;
public:
	cListCandidate();
	cListCandidate(int so_thisinh);
	~cListCandidate();
	void ThemThiSinh(const cCandidate& thi_sinh);
	void Nhap();
	void TieuDe()const;
	void Xuat()const;
	void ThiSinhDiemCaoNhat();
	void SapXepGiamDan();		
};
