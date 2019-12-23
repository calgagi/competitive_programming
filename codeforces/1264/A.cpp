// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;
    int prev = -1, streak = 1;
    cin >> prev;
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        int a = -1; 
        if (i < n-1) cin >> a;
        if (prev == a) streak++;
        else {
            q.push({prev, streak});
            streak = 1;
            prev = a;
        }
         
    }
    int g = 0, s = 0, b = 0;

    int m = n/2;
    g = q.front().second;
    q.pop();
    m -= g;
    while (!q.empty() && s <= g && m-q.front().second >= 0) {
        s += q.front().second;
        m -= q.front().second;
        q.pop();
    }
    while (!q.empty() && (b <= g || m-q.front().second >= 0)) {
        b += q.front().second;
        m -= q.front().second;
        q.pop();
    }

    if (s == 0 || g == 0 || b == 0 || m < 0) {
        cout << "0 0 0\n";
    } else {
        cout << g << " " << s << " " << b << endl;
    }
   
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    while (t--)
        solve();
    

    return 0;
}
