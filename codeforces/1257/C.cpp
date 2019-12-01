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
        int n; cin >> n;
        vector<int> a(n);
        for(auto& i : a) cin >> i;
        int b = 0, e = 0, res = INT_MAX;
        unordered_map<int,int> freq;
        int m = 1;
        while (e < a.size()) {
            freq[a[e]]++;
            while (b <= e && m < freq[a[e]]) {
                res = min(e-b+1, res);
                freq[a[b]]--;
                b++;
            }
            e++;
        }
        if (res == INT_MAX) res = -1;
        cout << res << endl;
    }

    return 0;
}
