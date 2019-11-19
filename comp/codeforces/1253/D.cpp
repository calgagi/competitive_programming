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
	
    int n, m;
    cin >> n >> m;
    vector<int> attached(n+1, -1);
    vector<bool> before(n+1, false);
    for(int i = 0; i < n+1; i++) attached[i] = i;
    forn(i,m) {
        int from, to;
        cin >> from >> to;
        if(from > to) swap(to, from);
        attached[from] = max(attached[from], to);
        before[to] = true;
    }
    // Algorithm
    // For all nodes i:
    //      If attached[i] > i:
    //          e = attached[i];
    //          i++;
    //          while i < e:
    //              e = max(attached[i], e);
    //              if(i 
    
    int ans = 0;
    fore(i, 1, n+1) {
        if(a[i] != i) {
            int e = a[i];
            i++;
            while(i < e){
                if(!attached[i] && a[i] > e) ans++;
                e = max(e, a[i]);
                i++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
