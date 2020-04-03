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
    vector<int> a(n), left(n, 0), right(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right[a[i]]++;
    }

    vector<ii> ans;

    int li = 0, ri = 0;
    while (ri+1 < n && right[ri+1] == 1) {
        ri++;
    } 
    /* cout << "ri: " << ri << endl; */

    for (int i = 0; i < n-1; i++) {
        right[a[i]]--;
        left[a[i]]++;
        if (right[a[i]] == 0) {
            ri = min(ri, a[i]-1);
        }
        while (li+1 < n && left[li+1] == 1) {
            li++;
        }
        while (ri+1 < n && right[ri+1] == 1) {
            ri++;
        }
        if (li == i+1 && ri == n-i-1) {
            ans.push_back({i+1, n-i-1});
        }
    }        

    cout << ans.size() << endl;
    for (auto& p : ans) {
        cout << p.f << " " << p.s << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
