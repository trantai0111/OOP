#include "ClassSession.h"
#include <iostream>

ClassSession::ClassSession() : Activity(), courseCode(""), subject("") {}

void ClassSession::input() {
    Activity::input();
    getline(cin, courseCode);
    getline(cin, subject);
}

void ClassSession::output() const {
    cout << "[Class] ";
	Activity::output();
    cout << " (" << courseCode << ") - " << startTime <<" - Ưu tiên: " << calculatePriority() << endl;
}

double ClassSession::calculatePriority() const {
    if (courseCode.substr(0, 2) == "SE")
        return duration * 2;
    return duration * 1.5;
}
