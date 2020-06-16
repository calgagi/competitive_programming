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

const int n = 8;
int ans = 0;
vector<ii> dir = {{-1, -1}, {-1, 0}, {-1, 1}};

bool good(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool check_board(vector<string>& board, int i, int j) {
    for (ii& d : dir) {
        for (int row = i + d.f, col = j + d.s; good(row, col); row += d.f, col += d.s) {
            if (board[row][col] == 'Q') {
                return 0;
            }
        }
    }
    return 1;
}

void build(vector<string>& board, int row) {
    if (row >= n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (board[row][i] != '*') {
            board[row][i] = 'Q';
            if (check_board(board, row, i)) {
                build(board, row+1);
            }
            board[row][i] = '.';
        }
    }
    return;
}        

void solve() {
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    build(board, 0);

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
