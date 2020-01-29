/*
ID: calgagi1
LANG: C++
TASK: milk
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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("milk.in", "r", stdin), *OUT = freopen("milk.out", "w", stdout); 

    // Fractional knapsack :)
    int n, m;
    cin >> n >> m;
    vector<ii> p(m);
    for (int i = 0; i < m; i++) 
        cin >> p[i].first >> p[i].second;
    
    sort(p.begin(), p.end());

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += p[i].first * min(p[i].second, n);
        n -= min(p[i].second, n);
    } 
    cout << ans << endl;



    return 0;
}
