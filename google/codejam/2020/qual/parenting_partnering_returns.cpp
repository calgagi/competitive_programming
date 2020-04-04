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

const int MAX = 24*60;

void solve() {
    int n;
    cin >> n;
    vector<ar<int,3>> act(n);
    for (int i = 0; i < n; i++) {
        cin >> act[i][0] >> act[i][1];
        act[i][2] = i;
    }

    sort(act.begin(), act.end());

    vector<char> ans(n);
    int c = -1, j = -1;
    for (int i = 0; i < n; i++) {
        if (c < act[i][0]) {
            c = act[i][1]-1;
            ans[act[i][2]] = 'C';
        } else if (j < act[i][0]) {
            j = act[i][1]-1;
            ans[act[i][2]] = 'J';
        }  else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    for (auto& x : ans) {
        cout << x;
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
