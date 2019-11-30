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
    srand(chrono::steady_clock::now().time_since_epoch().count());


    ld m, n; cin >> m >> n;

    ld ans = 0;
    forn(i, m) {
        ld v = i+1;
        ans += v * (ld)(pow(v/m, n) - pow((v-1)/m, n));
    }
    cout << ans << endl;
	

    return 0;
}
