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

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int,int>> a(n);
    forn(i, n) {
        cin >> a[i].x;
        a[i].y = i+1;
    }
    sort(a.begin(), a.end());
    if (m < n || n == 2) {
        cout << "-1" << endl;
    } else {
        ll res = a.back().x + a[0].x;
        vector<pair<int,int>> ans;
        ans.pb({a.back().y, a[0].y});
        forn(i, n-1) {
            res += a[i].x + a[i+1].x;
            ans.pb({a[i].y, a[i+1].y});
        }
        m -= n;
        forn(i, m) {
            res += a[0].x + a[1].x;
            ans.pb({a[0].y, a[1].y});
        }
        cout << res << endl;
        for (auto& p : ans) {
            cout << p.x << " " << p.y << endl;
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    int T; cin >> T;
    while (T--) solve();

    return 0;
}
