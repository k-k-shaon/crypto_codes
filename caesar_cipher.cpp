#include <bits/stdc++.h>
using namespace std;
string encrypt(string s) {
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ( (c - 'A') + 3 ) % 26 + 'A';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ( (c - 'a') + 3 ) % 26 + 'a';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else {
            res += c;
        }
    }
    return res;
}
string decrypt(string s) {
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ( (c - 'A') - 3 + 26 ) % 26 + 'A';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ( (c - 'a') - 3 + 26 ) % 26 + 'a';
            cout<<c<<"->"<<x<<endl;
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
    // int k;
    getline(cin, s);
    // cin >> k;
    string enc = encrypt(s);
    cout << "Encrypted: " << enc << endl;
    string dec = decrypt(enc);
    cout << "Decrypted: " << dec << endl;
    return 0;
}
