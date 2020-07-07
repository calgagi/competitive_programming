/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>
 
using namespace std;
 
#define long long long
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long long, long long>
#define ar array
#define f first
#define s second
#define double long double
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<ii> ans;
    for (int i = 0; i < n; i++) {
        vector<ii> inv;
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                inv.push_back({a[j], j});
            }
        }
 
        sort(inv.begin(), inv.end(), greater<ii>());
 
        int mx = 0;
        for (int j = 0; j < (int) inv.size(); j++) {
            if (mx == inv[j].f) {
                cout << -1 << endl;
                return;
            }
            ans.push_back({i, inv[j].s});
        }
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].f+1 << " " << ans[i].s+1 << endl;
    }
 
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* 
