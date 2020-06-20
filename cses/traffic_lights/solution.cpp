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
    int x, n;
    cin >> x >> n;

    set<int, greater<int>> left;
    set<int> right;
    multiset<int> sz;
    sz.insert(x);
    left.insert(0);
    right.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        
        auto l = left.lower_bound(p)--;
        auto r = right.upper_bound(p);
        left.insert(p);
        right.insert(p);
        auto interval = sz.find(*r - *l);
        sz.insert(*r - p);
        sz.insert(p - *l);
        sz.erase(interval);

        cout << *--sz.end() << " ";
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
