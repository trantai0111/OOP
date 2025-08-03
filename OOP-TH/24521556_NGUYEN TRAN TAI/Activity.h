#pragma once  
#include <iostream>  
#include <string>  
#include "Time.h"  
using namespace std;  

class Activity { 
protected:  
   string title;  
   string startTime;  
   int duration;  
public:  
   Activity();  
   Activity(string, string, int);  
   virtual ~Activity();  

   virtual void input();  
   virtual void output() const;  
   void setTitle(const string& t);
   string getTitle() const;

   virtual double calculatePriority() const = 0;  
   string getTimeSlot() const;  
}; 
