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

    bool createTree(int v, int tl, int tr, vector<int>& in) {
        if (tl == tr) {
            tree[v] = in[tl];
            return true;
        } else {
            int tm = (tl+tr)/2;
            bool l = createTree(2*v, tl, tm, in);
            bool r = createTree((2*v)+1, tm+1, tr, in);           
            tree[v] = l ? tree[2*v] | tree[(2*v)+1] : tree[2*v] ^ tree[(2*v)+1];
            return !l; 
        }
    }

    int get() {
        return tree[1];
    }

    bool update(int v, int tl, int tr, int i, int new_val) {
        if (tr == tl) {
            tree[v] = new_val;
            return true;
        } else {
            int tm = (tl+tr)/2;    
            bool l;
            if (i <= tm) {
                l = update(v*2, tl, tm, i, new_val);
            } else {
                l = update((v*2)+1, tm+1, tr, i, new_val);
            }
            tree[v] = l ? tree[2*v] | tree[(2*v)+1] : tree[2*v] ^ tree[(2*v)+1];
            return !l;
        }
    }
    
    SegmentTree(vector<int>& in) {
        tree.resize(in.size()*4); 
        createTree(1, 0, in.size()-1, in);
    }
};
    


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int n, m; cin >> n >> m;
    vector<int> a(pow(2, n));
    forn(i, pow(2, n))
       cin >> a[i];

    SegmentTree t(a);

    forn(i, m) {
        int p, b; cin >> p >> b;
        t.update(1, 0, a.size()-1, p-1, b);
        cout << t.get() << endl;
    }

    return 0;
}
