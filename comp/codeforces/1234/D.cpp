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
    unordered_map<char,int>* tree;
    
    void createTree(int v, int tl, int tr, string& in) {
        if (tl == tr) {
            tree[v][in[tl]] = 1;
        } else {
            int tm = (tl + tr) / 2;
            createTree(v*2, tl, tm, in);
            createTree((v*2)+1, tm+1, tr, in);
            for (auto it = tree[v*2].begin(); it != tree[v*2].end(); it++) {
                tree[v][it->first] += it->second;
            }
            for (auto it = tree[(v*2)+1].begin(); it != tree[(v*2)+1].end(); it++) {
                tree[v][it->first] += it->second;
            }            
        }
    }

    char update(int v, int tl, int tr, int i, char new_val) {
        if (tl == tr) {
            char x = tree[v].begin()->first;
            tree[v][new_val] = 1;
            tree[v][x]--;
            tree[v].erase(x);
            return x;
        } else {
            int tm = (tl + tr) / 2;
            char res;
            if (i <= tm)
                res = update(v*2, tl, tm, i, new_val);
            else
                res = update((v*2)+1, tm+1, tr, i, new_val);
            tree[v][res]--;
            if (tree[v][res] == 0) tree[v].erase(res);
            tree[v][new_val]++;

            return res;
        }
    }


    unordered_map<char,int> get(int v, int tl, int tr, int l, int r) {
        if (l > r) return unordered_map<char,int>();
        if (tl == l && tr == r) 
            return tree[v]; 
        int tm = (tl + tr) / 2;
        auto res = get(v*2, tl, tm, l, min(r, tm));
        auto res2 = get((v*2)+1, tm+1, tr, max(l, tm+1), r);
        res.insert(res2.begin(), res2.end());
        return res;
    }
            

    SegmentTree(string& in) {
        tree = new unordered_map<char,int>[4*in.length()];
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
            cout << t.get(1, 0, s.length()-1, l-1, r-1).size() << endl;
        }
    }

    return 0;
}
