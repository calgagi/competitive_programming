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
	
    int q; cin >> q;
    while(q--){
        int a, b, n, S;
        cin >> a >> b >> n >> S;
        int num_a = S / n;
        S -= min(num_a, a)*n;
        if(b >= S)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
