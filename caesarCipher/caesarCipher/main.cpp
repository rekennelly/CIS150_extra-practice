//
//  main.cpp
//  caesarCipher
//
//  Created by Rachel Kennelly on 11/6/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<char> ALPHABET = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

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
            // Store spaces as -100
            if (text.at(messageIndex) == ' ')
            {
                messageInNumbers.push_back(-100);
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
            if (textInNumbers.at(textIndex) == -100)
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
        if (vector.at(index) < 0 && vector.at(index) != -100)
        {
            vector.at(index) += 26;
        }
        if (vector.at(index) != -100)
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


string encryptString(string message, int key)
{
    
    vector<int> messageInNumbers;
    
    // Translate string to numbers
    messageInNumbers = translateToNumbers(message);
    
    // Add key to message in numbers
    for (int index = 0; index < messageInNumbers.size(); index++)
    {
        if (messageInNumbers.at(index) != -100) {
            messageInNumbers.at(index) += key;
        }
    }
    
    // Mod by 26
    messageInNumbers = modValuesInVectorBy26(messageInNumbers);
    
    string ciphertext = "";
    // Translate string back to letters
    ciphertext = translateToLetters(messageInNumbers);
    
    return ciphertext;
}

string decryptString(string ciphertext, int key)
{
    string message = "";
    vector<int> cipherInNumbers;
    
    // Translate to numbers
    cipherInNumbers = translateToNumbers(ciphertext);
    
    // Subtract the key
    for (int index = 0; index < cipherInNumbers.size(); index++)
    {
        if (cipherInNumbers.at(index) != -100) {
            cipherInNumbers.at(index) -= key;
        }
    }
    
    // Mod by 26
    cipherInNumbers = modValuesInVectorBy26(cipherInNumbers);
    
    // Translate string back to letters
    message = translateToLetters(cipherInNumbers);
    
    return message;
}

int main() {
//    cout << encryptString("stop", 11) << endl;
//    cout << encryptString("experience", 7) << endl;
//    
//    cout << decryptString("lewlyplujl", 7) << endl;
//    cout << decryptString("deza", 11) << endl;
    
    bool userStillPlaying = true;
    
    while (userStillPlaying)
    {
        string userChoiceInput = "";
        char userChoice = ' ';
        
        string userKeyInput = "";
        int key = 0;
        
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
            
            cout << "Input the key: " << endl;
            getline(cin, userKeyInput);
            
            key = convertKeyStringInputToInt(userKeyInput);
            
            finalMessage = encryptString(userMessage, key);
            
            cout << "The encrypted message is: " << finalMessage << endl;
        }
        else
        {
            cout << "What is the message you would like to decrypt?" << endl;
            getline(cin, userMessage);
            
            cout << "Input the key: " << endl;
            getline(cin, userKeyInput);
            
            key = convertKeyStringInputToInt(userKeyInput);
            
            finalMessage = decryptString(userMessage, key);
            
            cout << "The decrypted message is: " << finalMessage << endl;
        }
        
        cout << "Would you like to go again? Y/N" << endl;
        getline(cin, userChoiceInput);

        if (toupper(userChoiceInput.at(0)) == 'N')
        {
            userStillPlaying = false;
        }
    }
    
    return 0;
}
