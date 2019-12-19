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


void solve() {
    string s, h;
    cin >> s >> h;
    unordered_map<char,int> see;
    for(auto& i : s) see[i]++;
    int counter = see.size();
    int b = 0, e = 0;
    while (e < (int)h.length()) {
        if (see.find(h[e]) != see.end()) {
            see[h[e]]--;
            if (see[h[e]] == 0) {
                counter--;
            }
        }
        while (counter == 0) {
            if (e - b+1 == (int)s.length()) {
                cout << "YES" << endl;
                return;
            }
            if (see.count(h[b])) {
                see[h[b]]++;
                if (see[h[b]] == 1) counter++;
            }
            b++;
        }
        e++;
    }
    cout << "NO" << endl;
         
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
