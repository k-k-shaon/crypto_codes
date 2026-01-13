#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int L = s.size();
    int n = ceil(sqrt(L));
    char a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = ' ';
        }
    }
    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(idx < L) {
                a[i][j] = s[idx++];
            }
        }
    }
    string enc = "";
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            enc += a[i][j];
        }
    }
    cout << enc << endl;
    return 0;
}
