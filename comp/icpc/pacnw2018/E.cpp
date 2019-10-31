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

int n, m;

int dfs(vector<vector<char> >& b, pair<int,int> c, unordered_map<int,unordered_set<int> >& seen) {
    if (c.x == 0 || c.x == n-1 || c.y == 0 || c.y == m-1) return 1;
    int possible = 0;
    seen[c.x].insert(c.y);
    if (c.x+1 < n && b[c.x+1][c.y] == '.' && seen[c.x+1].find(c.y) != seen[c.x+1].end())
        possible |= dfs(b, {c.x+1, c.y}, seen);
    if (c.x > 0 && b[c.x-1][c.y] == '.' && seen[c.x-1].find(c.y) != seen[c.x-1].end())
        possible |= dfs(b, {c.x-1, c.y}, seen);
    if (c.y+1 < m && b[c.x][c.y+1] == '.' && seen[c.x].find(c.y+1) != seen[c.x].end())
        possible |= dfs(b, {c.x, c.y+1}, seen);
    if (c.y > 0 && b[c.x][c.y-1] == '.' && seen[c.x].find(c.y-1) != seen[c.x].end())
        possible |= dfs(b, {c.x, c.y-1}, seen);
    seen[c.x].erase(c.y);
    return possible;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c; cin >> n >> m >> c;
    vector<vector<char> > b(n, vector<char>(m));
    forn(i, n) forn(j, m) cin >> b[i][j];
    int d[c];
    pair<int,int> bank;
    forn(i, c) cin >> d[i];
    forn(i, n) forn(j, m)
        if (b[i][j] == 'B') {
            bank.x = i, bank.y = j;
            break;
        }

    // Test for -1
    unordered_map<int, unordered_set<int> > seen;
    if (dfs(b, bank, seen)) {
        cout << "-1" << endl;
        return 0;
    }






    return 0;
}
