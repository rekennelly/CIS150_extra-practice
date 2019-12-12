//
//  main.cpp
//  vectorBuilder
//
//  Created by Rachel Kennelly on 11/14/19.
//  Copyright © 2019 Rachel Kennelly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    
    string toConvert;
    vector<char> convertedString;
    vector<char> const ALPHABET = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    
    cout << "Enter string to convert to vector: "  << endl;
    cin >> toConvert;
    
    cout << "{";
    for (int index = 0; index < toConvert.length(); index++) {
        cout << " {";
        cout << "'";
        cout << ALPHABET.at(index);
        cout << "',";
        cout << "'";
        cout << toConvert.at(index);
        cout << "'},";
        
    }
    cout << endl;
    
    
    return 0;
}
