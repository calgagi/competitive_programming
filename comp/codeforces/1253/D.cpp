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


class UF {
    public:
        vector<ll> size;
        vector<int> link;
        vector<int> max_item;

        UF(int n) {
            size.resize(n);
            link.resize(n);
            forn(i,n) {
                size[i] = 1;
                link[i] = i;
            }
            max_item = link;
        }

        int find(int a) {
            while(a != link[a]) {
                a = link[a];
            }
            return a;
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if(size[b] < size[a]) swap(a,b);
            link[a] = b;
            size[b] += size[a];
            max_item[a] = max_item[b] = max(max_item[a],max_item[b]);
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    int n, m;
    cin >> n >> m;
    UF uf(n+1);
    forn(i,m) {
        int a, b;
        cin >> a >> b;
        uf.unite(a,b);
    }
    
    int ans = 0;
    forn(i, n) {
        int j;
        for(j = i+1; j <= uf.max_item[i]; j++) {
            if(uf.find(j) != uf.find(i)) {
                uf.unite(i,j);
                ans++;
                uf.max_item[i] = max(uf.max_item[i], uf.max_item[j]);
            }
        }
        i = j-1; 
    }
    cout << ans << endl;

    return 0;
}
