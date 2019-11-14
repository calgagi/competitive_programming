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
	
    int T; cin >> T;
    forn(t, T){
        vector<int> c(10);
        int mx = INT_MAX, d = -1;
        forn(i, 10) {
            cin >> c[i];
            if (mx > c[i] || (mx >= c[i] && d == 0)) {
                d = i;
                mx = c[i];
            }
        }
        if (d == 0) {
            int j;
            fore(i, 1, 10) 
                if (c[i]) {
                    j = i; break;
                }
            cout << j;
        }
        forn(i, mx+1) cout << d;
        cout << endl;  
    }

    return 0;
}
