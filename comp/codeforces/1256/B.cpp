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

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<int> locations(n+1);
    forn(i, n) {
        cin >> p[i];
        locations[p[i]] = i;
    }
    int c = 1;
    int loc, prev_loc = 0;
    while(c < n) {
        loc = locations[c];
        if (prev_loc == loc) prev_loc++;
        else if (prev_loc < loc) {
            int num = p[loc-1];
            locations[num]++;
            p.erase(p.begin()+loc); 
            p.insert(p.begin()+prev_loc, c);
            prev_loc = loc;
        }
        c++;
    }
    for(auto& i : p) cout << i << " ";
    cout << endl;
    return;
} 
        
        

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
