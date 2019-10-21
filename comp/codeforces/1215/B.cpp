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
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    ll neg = 0, pos = 0;
    ll j = 0;
    bool odd = false;
    forn(i, n) {
        if (a[i] < 0)
            odd = !odd;
        if (!odd) {
            neg += j;
            pos += (i+1)-j;
        } else {
            neg += (i+1)-j;
            pos += j;
        }
        if (odd)
            j++; 
    }
    cout << neg << " " << pos << endl;
        
        

    return 0;
}
