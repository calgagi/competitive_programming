// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define x first
#define y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int,int> w[2], b[2][2];
    cin >> w[0].fi >> w[0].se >> w[1].fi >> w[1].se;
    cin >> b[0][0].fi >> b[0][0].se >> b[0][1].fi >> b[0][1].se;
    cin >> b[1][0].fi >> b[1][0].se >> b[1][1].fi >> b[1][1].se;

    for (int i = 0; i < 2; i++) {
        b[i][0].fi = max(0, b[i][0].fi - w[0].fi);
        b[i][0].se = max(0, b[i][0].se - w[0].se); 
        b[i][1].fi = min(b[i][1].fi - w[0].fi, 
            


    return 0;
}
