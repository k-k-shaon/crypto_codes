#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r1, r2;
    cin >> r1 >> r2;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    while (r2 != 0)
    {
        int q = r1 / r2;
        int r = r1 % r2;
        int s = s1 - q * s2;
        int t = t1 - q * t2;
        cout << "q=" << q << " r1=" << r1 << " r2=" << r2
             << " s1=" << s1 << " s2=" << s2
             << " t1=" << t1 << " t2=" << t2 << endl;
        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }
    cout << "gcd = " << r1 << endl;
    cout << "s = " << s1 << endl;
    cout << "t = " << t1 << endl;
    return 0;
}
