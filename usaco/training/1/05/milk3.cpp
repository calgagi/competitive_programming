/*
ID: calgagi1
LANG: C++
TASK: milk3
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;


const int MAX = 21;
bool dp[MAX][MAX][MAX];
bool ans[MAX];
int cap[3];

void dfs(int a, int b, int c) {
    if (dp[a][b][c] == 1) {
        return;
    }
    dp[a][b][c] = 1;
    if (a == 0) {
        ans[c] = 1;
    }
    dfs(a-min(a, cap[2]-c), b, c+min(a, cap[2]-c));
    dfs(a-min(a, cap[1]-b), b+min(a, cap[1]-b), c);
    dfs(a+min(b, cap[0]-a), b-min(b, cap[0]-a), c);
    dfs(a, b-min(b, cap[2]-c), c+min(b, cap[2]-c));
    dfs(a, b+min(c, cap[1]-b), c-min(c, cap[1]-b));
    dfs(a+min(c, cap[0]-a), b, c-min(c, cap[0]-a));
}    

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("milk3.in", "r", stdin), *OUT = freopen("milk3.out", "w", stdout); 

    memset(ans, 0, sizeof(ans));
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 3; i++) {
        cin >> cap[i];
    }

    dfs(0, 0, cap[2]);

    bool f = true;
    for (int i = 0; i < MAX; i++) {
        if (ans[i] && !f) {
            cout << " " << i;
        } else if (ans[i]) {
            cout << i;
            f = false;
        }
    }
    cout << endl;

    return 0;
}
