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
        int n, a, b, k; cin >> n >> k >> a >> b;
        int c = abs(a-b);
        if (a > b) swap(a,b);
        int diff = min(a-1, k);
        a -= diff;
        k -= diff;
        b += min(n-b, k);
        cout << abs(a-b) << endl;
    }


    return 0;
}
