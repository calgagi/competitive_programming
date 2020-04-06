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

vector<vector<int>> g;
vector<int> ans;

int dfs(int i) {
    int r = 0;
    for (int e : g[i]) {
        r += dfs(e);
    }
    ans[i] = r;
    return r+1;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        g[a-1].push_back(i+1);
    }
    
    dfs(0);
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    } 
    cout << endl;

    return 0;
}
