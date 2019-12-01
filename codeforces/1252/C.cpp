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

vector<int> r, c;
int N;


class UnionFind {
    public:
    vector<int> link;
    vector<int> size;

    UnionFind(int n) {
        link.resize(n);
        size.resize(n);
        forn(i, n) {
            link[i] = i;
            size[i] = 1;
        }
    }

    int find(int a) {
        while (a != link[a])
            a = link[a];
        return a;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(size[a] < size[b]) swap(a,b);
        link[b] = a;
        size[a] += size[b];
    }
};

UnionFind *rows, *cols;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    
    // Can use !^ to determine if even or not
    // DFS too slow
    // Looked at solution: Use Union-Find to query in log(n)
    bool flag = rows->find(min(x1, x2)) == rows->find(max(x1, x2)) && cols->find(min(y1, y2)) == cols->find(max(y1, y2));

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int Q; cin >> N >> Q;
    r.resize(N); c.resize(N);    
    rows = new UnionFind(N);
    cols = new UnionFind(N);
    forn(i, N) {
        cin >> r[i];
        r[i] %= 2;
        if (i > 0 && r[i] == r[i-1]) rows->unite(i, i-1);
    }
    forn(i, N){
        cin >> c[i];
        c[i] %= 2;
        if (i > 0 && c[i] == c[i-1]) cols->unite(i, i-1);
    }
    while(Q--)
        solve();

    return 0;
}
