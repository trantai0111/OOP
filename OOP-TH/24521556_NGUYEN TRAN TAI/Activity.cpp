#include "Activity.h"  
#include <iostream>  
#include <iomanip>  

Activity::Activity() : title(""), startTime("00:00"), duration(0) {}  
Activity::Activity(string t, string st, int d) : title(t), startTime(st), duration(d) {}  
Activity::~Activity() {}  

void Activity::input() {  
   getline(cin, title);   
   getline(cin, startTime);  
   cin >> duration;  
   cin.ignore();  
}  

void Activity::output() const {  
	cout << title;
}

void Activity::setTitle(const string& t)
{
	title = t;
}

string Activity::getTitle() const
{
	return title;
}

string Activity::getTimeSlot() const {  
   int hour = stoi(startTime.substr(0, 2));  
   if (hour >= 5 && hour < 12) return "Sáng";  
   if (hour >= 12 && hour < 18) return "Chiều";  
   if (hour >= 18 && hour < 23) return "Tối";  
   return "Khác";  
}
