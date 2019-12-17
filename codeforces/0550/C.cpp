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

    string s; cin >> s;
    const int n = s.length();
    for (int i = 0; i < n; i++) { 
        if (s[i] == '0' || s[i] == '8') {
            cout << "YES\n" << s[i] << endl;
            return 0;
        }
        for (int j = i+1; j < n; j++) {
            string y = s.substr(i,1) + s.substr(j,1);
            if (stoi(y) % 8 == 0) {
                cout << "YES\n" << y << endl;
                return 0;
            }
 
            for (int k = j+1; k < n; k++) {
                string x = s.substr(i,1) + s.substr(j,1) + s.substr(k,1);
                if (stoi(x) % 8 == 0) {
                    cout << "YES\n" << x << endl;
                    return 0;
                }
           
            }
        }
    }
    cout << "NO\n";
    return 0;
}
