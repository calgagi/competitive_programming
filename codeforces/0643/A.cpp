// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    vector<int> t(n);
    for (auto& x : t) {
        cin >> x;
        x--;
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        vector<int> cur(n, 0);
        int c = n-1;
        for (int j = i; j < n; j++) {
            cur[t[j]]++;
            if (cur[t[j]] > cur[c] || (cur[c] == cur[t[j]] && c > t[j])) {
                c = t[j];
            }
            ans[c]++;
        }
        
        /* for (int i = 0; i < n; i++) { */
        /*     cout << ans[i] << (i<n-1?" ":""); */
        /* } */
        /* cout << endl; */
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i<n-1?" ":"");
    }
    cout << endl;

    return 0;
}
