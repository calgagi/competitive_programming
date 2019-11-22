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
    vector<int> where(n);
    vector<tuple<int,int,int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = make_tuple(i, i, i);
        where[i] = i;
    }
    forn(i, m) {
        int a; cin >> a; a--;
        if (where[a] != 0) {
            int swp_idx = where[a]-1;
            swap(p[swp_idx], p[where[a]]); 
            where[a]--;
            where[get<0>(p[swp_idx+1])]++;
            get<2>(p[swp_idx+1]) = max(get<2>(p[swp_idx+1]), where[get<0>(p[swp_idx+1])]);
            get<1>(p[where[a]]) = min(get<1>(p[where[a]]), where[a]); 
        }
    }
    forn(i, n) {
        cout << get<1>(p[where[i]])+1 << " " << get<2>(p[where[i]])+1 << endl;
    }
	

    return 0;
}
