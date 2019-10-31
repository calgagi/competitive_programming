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
	
    ld ans = LLONG_MAX;
    vector<pair<ld, ld> > c(2);
    pair<ld, ld> g;
    cin >> g.x >> g.y;
    for (int i = 0; i < 2; i++)
        cin >> c[i].x >> c[i].y;
    if (g.x <= max(c[0].x, c[1].x) && g.x >= min(c[0].x, c[1].x)) {
        ans = min(abs(c[0].y-g.y), abs(c[1].y-g.y));        
    } else if (g.y <= max(c[0].y, c[1].y) && g.y >= min(c[0].y, c[1].y)) {
        ans = min(abs(c[0].x-g.x), abs(c[1].x-g.x));
    } else { 
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                ans = min(ans, sqrt(pow(c[i].x-g.x, 2) + pow(c[j].y-g.y, 2))); 
            }
    }
    cout << fixed << setprecision(3) << ans << endl;

    return 0;
}
