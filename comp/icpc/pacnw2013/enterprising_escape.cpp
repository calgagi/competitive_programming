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

using namespace std;


int dfs(unordered_map<char, int>& c, vector<vector<char> >& m, unordered_map<int, unordered_map<int,bool> >& seen, int r, int x) {
    seen[r][x] = true;
    if (r == 0 || x == 0 || r == m.size()-1 || x == m[0].size()-1) {
        return c[m[r][x]];
    }
    int lr = INT_MAX;
    if (r > 0 && !seen[r-1][x]) lr = min(lr, dfs(c, m, seen, r-1, x));
    if (x > 0 && !seen[r][x-1]) lr = min(lr, dfs(c, m, seen, r, x-1));
    if (r < m.size()-1 && !seen[r+1][x]) lr = min(lr, dfs(c, m, seen, r+1, x));
    if (x < m[0].size()-1 && !seen[r][x+1]) lr = min(lr, dfs(c, m, seen, r, x+1));

    seen[r][x] = false;
    return lr + c[m[r][x]];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int T; cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, w, h; cin >> N >> w >> h;
        unordered_map<char, int> c;
        vector<vector<char> > m(h, vector<char>(w));
        for (int n = 0; n < N; n++) {
            char t; cin >> t;
            cin >> c[t];
        }
        int x, y;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> m[i][j];
                if (m[i][j] == 'E') { 
                    x = i;
                    y = j;
                }
            }
        }
        unordered_map<int, unordered_map<int, bool> > seen;
        cout << dfs(c, m, seen, x, y) << endl;
    }
         
    return 0;
}
