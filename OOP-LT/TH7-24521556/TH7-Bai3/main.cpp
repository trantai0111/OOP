#include "GiaoDich.h"  
#include "GiaoDichVang.h"  
#include "GiaoDichTienTe.h"  
#include <iostream>  
using namespace std;  

int main() {  
   int n = 0;  
   GiaoDich** gd = nullptr;  
   int choice;  

   do {  
       cout << "\n==== MENU ====\n";  
       cout << "1. Nhap danh sach giao dich (vang va tien te)\n";  
       cout << "2. Xuat danh sach giao dich\n";  
       cout << "3. Giao dich vang co thanh tien cao nhat\n";  
       cout << "4. Giao dich Euro co thanh tien thap nhat\n";  
       cout << "5. Xuat giao dich co thanh tien > 1 ty\n";  
       cout << "0. Thoat\n";  
       cout << "Chon chuc nang: ";  
       cin >> choice;  
       cin.ignore();  

       switch (choice) {  
       case 1: {  
           cout << "Nhap so luong giao dich: ";  
           cin >> n;  
           cin.ignore();  
           gd = new GiaoDich * [n];  
           for (int i = 0; i < n; ++i) {  
               int loai;  
               cout << "\nNhap loai giao dich (1. Vang, 2. Tien te): ";  
               cin >> loai;  
               cin.ignore();  

               if (loai == 1) {  
                   gd[i] = new GiaoDichVang();  
               }  
               else {  
                   gd[i] = new GiaoDichTienTe();  
               }  
               gd[i]->Nhap();  
           }  
           break;  
       }  

       case 2: {  
           if (!gd || n == 0) {  
               cout << "Chua co du lieu!\n";  
               break;  
           }  
           cout << "\nDanh sach cac giao dich:\n";  
           for (int i = 0; i < n; ++i) {  
               gd[i]->Xuat();  
           }  
           break;  
       }  

       case 3: {  
           if (!gd || n == 0) {  
               cout << "Chua co du lieu!\n";  
               break;  
           }  
           double max = -1;  
           GiaoDichVang* maxGD = nullptr;  
           for (int i = 0; i < n; ++i) {  
               GiaoDichVang* gv = dynamic_cast<GiaoDichVang*>(gd[i]);  
               if (gv && gv->ThanhTien() > max) {  
                   max = gv->ThanhTien();  
                   maxGD = gv;  
               }  
           }  
           if (maxGD) {  
               cout << "\nGiao dich vang co thanh tien cao nhat:\n";  
               maxGD->Xuat();  
           }  
           else {  
               cout << "Khong co giao dich vang!\n";  
           }  
           break;  
       }  

       case 4: {  
           if (!gd || n == 0) {  
               cout << "Chua co du lieu!\n";  
               break;  
           }  
           double min = 1e18;  
           GiaoDichTienTe* minEuro = nullptr;  
           for (int i = 0; i < n; ++i) {  
               GiaoDichTienTe* tt = dynamic_cast<GiaoDichTienTe*>(gd[i]);  
               if (tt && tt->getLoaiTien() == "EURO" && tt->ThanhTien() < min) {  
                   min = tt->ThanhTien();  
                   minEuro = tt;  
               }  
           }  
           if (minEuro) {  
               cout << "\nGiao dich EURO co thanh tien thap nhat:\n";  
               minEuro->Xuat();  
           }  
           else {  
               cout << "Khong co giao dich EURO!\n";  
           }  
           break;  
       }  

       case 5: {  
           if (!gd || n == 0) {  
               cout << "Chua co du lieu!\n";  
               break;  
           }  
           cout << "\nGiao dich co thanh tien > 1 ty:\n";  
           for (int i = 0; i < n; ++i) {  
               if (gd[i]->ThanhTien() > 1e9) {  
                   gd[i]->Xuat();  
               }  
           }  
           break;  
       }  

       case 0:  
           cout << "Ket thuc chuong trinh.\n";  
           break;  

       default:  
           cout << "Lua chon khong hop le!\n";  
           break;  
       }  

   } while (choice != 0);  

   if (gd) {  
       for (int i = 0; i < n; ++i) {  
           delete gd[i];  
       }  
       delete[] gd;  
   }  

   return 0;  
}
