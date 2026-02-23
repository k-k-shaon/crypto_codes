// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     string s;
//     getline(cin, s);
//     int L = s.size();
//     int n = ceil(sqrt(L));
//     char a[n][n];
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             a[i][j] = ' ';
//         }
//     }
//     int idx = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             if(idx < L) {
//                 a[i][j] = s[idx++];
//             }
//         }
//     }
//     string enc = "";
//     for(int j = 0; j < n; j++) {
//         for(int i = 0; i < n; i++) {
//             enc += a[i][j];
//         }
//     }
//     cout << enc << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int L = s.size();
    int n = ceil(sqrt(L));

    char a[n][n];

    // Initialize with space
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = ' ';
        }
    }

    // Fill matrix row-wise
    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(idx < L) {
                a[i][j] = s[idx++];
            }
        }
    }

    // SHOW MATRIX FORMATION
    cout << "\nMatrix Formation:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Encryption (column-wise reading)
    string enc = "";
    cout << "\nEncryption (Column-wise read):\n";
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            cout << a[i][j] << " ";
            enc += a[i][j];
        }
    }

    cout << "\n\nEncrypted Text: " << enc << endl;

    // -------- Decryption --------

    char b[n][n];
    idx = 0;

    // Fill column-wise
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            b[i][j] = enc[idx++];
        }
    }

    cout << "\nDecryption Matrix (Filled Column-wise):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    // Read row-wise to get original
    string dec = "";
    cout << "\nDecryption (Row-wise read):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
            dec += b[i][j];
        }
    }

    cout << "\n\nDecrypted Text: " << dec << endl;

    return 0;
}