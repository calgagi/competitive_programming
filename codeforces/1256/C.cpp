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
	
    int n, m, d; cin >> n >> m >> d;
    vector<int> p(m);
    int tot = 0;
    forn(i, m) { 
        cin >> p[i];
        tot += p[i];
    }
    
    int spacing_min = (n-tot)/(m+1);
    int spacing_max = (n-tot) % (m+1) ? 1+spacing_min : spacing_min;
    int count_max = (n-tot) % (m+1);
    if (spacing_max >= d) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        vector<int> a(n, 0);
        int it = spacing_max;
        int i;
        for(i = 0; i < count_max-1; i++) {
            for(int j = 0; j < p[i]; j++){
                a[it] = i+1;
                it++;
            }
            it += spacing_max;
        }
        for( ; i < m; i++) {
            for(int j = 0; j < p[i]; j++){
                a[it] = i+1;
                it++;
            }
            it += spacing_min;
        }
        for(auto& z : a) cout << z << " ";
        cout << endl;
    }
         
    return 0;
}
