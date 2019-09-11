//
//  main.cpp
//  leapYear
//
//  Created by Rachel Kennelly on 9/10/19.
//  Copyright © 2019 Rachel Kennelly. All rights reserved.
//

#include <iostream>

using namespace std;

bool leapYearCalculator(int year) {
    // No leap years before 1752
    if (year < 1752) {
        return false;
    }
    
    // If year is divisible by 400, it's a leap year
    if (year % 400 == 0) {
        return true;
    }
    
    // All other years divisible by 100 are not leap years
    if (year % 100 == 0) {
        return false;
    }
    
    // All other years divisible by 4 are leap years
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

int main() {
    int inputYear;
    
    cout << "Leap Year Calculator" << endl;
    cout << "Enter a year: " << endl;
    cin >> inputYear;
    
    if (leapYearCalculator(inputYear) == true) {
        cout << inputYear << " is a leap year." << endl;
    }
    
    if (leapYearCalculator(inputYear) == false) {
        cout << inputYear << " is not a leap year." << endl;
    }
    
    return 0;
}


