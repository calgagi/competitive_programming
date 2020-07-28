/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

string path;
const int n = 7, w = 48;
bool grid[n][n];
int ans = 0;
int count = 0;

bool empty_square(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n && !grid[row][col];
}

void dfs(int row, int col, int where) {
    if (row == 6 && col == 0) {
        ans += where == 48;
        return;
    }

    grid[row][col] = 1;

    if (path[where] == '?' || path[where] == 'D') {
        if (empty_square(row + 1, col) && !(!empty_square(row + 2, col) && empty_square(row + 1, col - 1) && empty_square(row + 1, col + 1))) {
            dfs(row + 1, col, where + 1);
        }
    }
    if (path[where] == '?' || path[where] == 'U') {
        if (empty_square(row - 1, col) && !(!empty_square(row - 2, col) && empty_square(row - 1, col - 1) && empty_square(row - 1, col + 1))) {
            dfs(row - 1, col, where + 1);
        }
    } 
    if (path[where] == '?' || path[where] == 'R') {
        if (empty_square(row, col + 1) && !(!empty_square(row, col + 2) && empty_square(row + 1, col + 1) && empty_square(row - 1, col + 1))) {
            dfs(row, col + 1, where + 1);
        }
    }
    if (path[where] == '?' || path[where] == 'L') {
        if (empty_square(row, col - 1) && !(!empty_square(row, col - 2) && empty_square(row + 1, col - 1) && empty_square(row - 1, col - 1))) {
            dfs(row, col - 1, where + 1);
        }
    }

    grid[row][col] = 0;

    return;
}

void solve() {
    cin >> path;

    dfs(0, 0, 0);
    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}


