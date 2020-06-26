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
    string s;
    cin >> s;

    vector<int> cnt(2, 0);

    for (char& c : s) {
        cnt[c-'0']++;
    }

    int num_moves = min(cnt[0], cnt[1]);

    if ((num_moves & 1)) {
        cout << "DA" << endl;
    } else {
        cout << "NET" << endl;
    }

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
