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

    vector<ll> ans(4);
    ans[0] = 0;
    ans[1] = 6;
    ans[2] = 28;
    ans[3] = 96;
    for (ll i = 4; i < n; i++) {
        ll prev_board_size = i*i;
        ll new_elements = ((2LL*(i+1))-1);
        ll cur = prev_board_size * new_elements;
        cur -= 2LL*5;
        cur -= 3LL*4;
        cur -= 8LL*(i-4);
        cur += (new_elements*(new_elements-1))/2LL;
        cur -= 2LL;
        cur += ans.back();
        ans.push_back(cur);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

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
