// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
template<class T>
inline std::ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii) { os << " " << *ii; } os << "]"; return os; }
template<class T1, class T2>
inline std::ostream& operator<<(ostream& os, const pair<T1, T2>& p) { os << "["; os << p.F << "," << p.S; os << "]"; return os; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    ll n, d; cin >> n >> d;
    vector<pair<ll,ll>> friends(n);
    forn(i, n) cin >> friends[i].F >> friends[i].S;
    
    sort(friends.begin(), friends.end());
    ll b = 0, e = 0, res = 1, curSum = 0;
    while (e < n) {
        curSum += friends[e].S;
        while (friends[e].F-friends[b].F >= d && b <= e) {
            curSum -= friends[b].S;
            b++;
        }
        res = max(curSum, res);
        e++;
    }
    cout << res << endl;

    return 0;
}
