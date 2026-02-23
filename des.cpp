#include <bits/stdc++.h>
using namespace std;

// XOR function
string XOR(string a, string b) {
    string res = "";
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == b[i]) res += '0';
        else res += '1';
    }
    return res;
}

int main() {
    string plaintext, key;

    cout << "Enter 64-bit binary plaintext: ";
    cin >> plaintext;

    cout << "Enter 64-bit binary key: ";
    cin >> key;

    // Split into two halves
    string L = plaintext.substr(0, 32);
    string R = plaintext.substr(32, 32);

    cout << "\nInitial L0: " << L << endl;
    cout << "Initial R0: " << R << endl;

    // 16 Rounds
    for(int i = 1; i <= 16; i++) {
        string temp = R;

        // Simplified F function = XOR with first 32 bits of key
        string f = XOR(R, key.substr(0,32));

        R = XOR(L, f);
        L = temp;

        cout << "\nRound " << i << ":\n";
        cout << "L" << i << ": " << L << endl;
        cout << "R" << i << ": " << R << endl;
    }

    // Final Swap
    string ciphertext = R + L;

    cout << "\nCiphertext: " << ciphertext << endl;

    return 0;
}