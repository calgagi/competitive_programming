// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    // The only time manhattan == regular is when y = y or x = x?
    long long ans = 0;
    int n; cin >> n;
    unordered_map<int,int> x;
    unordered_map<int,int> y;
    unordered_map<int,unordered_map<int,int>> same;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        ans += x[a] + y[b] - same[a][b];
        x[a]++;
        y[b]++;
        same[a][b]++;
    }

    cout << ans << endl;

    return 0;
}
