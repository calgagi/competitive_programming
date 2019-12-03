// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> a;
    while (true) {
        int b = -1;
        char c;
        cin >> b >> c;
        if (b == -1) {
            break;
        }
        a.pb(b);
    }

    a[1] = 12;
    a[2] = 2;

    for (int i = 0; i < a.size(); i += 4) {
        if (a[i] == 1) {
           a[a[i+3]] = a[a[i+1]] + a[a[i+2]];
        } else if (a[i] == 2) {
           a[a[i+3]] = a[a[i+1]] * a[a[i+2]];
        } else if (a[i] == 99) {
            break;
        } else {
            cout << "unknown opcode" << endl;
        }
    }    
    cout << "answer: ";

    cout << a[0] << endl;

    return 0;
}
