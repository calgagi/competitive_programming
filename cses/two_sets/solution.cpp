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
    ll n;
    cin >> n;

    ll sum = ((n*(n+1))/2);
    if (sum & 1) {
        cout << "NO" << endl;
        return;
    }
    
    vector<ll> set1, set2;
    ll sum1 = 0, sum2 = 0;
    for (ll i = n; i >= 1; i--) {
        if (sum1 < sum2) {
            set1.push_back(i);
            sum1 += i;
        } else {
            set2.push_back(i);
            sum2 += i;
        }
    }
        
    cout << "YES" << endl;
    cout << set1.size() << endl;
    for (ll& x : set1) {
        cout << x << " ";
    }
    cout << endl;
    cout << set2.size() << endl;
    for (ll& x : set2) {
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
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
