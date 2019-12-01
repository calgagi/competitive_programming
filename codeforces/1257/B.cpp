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
    forn(t, T) {
        ll x, y; cin >> x >> y;
        unordered_map<int,bool> seen;
        while (x < y) {
            if (seen.count(x)) break;
            seen[x] = true;
            if (x % 2 == 0) x = (3 * x) / 2;
            else x--;
        }
        if (x == y || y < x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
            
            

    return 0;
}
