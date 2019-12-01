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


    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    unordered_map<int,pair<int, priority_queue<int> > > c;

    forn(i, n) {
        int j = 0;
        while (a[i] != 0) {
            c[a[i]].x += j;
            c[a[i]].y.push(j);
            if (c[a[i]].y.size() > k) {
                c[a[i]].x -= c[a[i]].y.top();
                c[a[i]].y.pop();
            }
            a[i] /= 2;
            j++;
        } 
    }

    int res = INT_MAX;
    for (auto it = c.begin(); it != c.end(); it++) {
        if (it->second.y.size() == k)
            res = min(it->second.x, res);
    }
    cout << res << endl;


    return 0;
}
