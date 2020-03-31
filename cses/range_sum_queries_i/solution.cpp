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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, q;
    cin >> n >> q;
    vector<ll> pre(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> pre[i+1];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i-1];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << endl;
    }

    return 0;
}
