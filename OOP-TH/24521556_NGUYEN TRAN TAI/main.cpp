#include <iostream>
#include <vector>
#include <algorithm>
#include "ClassSession.h"
#include "Meeting.h"
#include "SelfStudy.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<Activity*> ds;
    for (int i = 0; i < n; ++i) {
        string loai;
        getline(cin, loai);

        Activity* hd = nullptr;
        if (loai == "ClassSession") hd = new ClassSession();
        else if (loai == "Meeting") hd = new Meeting();
        else if (loai == "SelfStudy") hd = new SelfStudy();

        if (hd) {
            hd->input();
            ds.push_back(hd);
        }
    }

    cout << "-- Thông tin hoạt động và điểm ưu tiên --\n";
    for (auto* hd : ds) {
        hd->output();
    }

    cout << "--- Danh sách hoạt động theo buổi ---\n";

    vector<string> buoi = { "Sáng", "Chiều", "Tối" };
    for (const auto& b : buoi) {
        cout << "== " << b << " ==\n";
        for (auto* hd : ds) {
            if (hd->getTimeSlot() == b) {
                hd->output();
            }
        }
    }

    cout << "--- Hoạt động có ưu tiên cao nhất mỗi buổi ---\n";
    for (const auto& b : buoi) {
        Activity* maxHD = nullptr;
        for (auto* hd : ds) {
            if (hd->getTimeSlot() == b) {
                if (!maxHD || hd->calculatePriority() > maxHD->calculatePriority()) {
                    maxHD = hd;
                }
            }
        }
        if (maxHD) {
            cout << b << ": " << maxHD->getTitle() << " - Ưu tiên: " << maxHD->calculatePriority() << '\n';
        }
    }

    for (auto* hd : ds) {
        delete hd;
    }

    return 0;
}
