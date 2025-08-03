#pragma once
#include "Activity.h"

class Meeting : public Activity {
    string partner;
    string platform;
public:
    Meeting();
    void input() override;
    void output() const override;
    double calculatePriority() const override;
};
