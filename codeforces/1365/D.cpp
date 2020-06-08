/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

const char emp = '.', wall = '#', good = 'G', bad = 'B';
vector<ii> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int num_good;
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visit;
bool seen_bad;

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || visit[i][j]) {
        return;
    }
    if (grid[i][j] == wall) {
        return;
    }
    visit[i][j] = 1;

    if (grid[i][j] == good) {
        num_good--;
    }
    else if (grid[i][j] == bad) {
        seen_bad = 1;
        return;
    }
        
    
    for (ii& d : dir) {
        dfs(i+d.f, j+d.s);
    }

    return;
}

void solve() { 
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    num_good = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == bad) {
                for (ii& d : dir) {
                    if (d.f+i >= 0 && d.f+i < n && d.s+j >= 0 && d.s+j < m && grid[i+d.f][j+d.s] == emp) {
                        grid[d.f+i][d.s+j] = wall;
                    }
                }
            }
            else if (grid[i][j] == good) {
                num_good++;
            }
        }
    }

    seen_bad = 0;
    visit.assign(n, vector<bool>(m, 0));
    dfs(n-1, m-1);

    if (num_good == 0 && !seen_bad) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
