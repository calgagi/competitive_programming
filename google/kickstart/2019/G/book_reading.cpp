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
        cout << "Case #" << t+1 << ": ";
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<bool> b(N+1, true);
        forn(i, M) {
            int a; cin >> a;
            b[a] = false;
        }
        vector<ll> a(N+1, -1);
        ll answer = 0;
        forn(q, Q) {
            int r; cin >> r; 
            if (a[r] != -1) {
                answer += a[r];
                continue;
            }
            int tot = 0;
            for (int i = r; i <= N; i += r)
                 if (b[i]) tot++;
            answer += tot;
            a[r] = tot;
        }
        cout << answer << endl;
    }
    return 0;
}
