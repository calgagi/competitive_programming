// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int run(vector<vector<int> >& board) { 
    vector<vector<int> > dp(board.size()+1, vector<int>(board[0].size()+1, 0));
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            dp[i][j] = 1;
            if (!dp[i][j-1] || abs(board[i][j-1]-board[i][j]) <= K)
                dp[i][j] = max(dp[i][j], dp[i][j-1]+1);
            if (!dp[i-1][j] || abs(board[i-1][j]-board[i][j]) <= K)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            if ( 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int R, C, K;
        cin >> R >> C >> K;
        vector<vector<int> > board(R, vector<int>(C));
        for (int j = 0; j < R; j++)
           for (int k = 0; k < C; k++)
              cin >> board[j][k];
        cout << "Case #" << i+1 << ": " << run(board) << endl;  
    }

    return 0;
}
