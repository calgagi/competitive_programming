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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> ans;
    ans.push_back(p[0]);
    ans.push_back(p[1]);

    bool increase_mode = p[0] < p[1];
    for (int i = 2; i < n; i++) {
        if (increase_mode && p[i] > ans.back()) {
            ans.pop_back();
            ans.push_back(p[i]);
        } 
        else if (increase_mode) {
            increase_mode = 0;
            ans.push_back(p[i]);
        }
        else if (!increase_mode && p[i] < ans.back()) {
            ans.pop_back();
            ans.push_back(p[i]);
        }
        else if (!increase_mode) {
            increase_mode = 1;
            ans.push_back(p[i]);
        }
    }

    cout << ans.size() << endl;
    for (int& x : ans) {
        cout << x << " ";
    }
    cout << endl;

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
