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
    // Time: O(n)
    string s, c, res;
    cin >> s >> c;
    res = s;
    sort(s.begin(), s.end());
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] != res[i]) {
            int pos = i;
            for (int j = i+1; j < (int)s.length(); j++)
                if (s[i] == res[j]) pos = j;
            swap(res[i], res[pos]);
            break;
        }
    }

    if (res < c)
        cout << res << endl;
    else
        cout << "---" << endl;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());


    int n; cin >> n;
    while (n--) solve(); 

    return 0;
}
