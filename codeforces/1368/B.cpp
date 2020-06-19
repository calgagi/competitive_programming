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
    ll k;
    cin >> k;
    
    const int letters = 10;
    vector<ll> ans(letters, 1);
    ll sum = 1;
    while (sum < k) {
        ll a = 0; 
        for (int i = 0; i < letters; i++) {
            if (ans[i] < ans[a]) {
                a = i;
            }
        }
        ans[a]++;
        sum = 1;
        for (int i = 0; i < letters; i++) {
            sum *= ans[i];
        }
    }

    const string cf = "codeforces";
    for (int i = 0; i < letters; i++) {
        for (ll j = 0; j < ans[i]; j++) {
            cout << cf[i];
        }
    }
    cout << endl;


    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
