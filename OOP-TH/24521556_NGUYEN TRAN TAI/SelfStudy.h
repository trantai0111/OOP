#pragma once
#include "Activity.h"

class SelfStudy : public Activity {
    string topic;
    string location;
public:
    SelfStudy();
    void input() override;
    void output() const override;
    double calculatePriority() const override;
};
