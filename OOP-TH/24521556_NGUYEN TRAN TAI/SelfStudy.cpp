#include "SelfStudy.h"
#include <iostream>

SelfStudy::SelfStudy() : Activity(), topic(""), location("") {}

void SelfStudy::input() {
    Activity::input();
    getline(cin, topic);
    getline(cin, location);
}

void SelfStudy::output() const {
    cout << "[Tự học] ";
    Activity::output();
    cout << " tại " << location << " - " << startTime << " - Ưu tiên: " << calculatePriority() << endl;
}

double SelfStudy::calculatePriority() const {
    int hour = stoi(startTime.substr(0, 2));
    if (hour >= 18)
        return duration * 2;
    return duration;
}
