#include <bits/stdc++.h>
using namespace std;
// int inv(int k) {
//     for(int i = 0; i < 26; i++) {
//         if((k * i) % 26 == 1) return i;
//     }
//     return -1;
// }

int inv(int k) {
    cout << "\nFinding modular inverse of " << k << " mod 26:\n";
    for(int i = 0; i < 26; i++) {
        cout << k << " * " << i << " mod 26 = " << (k * i) % 26 << endl;
        if((k * i) % 26 == 1) {
            cout << "Modular inverse found: " << i << endl;
            return i;
        }
    }
    return -1;
}

string encrypt(string s, int k) {
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ((c - 'A') * k) % 26 + 'A';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ((c - 'a') * k) % 26 + 'a';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else {
            res += c;
        }
    }
    return res;
}
string decrypt(string s, int k) {
    int kinv = inv(k);  
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ((c - 'A') * kinv) % 26 + 'A';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ((c - 'a') * kinv) % 26 + 'a';
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
    int k;
    getline(cin, s);
    cin >> k;
    string enc = encrypt(s, k);
    cout << "Encrypted: " << enc << endl;
    string dec = decrypt(enc, k);
    cout << "Decrypted: " << dec << endl;
    return 0;
}
