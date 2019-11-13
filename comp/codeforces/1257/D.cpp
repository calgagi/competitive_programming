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
        for(auto& i : monsters) cin >> i;
        int h; cin >> h;
        vector<pair<int,int> > heroes(h);
        for(auto& p : heroes) cin >> p.x >> p.y;
        
        vector<vector<int> > dp(h+1, vector<int>(n+1, 0));
        forn(i, n+1) dp[0][i] = -1;
        
        fore(i, 1, h+1) {
            int streak = heroes[i-1].y;
            fore(j, 1, n+1) {
                // If can fight another monster
                if (heroes[i-1].x >= monsters[j-1]) {
                    if (dp[i-1][j-1] == -1) {
                        dp[i][j] = dp[i][j-1];
                        if (streak >= heroes[i-1].y) {
                            dp[i][j]++;
                            streak = 0;
                        }
                    } else {
                        dp[i][j] = dp[i-1][j-1]+1;
                        if (streak >= heroes[i-1].y) {
                            dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                            streak = 0;
                        }
                    }
                } else {
                    streak = 0;
                    dp[i][j] = dp[i-1][j];
                }
                streak++;
            }
        }
        forn(i, n+1)
            if (dp[h][i] == -1) {
                dp[h][n] = -1;
                break;
            }
        cout << dp[h][n] << endl;
    }
                 

    return 0;
}
