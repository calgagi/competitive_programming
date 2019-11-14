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
	
    int T; cin >> T;
    forn(t, T) {
        int n; cin >> n;
        vector<int> monsters(n);
        int max_monster = 0;
        for(auto& i : monsters) {
            cin >> i;
            max_monster = max(max_monster, i);
        }
        int h; cin >> h;
        unordered_map<int,int> e;
        int max_e = 0;
        pair<int,int> x;
        forn(i, h) {
            cin >> x.x >> x.y;
            if (!e.count(x.y)) e[x.y] = 0;
            e[x.y] = max(x.x, e[x.y]);
            max_e = max(x.y, max_e);
        } 
        vector<int> endurances(max_e+1, 0);
        endurances[max_e] = e[max_e];
        map<int,int> tree;
        tree[e[max_e]] = max_e;
        forb(i, max_e) {
            if (e.count(i))
                endurances[i] = max(endurances[i+1], e[i]);
            else endurances[i] = endurances[i+1];
            if (endurances[i] != endurances[i+1])
                tree[endurances[i]] = i;
        }
        //for(auto it = tree.begin(); it != tree.end(); it++) cout << it->first << "," << it->second << " ";
        //cout << endl;
        if (max_monster > endurances[1]) {
            cout << -1 << endl;
        } else {
            int res = 0;
            int i = 0;
            while (i < n) {
                auto cur = tree.upper_bound(monsters[i]-1);
                int j;
                for (j = 1; j < cur->second && i+j < n; j++) {
                    if (monsters[j+i] > cur->first) {
                        auto maybe_cur = tree.upper_bound(monsters[j+i]-1);
                        if (maybe_cur->second >= j+1)
                            cur = maybe_cur;
                        else
                            break;
                    }
                }
                i += j;
                res++;
                      
            }
            cout << res << endl;
        }
    }
                 

    return 0;
}
