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

vector<vector<ii>> g;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    g.resize(n);
    a.assign(n-1, -1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }

    bool f = 0;
    for (int i = 0; !f && i < n; i++) {
        if (g[i].size() >= 3) {
            for (int j = 0; j <= 2; j++) {
                a[g[i][j].second] = j;
            }
            f = 1;
        }
    }

    int counter = f ? 3 : 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] == -1) {
            a[i] = counter++;
        }
    }
        
    for (int i = 0; i < n-1; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
