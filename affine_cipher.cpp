#include <bits/stdc++.h>
using namespace std;
// int inverse(int k) {
//     for(int i = 0; i < 26; i++) {
//         if((k * i) % 26 == 1) return i;
//     }
//     return -1; 
// }

int inverse(int k) {
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

string encrypt(string s, int k1, int k2) {
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ((c - 'A') * k1 + k2) % 26 + 'A';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ((c - 'a') * k1 + k2) % 26 + 'a';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else res += c;
    }
    return res;
}
string decrypt(string s, int k1, int k2) {
    int k1_inv = inverse(k1);
    string res = "";
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            char x = ((c - 'A' - k2 + 26) * k1_inv) % 26 + 'A';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else if(c >= 'a' && c <= 'z') {
            char x = ((c - 'a' - k2 + 26) * k1_inv) % 26 + 'a';
            cout<<c<<"->"<<x<<endl;
            res += x;
        }
        else res += c;
    }
    return res;
}
int main() {
    string s;
    int k1, k2;
    getline(cin, s);
    cin >> k1 >> k2;
    string enc = encrypt(s, k1, k2);
    cout << "Encrypted: " << enc << endl;
    string dec = decrypt(enc, k1, k2);
    cout << "Decrypted: " << dec << endl;
    return 0;
}