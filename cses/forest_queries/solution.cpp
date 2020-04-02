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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            g[i][j] = x=='*'?1:0;
            /* cout << g[i][j] << " "; */
        }
        /* cout << endl; */
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
            /* cout << g[i][j] << " "; */
        }
        /* cout << endl; */
    }

    for (int i = 0; i < q; i++) {
        ii o, t;
        cin >> o.f >> o.s >> t.f >> t.s;
        if (t < o) {
            swap(o,t);
        }
        cout << g[t.f][t.s]+g[o.f-1][o.s-1]-g[t.f][o.s-1]-g[o.f-1][t.s] << endl;
    }
    

    return 0;
}
