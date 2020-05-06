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

    int n; cin >> n;
    vector<int> a(n+1, 0);
    forn(i, n) {
        int l, r;
        cin >> l >> r;
        fore(j, l, r+1)
            a[j]++;
    }
    forb(i, n+1) {
        if (a[i] == i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;


	

    return 0;
}
