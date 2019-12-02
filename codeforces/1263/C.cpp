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
    int n; cin >> n;
    set<int> s;
    s.insert(0);
    for (int i = 1; i <= sqrt(n); i++) {
        if (!s.count(n/i)) {
            s.insert(n/i);
            s.insert(i);
        }
    }

    cout << s.size() << endl;
    for (auto& item : s) {
        cout << item << " ";
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    int t; cin>> t;
    while(t--)
        solve();

    return 0;
}
