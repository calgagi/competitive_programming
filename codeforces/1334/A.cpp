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

void solve() {
    int n;
    cin >> n;

    vector<int> plays(n), clears(n);
    for (int i = 0; i < n; i++) {
        cin >> plays[i] >> clears[i];
    }
        
    plays.insert(plays.begin(), 0);
    clears.insert(clears.begin(), 0);
    for (int i = 1; i <= n; i++) {
        if (clears[i] > plays[i]) {
            cout << "NO" << endl;
            return;
        }
        if (clears[i]-clears[i-1] > plays[i]-plays[i-1] || clears[i]-clears[i-1] < 0 || plays[i]-plays[i-1] < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
