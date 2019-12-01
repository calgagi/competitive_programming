// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    unordered_map<int,int> xs;
    unordered_map<int,int> ys;
    unordered_map<int, unordered_map<int,int> > ps;
    ull r = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (!ps.count(x))
            ps[x] = unordered_map<int,int>();
        if (!ps[x].count(y))
            ps[x][y] = 0;
        if (!xs.count(x))
            xs[x] = 0;
        if (!ys.count(y))
            ys[y] = 0;
        ps[x][y]++;
        xs[x]++;
        ys[y]++;
        int t = (xs[x]-1) + (ys[y]-1) - (ps[x][y]-1);
        r += t;
    }
    cout << r << endl;


    return 0;
}
