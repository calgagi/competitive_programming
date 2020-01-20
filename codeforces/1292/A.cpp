// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

const int MAX_N = 1e5 + 10;
bool board[2][MAX_N];
int n;
int blockade_count = 0;

bool solve(int r, int c) {
    board[r][c] = !board[r][c];
    // Check if path exists from 0, 0 to 1, n-1: O(n) brute force
    // Total time: O(q*n)
    // Is there a faster way?
    //  Segment tree to find block = O(q*logn)
    //  Keep count of blockades somehow = O(q)
    //      How to keep count though?

    int opp = r==1?0:1;
    int mark = board[r][c]==1?1:-1;
    if (board[opp][c] == 1) {
        blockade_count += mark;
    }
    if (board[opp][c-1] == 1) {
        blockade_count += mark;
    }
    if (board[opp][c+1] == 1) {
        blockade_count += mark;
    }

    return blockade_count == 0;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 


    int q; 
    cin >> n >> q;
     
    memset(board, 0, sizeof(board));
    board[1][0] = 1;
    board[0][n+1] = 1;


    // keep track of num blockades
    for (int i = 0; i < q; i++) {
        int r, c; 
        cin >> r >> c; 
        r--;
        cout << (solve(r, c) ? "Yes" : "No") << endl;
    }
     

    return 0;
}
