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
    ll a;
    string b;
    cin >> a;
    cin >> b;

    string bd = b.substr(b.find('.')+1);

    for (int i = b.length()-1; i >= 0; i--) {
        if (b[i] == '.') {
            b.pop_back();
            break;
        }
        b.pop_back();
    }

    ll bx = stoll(b)*100, by = stoll(bd);
    ll bc = bx + by;

    ll ans = bc * a;

    cout << ans/100 << endl;

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
