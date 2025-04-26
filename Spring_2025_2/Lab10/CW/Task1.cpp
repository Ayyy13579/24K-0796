#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encrypt(string& word) {
    int length = word.length();
    string newstring;
    for (int i = 0; i < length; i++) {
        newstring += (char)(word[i] + (i+1));
    }
    return newstring;
}

string decrypt(string& word) {
    int length = word.length();
    string newstring;
    for (int i = 0; i < length; i++) {
        newstring += (char)(word[i] - (i+1));
    }
    return newstring;
}


int main() {
    string word, encryptedWord, decryptedWord;
    ofstream file("encrypt.txt");
    cout << "Enter a string: " << endl;
    getline(cin, word);
    encryptedWord = encrypt(word);
    file << encryptedWord << endl;
    decryptedWord = decrypt(encryptedWord);
    cout << "Decrypted string: " << decryptedWord << endl;
    file.close();
}