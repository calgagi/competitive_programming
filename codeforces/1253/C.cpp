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
	
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    forn(i,n) cin >> a[i];

    sort(a.begin(), a.end());
    
    vector<ll> ans(n, 0);
    ll current = 0;
    forn(i, n) {
        ans[i] = a[i] + (i-m < 0 ? 0 : ans[i-m]);
        current += ans[i];
        cout << current << " ";
    }
    cout << endl;
        

    return 0;
}
