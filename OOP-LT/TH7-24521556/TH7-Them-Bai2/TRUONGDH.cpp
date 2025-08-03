#include "TRUONGDH.h"
#include "GV.h"
#include "SV.h"
#include "NV.h"
#include <iostream>
using namespace std;

TRUONGDH::~TRUONGDH() {
    if (pdtxs != NULL) {
        for (int i = 0; i < sl; i++)
            delete pdtxs[i];
        delete[] pdtxs;
        pdtxs = NULL;
        sl = 0;
    }
}

TRUONGDH::TRUONGDH() {
    pdtxs = NULL;
    sl = 0;
}

int TRUONGDH::GetSL() {
    return sl;
}

void TRUONGDH::Nhap() {
    int loai; // loại DTXS
    do {
        cout << "Nhap so luong DTXS: ";
        cin >> sl;
    } while (sl < 1);
    pdtxs = new DTXS*[sl];
    for (int i = 0; i < sl; i++) {
        cout << "-------------------------------\n";
        cout << "Nhap thong tin DTXS thu " << i + 1 << ":\n";
        do {
            cout << "Nhap loai (1: GV, 2: SV, 3: NV): ";
            cin >> loai;
        } while (loai < 1 || loai > 3);
        if (loai == 1)
            pdtxs[i] = new GV;
        else if (loai == 2)
            pdtxs[i] = new SV;
        else
            pdtxs[i] = new NV;
        pdtxs[i]->Nhap(); // tính đa hình
    }
}

DTXS* TRUONGDH::Nhap1() {
    int loai; // loại DTXS
    DTXS* pdt;
    do {
        cout << "Nhap loai (1: GV, 2: SV, 3: NV): ";
        cin >> loai;
    } while (loai < 1 || loai > 3);
    if (loai == 1)
        pdt = new GV;
    else if (loai == 2)
        pdt = new SV;
    else
        pdt = new NV;
    pdt->Nhap(); // đa hình
    return pdt;
}

void TRUONGDH::Xuat() {
    if (pdtxs == NULL)
        cout << "D/s DTXS rong\n";
    else
        for (int i = 0; i < sl; i++)
            pdtxs[i]->Xuat(); // đa hình
}

void TRUONGDH::LietKeGVCoTu5BaiBao() {
    int dem = 0;
    for (int i = 0; i < sl; i++)
        if (pdtxs[i]->GetLoai() == "GV" && ((GV*)pdtxs[i])->GetSoBB() >= 5) {
            pdtxs[i]->Xuat(); // đa hình
            dem++;
        }
    if (dem == 0)
        cout << "Khong co GV nao co tu 5 bai bao tro len\n";
}

int TRUONGDH::DemSVCoDRLToiDa() {
    int dem = 0;
    for (int i = 0; i < sl; i++)
        if (pdtxs[i]->GetLoai() == "SV" && ((SV*)pdtxs[i])->GetDRL() == 100)
            dem++;
    return dem;
}

long TRUONGDH::TinhTongTienThuongNVCo3SKKNTroLen() {
    long sum = 0;
    for (int i = 0; i < sl; i++)
        if (pdtxs[i]->GetLoai() == "NV" && ((NV*)pdtxs[i])->GetSoSKKN() >= 3)
            sum += pdtxs[i]->TinhTienThuong();
    return sum;
}

double TRUONGDH::TinhDTBCuaSVCoDRLDuoi50() {
    double tongdtb = 0;
    int dem = 0;
    for (int i = 0; i < sl; i++)
        if (pdtxs[i]->GetLoai() == "SV" && ((SV*)pdtxs[i])->GetDRL() < 50) {
            tongdtb += ((SV*)pdtxs[i])->GetDTB();
            dem++;
        }
    return dem > 0 ? tongdtb / dem : 0;
}
bool TRUONGDH::KiemTraGVChuaCoBaiBao() {
	for (int i = 0; i < sl; i++)
		if (pdtxs[i]->GetLoai() == "GV" && ((GV*)pdtxs[i])->GetSoBB() == 0)
			return true;
	return false;
}
void TRUONGDH::TimNVCoSKKNNhieuNhat() {
	int maxSKKN = -1;
	NV* nvMax = nullptr;
	for (int i = 0; i < sl; i++) {
		if (pdtxs[i]->GetLoai() == "NV") {
			NV* nv = (NV*)pdtxs[i];
			if (nv->GetSoSKKN() > maxSKKN) {
				maxSKKN = nv->GetSoSKKN();
				nvMax = nv;
			}
		}
	}
	if (nvMax != nullptr) {
		cout << "NV co so SKKN nhieu nhat:\n";
		nvMax->Xuat();
	}
	else {
		cout << "Khong co NV nao trong danh sach\n";
	}
}
string TRUONGDH::DoiChuoiInHoa(string str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}

string TRUONGDH::DoiChuoiInThuong(string str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}

void TRUONGDH::SapXepMaSoTangDan() {
    for (int i = 0; i < sl - 1; i++)
        for (int j = i + 1; j < sl; j++)
            if (DoiChuoiInHoa(pdtxs[i]->GetMaSo()) > DoiChuoiInHoa(pdtxs[j]->GetMaSo())) {
                DTXS* ptam = pdtxs[i];
                pdtxs[i] = pdtxs[j];
                pdtxs[j] = ptam;
            }
}
void TRUONGDH::TimDTXSThuocKhoa(string khoa) {
	bool found = false;
	for (int i = 0; i < sl; i++) {
		if (DoiChuoiInHoa(pdtxs[i]->GetKhoa()) == DoiChuoiInHoa(khoa)) {
			pdtxs[i]->Xuat(); // đa hình
			found = true;
		}
	}
	if (!found)
		cout << "Khong co DTXS thuoc khoa " << khoa << endl;
}
void TRUONGDH::CapNhatThongTinTheoMaSo(string maSo) {
	for (int i = 0; i < sl; i++) {
		if (DoiChuoiInHoa(pdtxs[i]->GetMaSo()) == DoiChuoiInHoa(maSo)) {
			cout << "Cap nhat thong tin cho DTXS co ma so " << maSo << ":\n";
			pdtxs[i]->Nhap(); // đa hình
			return;
		}
	}
	cout << "Khong tim thay DTXS co ma so " << maSo << endl;
}

void TRUONGDH::Them(DTXS* pdt, int vt) {
    DTXS** pnew = new DTXS * [sl + 1];
    for (int i = 0; i < vt - 1; i++)
        pnew[i] = pdtxs[i];
    pnew[vt - 1] = pdt;
    for (int i = vt; i < sl + 1; i++)
        pnew[i] = pdtxs[i - 1];
    delete[] pdtxs;
    pdtxs = pnew;
    sl++;
}

// Xóa đối tượng theo mã số
int TRUONGDH::Xoa(string ms) {
    int vt = -1;
    for (int i = 0; i < sl; i++)
        if (DoiChuoiInHoa(pdtxs[i]->GetMaSo()) == DoiChuoiInHoa(ms)) {
            vt = i;
            break;
        }
    if (vt != -1) {
        DTXS** pnew = new DTXS * [sl - 1];
        for (int i = 0; i < vt; i++)
            pnew[i] = pdtxs[i];
        for (int i = vt; i < sl - 1; i++)
            pnew[i] = pdtxs[i + 1];
        delete[] pdtxs;
        pdtxs = pnew;
        sl--;
    }
    else
        cout << "Khong tim thay DTXS co ma so " << ms << endl;
    return vt;
}
void TRUONGDH::GhiFile(string tenfile) {
    // Khai báo biến nd để lưu chuỗi nội dung
    string nd;

    // Khai báo biến hỗ trợ xử lý ghi file, mở file để bắt đầu ghi
    ofstream outputFile(tenfile);

    if (!outputFile.fail()) { // Nếu tạo file thành công
        cout << "Nhap noi dung file (ket thuc bang dau ~):\n";

        // Lặp để nhập nội dung
        while (true) {
            getline(cin, nd); // Đọc từng dòng và lưu vào chuỗi nd

            if (nd.back() != '~') { // Nếu chưa kết thúc
                outputFile << nd << endl; // Ghi dòng vào file và xuống dòng
            }
            else { // Nếu gặp dấu ~ kết thúc
                nd.back() = '\0'; // Thay dấu ~ bằng ký tự kết thúc chuỗi
                outputFile << nd; // Ghi dòng cuối vào file
                break; // Kết thúc vòng lặp
            }
        }

        outputFile.close(); // Đóng file, lưu dữ liệu
        cout << "Da ghi file thanh cong\n";
    }
    else {
        cout << "Loi tao file\n";
    }
}
void TRUONGDH::DocFile(string filename) {
	string nd;
	ifstream inputFile(filename);
	if (!inputFile.fail()) { 
		while (getline(inputFile, nd))
			cout << nd << endl; 
		inputFile.close(); // Đóng file sau khi đọc xong
		cout << "Da doc file thanh cong\n";
	}
	else 
		cout << "Loi doc file\n"; 
}
void TRUONGDH::DocFileDTXS(string tenfile) {
	ifstream inputFile(tenfile);
	if (!inputFile.fail()) {
		inputFile >> sl;
		inputFile.ignore();
		pdtxs = new DTXS * [sl];
		for (int i = 0; i < sl; i++) {
			string ma, ten, khoa, loai;
			getline(inputFile, ma);
			getline(inputFile, ten);
			getline(inputFile, khoa);
			getline(inputFile, loai);
			if (loai == "GV") {
				int sobb;
				inputFile >> sobb;
				pdtxs[i] = new GV(ma, ten, khoa, sobb);
			}
			else if (loai == "SV") {
				double dtb, drl;
				inputFile >> dtb >> drl;
				pdtxs[i] = new SV(ma, ten, khoa, dtb, drl);
			}
			else if (loai == "NV") {
				int sosk;
				inputFile >> sosk;
				pdtxs[i] = new NV(ma, ten, khoa, sosk);
			}
			else {
				cout << "Loai DTXS khong hop le: " << loai << endl;
				continue;
			}
			long thuong;
			inputFile >> thuong; // Đọc tiền thưởng
			pdtxs[i]->SetHoTen(ten);
			pdtxs[i]->SetKhoa(khoa);
		}
		inputFile.close();
		cout << "Da doc file thanh cong\n";
	}
	else
		cout << "Loi doc file\n";
}
