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
	
    int N; cin >> N;
    vector<int> p(N);
    forn(i, N) cin >> p[i];
    reverse(p.begin(), p.end());
    if(N % 2 == 1) swap(p[N/2], p[(N/2)+1]);
    forn(i, N) cout << p[i] << " ";
    cout << endl;

    return 0;
}
