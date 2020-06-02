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

vector<ll> cards;
const ll N = 1e9;

void preprocess() {
    ll s = 2, h = 1;
    while (s <= N) {
        cards.push_back(s);
        s += h*3 + 2;
        h++;
    }
    return;
}

void solve() {
    int n;
    cin >> n; 

    int ans = 0;
    for (int i = cards.size()-1; i >= 0; i--) {
        while (n >= cards[i]) {
            n -= cards[i];
            ans++;
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 

    preprocess();
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
