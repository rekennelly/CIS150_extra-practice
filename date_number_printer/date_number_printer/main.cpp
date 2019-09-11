//
//  main.cpp
//  date_number_printer
//
//  Created by Rachel Kennelly on 9/10/19.
//  Copyright © 2019 Rachel Kennelly. All rights reserved.
//


/*
 Write a program that, given a date, three ints (for example, 11 27 1997), will print the number of that day within its year: i.e. Jan 1st is always 1, Dec 31st is either 365 or 366.
 The months of the year have lengths according to the following rules:
 
 The odd months up to and including month 7 have 31 days.
 The even months from 8 upwards, have 31 days.
 Month 2 has 28 days except in a leap year when it has 29 days.
 The rest of the months have 30 days.
 */

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

int monthlengthCalculator(int month, int year) {
    int monthLength;
    
    if (month % 2 == 1) {
        monthLength = 31;
    }
    if (month >= 8) {
        monthLength = 31;
    }
    if (month == 2) {
        if (leapYearCalculator(year) == true) {
            monthLength = 29;
        }
        monthLength = 28;
    }
    else {
        monthLength = 30;
    }
    
    return monthLength;
}

int main () {
    int inputMonth;
    int inputDay;
    int inputYear;
    
    int dayCount = 0;
    
    cout << "Input a date: (MM DD YYYY)" << endl;
    cout << "Month: ";
    cin >> inputMonth;
    cout << "Day: ";
    cin >> inputDay;
    cout << "Year: ";
    cin >> inputYear;
    
    // Calculate days until month of given date
    for(int a = inputMonth - 1; a > 0; a = a - 1) {
        dayCount = dayCount + monthlengthCalculator(inputMonth, inputYear);
    }
    
    // Add days of given month
    dayCount = dayCount + inputDay;
    
    cout << inputMonth << "/" << inputDay << "/" << inputYear << " is Day "
         << dayCount << " of the year." << endl;
    
    return 0;
}
