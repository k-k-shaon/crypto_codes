#include <bits/stdc++.h>
using namespace std;
string encrypt(string s, int k) {
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ( (c - 'A') + k ) % 26 + 'A';
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ( (c - 'a') + k ) % 26 + 'a';
            res += x;
        }
        else {
            res += c;
        }
    }
    return res;
}
string decrypt(string s, int k) {
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ( (c - 'A') - k + 26 ) % 26 + 'A';
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ( (c - 'a') - k + 26 ) % 26 + 'a';
            res += x;
        }
        else {
            res += c;
        }
    }
    return res;
}
int main() {
    string s;
    int k;
    getline(cin, s);
    cin >> k;
    string enc = encrypt(s, k);
    string dec = decrypt(enc, k);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << dec << endl;
    return 0;
}
