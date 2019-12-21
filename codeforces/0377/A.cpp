// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> a;
int n, m, k;

void dfs(int r, int c) {
    a[r][c] = 'Z';
    if (r < n-1 && a[r+1][c] == '.')
        dfs(r+1, c);
    if (c < m-1 && a[r][c+1] == '.')
        dfs(r, c+1);
    if (c > 0 && a[r][c-1] == '.')
        dfs(r, c-1);
    if (r > 0 && a[r-1][c] == '.')
        dfs(r-1, c);
    if (k) { 
        a[r][c] = 'X';
        k--;
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    
    cin >> n >> m >> k;
    a = vector<vector<char>>(n, vector<char>(m));
    for (auto& v : a) 
        for (auto& s : v)
            cin >> s;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.') dfs(i, j);
             
    for (auto& v : a) {
        for (auto& s : v) {
            cout << (s == 'Z' ? '.' : s);
        }
        cout << endl;
    }

    return 0;
}
