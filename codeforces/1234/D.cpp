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

class SegmentTree {
public:
    vector<int> tree;
    
    void createTree(int v, int tl, int tr, string& in) {
        if (tl == tr) {
            tree[v] = (1 << (in[tl] - 'a'));
        } else {
            int tm = (tl + tr) / 2;
            createTree(v*2, tl, tm, in);
            createTree((v*2)+1, tm+1, tr, in);
            tree[v] = tree[v*2] | tree[(v*2)+1]; 
        }
    }

    void update(int v, int tl, int tr, int i, char new_val) {
        if (tl == tr) {
            tree[v] = (1 << (new_val - 'a'));
        } else {
            int tm = (tl + tr) / 2;
            if (i <= tm)
                update(v*2, tl, tm, i, new_val);
            else
                update((v*2)+1, tm+1, tr, i, new_val);
            tree[v] = tree[v*2] | tree[(v*2)+1];
        }
    }


    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0; 
        if (tl == l && tr == r)
            return tree[v];
        int tm = (tl + tr) / 2;
        return get(v*2, tl, tm, l, min(r, tm)) |
               get((v*2)+1, tm+1, tr, max(l, tm+1), r);
    }
            

    SegmentTree(string& in) {
        tree.resize(in.length()*4); 
        createTree(1, 0, in.length()-1, in);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    string s; cin >> s;
    SegmentTree t(s);
    int n; cin >> n;
    forn(i, n) {
        int d; cin >> d;
        if (d == 1) {
            int j; cin >> j;
            char p; cin >> p;
            t.update(1, 0, s.length()-1, j-1, p);
        } else {
            int l, r;
            cin >> l >> r;
            cout << __builtin_popcount(t.get(1, 0, s.length()-1, l-1, r-1)) << endl;
        }
    }

    return 0;
}
