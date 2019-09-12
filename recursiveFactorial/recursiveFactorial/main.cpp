//
//  main.cpp
//  recursiveFactorial
//
//  Created by Rachel Kennelly on 9/12/19.
//  Copyright © 2019 Rachel Kennelly. All rights reserved.
//

#include <iostream>

using namespace std;

int factorial(int n) {
    if (n > 0) {
        return n * factorial(n-1);
    } else {
        return 1;
    }
}

int main() {
    int num;
    int solution;
    
    cout << "Enter a number to compute its factorial: " << endl;
    cin >> num;
    
    solution = factorial(num);
    cout << num << "! = " << solution << endl;
    
    return 0;
}
