/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define double double double
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long long, long long>
#define ar array
#define f first
#define s second

int n;
const int MAX_N = 8;
vector<int> fact(MAX_N+1, 1);

int get_order(vector<int>& a) {
    int ans = 1;
    vector<bool> used(n+1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < a[i]; j++) {
            if (!used[j]) {
                ans += fact[n - (i+1)];
            }
        }
        used[a[i]] = 1;
    }
    
    return ans;
}

void solve() {
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    int a = get_order(p);
    int b = get_order(q);

    cout << abs(a - b) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 

    fact[0] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        fact[i] = fact[i-1] * i;
    }
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
