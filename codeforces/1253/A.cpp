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
	
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        forn(i, n) cin >> a[i];
        forn(i, n) cin >> b[i];
        int i = 0;
        while(i < n && a[i] == b[i]) i++;
        if(i == n) {
            cout << "YES" << endl;
            continue;
        }
        int diff = b[i] - a[i];
        if (diff <= 0) {
            cout << "NO" << endl;
            continue;
        }
        while(i < n && b[i] - a[i] == diff) i++;
        if(i == n) {
            cout << "YES" << endl;
            continue;
        } else if (a[i] - b[i] == 0) {
            while(i < n && a[i] == b[i]) i++;
            if(i == n) {
                cout << "YES" << endl;
                continue;
            }
        } 
        cout << "NO" << endl;
    }

    return 0;
}
