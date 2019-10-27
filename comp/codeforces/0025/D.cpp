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

class UnionFind {
public:
    int* link, * size;

    UnionFind(int n) {
        link = new int[n];
        size = new int[n];
        forn(i, n) {
            link[i] = i;
            size[i] = 1;
        }
        return;
    }
    
    int find(int a) {
        while (link[a] != a)
            a = link[a];
        return a;
    }

    void unite(int a, int b) {
        int ap = find(a);
        int bp = find(b);
        if (size[ap] > size[bp])
            swap(ap, bp);
        link[ap] = bp;
        size[bp] += size[ap];
        return;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int n; cin >> n;
    UnionFind uf(n);
    vector<pair<int,int> > d;
    forn(i, n-1) {
        int a, b; cin >> a >> b;
        if (uf.find(a-1) == uf.find(b-1)) d.pb({a-1, b-1}); 
        else uf.unite(a-1, b-1);
    }
    vector<int> components;
    forn(i, n) {
        if (uf.link[i] == i)
            components.pb(i);
    }
    int i, j;
    cout << components.size()-1 << endl;
    for (i = 0, j = 0; i < components.size()-1; i++, j++) {
        cout << d[j].x+1 << " " << d[j].y+1 << " " << components[i]+1 << " " << components[i+1]+1 << endl;
    }
    return 0;
}
