//
//  main.cpp
//  affineCipher
//
//  Created by Rachel Kennelly on 11/6/19.
//  Copyright © 2019 Rachel Kennelly. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<char> ALPHABET = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                               'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const int SPACE_KEY = -100;

vector<int> translateToNumbers(string text)
{
    // Convert string to upper case
    for (int index = 0; index < text.size(); index++)
    {
        text.at(index) = toupper(text.at(index));
    }
    
    vector<int> messageInNumbers;
    
    for (int messageIndex = 0; messageIndex < text.size(); messageIndex++)
    {
        for (int letterIndex = 0; letterIndex < ALPHABET.size(); letterIndex++)
        {
            // Store spaces as SPACE_KEY
            if (text.at(messageIndex) == ' ')
            {
                messageInNumbers.push_back(SPACE_KEY);
                break;
            }
            if (text.at(messageIndex) == ALPHABET.at(letterIndex))
            {
                messageInNumbers.push_back(letterIndex);
                break;
            }
        }
    }
    return messageInNumbers;
}

string translateToLetters(vector<int> textInNumbers)
{
    string message = "";
    
    for (int textIndex = 0; textIndex < textInNumbers.size(); textIndex++)
    {
        for (int letterIndex = 0; letterIndex < ALPHABET.size(); letterIndex++)
        {
            if (textInNumbers.at(textIndex) == SPACE_KEY)
            {
                message.append(" ");
                break;
            }
            else if (letterIndex == textInNumbers.at(textIndex))
            {
                message += ALPHABET.at(letterIndex);
                break;
            }
        }
    }
    return message;
}

vector<int> modValuesInVectorBy26(vector<int> vector)
{
    for (int index = 0; index < vector.size(); index++)
    {
        if (vector.at(index) < 0 && vector.at(index) != SPACE_KEY)
        {
            vector.at(index) += 26;
        }
        if (vector.at(index) != SPACE_KEY)
        {
            vector.at(index) = vector.at(index) % 26;
        }
    }
    return vector;
}

int convertKeyStringInputToInt(string keyInput)
{
    int key;
    
    key = stoi(keyInput);
    
    return key;
}

int calculateInverseOfAMod26(int a)
{
    int check;
    int aInverse = -1;
    
    for (int i = 0; i < 26; i++)
    {
        check = (a * i) % 26;
        
        if (check == 1)
        {
            aInverse = i;
            break;
        }
    }
    return aInverse;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

vector<int> getKey()
{
    string userInputA;
    string userInputB;
    int keyA;
    int keyB;
    
    cout << "Keys in affine ciphers take the form (a,b)." << endl;
    cout << "Enter your key value for a: " << endl;
    getline(cin, userInputA);
    cout << "Enter your key value for b: " << endl;
    getline(cin, userInputB);
    
    keyA = convertKeyStringInputToInt(userInputA);
    keyB = convertKeyStringInputToInt(userInputB);
        
    // Check validity of user choice of a
    while (gcd(keyA,26) != 1)
    {
        cout << "26 and a must be relatively prime. Choose a different value for a: " << endl;
        getline(cin, userInputA);
        keyA = convertKeyStringInputToInt(userInputA);
    }
    
    
    vector<int> key = {keyA, keyB};
    
    return key;
}

string encryptString(string message, vector<int> key)
{
    // Translate to numbers
    vector<int> messageInNumbers;
    int keyA = key.at(0);
    int keyB = key.at(1);
    string ciphertext = "";
    
    messageInNumbers = translateToNumbers(message);
    
    // Apply encryption function
    for (int index = 0; index < messageInNumbers.size(); index++)
    {
        if (messageInNumbers.at(index) != SPACE_KEY)
        {
            int m = messageInNumbers.at(index);
            messageInNumbers.at(index) = (keyA * m) + keyB;
        }
    }
    
    // Mod by 26
    messageInNumbers = modValuesInVectorBy26(messageInNumbers);
    
    // Translate to letters
    ciphertext = translateToLetters(messageInNumbers);
    
    return ciphertext;
}

string decryptString(string ciphertext, vector<int> key)
{
    vector<int> cipherInNumbers;
    int keyA = key.at(0);
    int keyB = key.at(1);
    string message = "";
    
    cipherInNumbers = translateToNumbers(ciphertext);
    
    int aInverse = calculateInverseOfAMod26(keyA);
    
    // Apply decryption function
    for (int index = 0; index < cipherInNumbers.size(); index++)
    {
        if (cipherInNumbers.at(index) != SPACE_KEY)
        {
            int number = aInverse * (cipherInNumbers.at(index) - keyB);
            cipherInNumbers.at(index) = number;
        }
    }
    
    // Mod by 26
    cipherInNumbers = modValuesInVectorBy26(cipherInNumbers);
    
    // Translate to letters
    message = translateToLetters(cipherInNumbers);
    
    return message;
}


int main() {
    bool userWantsToContinue = true;
    
    while (userWantsToContinue)
    {
        string userChoiceInput = "";
        char userChoice = ' ';
        
        vector<int> key;

        cout << "Do you want to [E]ncrypt or [D]ecrypt a message?" << endl;
        getline(cin, userChoiceInput);
        
        userChoice = toupper(userChoiceInput.at(0));
        
        while (userChoice != 'D' && userChoice != 'E')
        {
            cout << "Invalid choice. Please select [E]ncrypt or [D]ecrypt." << endl;
            getline(cin, userChoiceInput);
            userChoice = toupper(userChoiceInput.at(0));
        }
        
        string userMessage = "";
        string finalMessage = "";
        
        if (userChoice == 'E')
        {
            cout << "What is the message you would like to encrypt?" << endl;
            getline(cin, userMessage);
            
            key = getKey();
            
            finalMessage = encryptString(userMessage, key);
            
            cout << "The encrypted message is: " << finalMessage << endl;
        }
        else
        {
            cout << "What is the message you would like to decrypt?" << endl;
            getline(cin, userMessage);
            
            key = getKey();
            
            finalMessage = decryptString(userMessage, key);
            
            cout << "The decrypted message is: " << finalMessage << endl;
        }
        
        cout << "Would you like to go again? Y/N" << endl;
        getline(cin, userChoiceInput);
        
        if (toupper(userChoiceInput.at(0)) == 'N')
        {
            userWantsToContinue = false;
        }
        
    }
    return 0;
}
