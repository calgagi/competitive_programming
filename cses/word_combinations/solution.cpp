/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

const int A = 26, MAX_N = 5e3;
const ll MOD = 1e9 + 7;
string s;
int n;
ll dp[MAX_N + 1];

struct Node {
    vector<Node*> con;
    bool val = 0;
    Node() {
        con.assign(A, NULL);
    }
};

Node* trie = new Node;

int dfs(int where) {
    if (dp[where] != -1) {
        return dp[where];
    }

    dp[where] = 0;
    Node* it = trie;
    for (int i = where; i < n; i++) {
        it = it->con[s[i] - 'a'];
        if (!it) {
            break;
        }
        if (it->val) {
            dp[where] = (dp[where] + dfs(i+1)) % MOD;
        }
    }

    return dp[where];
} 

void solve() {
    cin >> s;
    n = s.length();
    int k;
    cin >> k;
    memset(dp, 255, sizeof(dp));

    for (int i = 0; i < k; i++) {
        string d;
        cin >> d;
        Node* it = trie;
        for (char j : d) {
            int idx = j - 'a';
            if (it->con[idx] == NULL) {
                it->con[idx] = new Node;
            }
            it = it->con[idx];
        } 
        it->val = 1;
    }

    dp[n] = 1;
    dfs(0); 
    cout << dp[0] << endl;

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
