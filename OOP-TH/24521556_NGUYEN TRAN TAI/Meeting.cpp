#include "Meeting.h"
#include <iostream>


Meeting::Meeting() : Activity(), partner(""), platform("") {}

void Meeting::input() {
    Activity::input();
    getline(cin, platform);
    getline(cin, partner);
}

void Meeting::output() const {
    cout << "[Meeting] ";
    Activity::output();
    cout << " ( " << platform << " ) - " << startTime << " - Ưu tiên: " << calculatePriority() << endl;
}

double Meeting::calculatePriority() const {
    if (platform == "Zoom" || platform == "Teams")
        return duration + 10;
    return duration;
}
