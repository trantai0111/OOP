#pragma once
#include "Activity.h"

class ClassSession : public Activity {
    string courseCode;
    string subject;
public:
    ClassSession();
    void input() override;
    void output() const override;
    double calculatePriority() const override;
};
