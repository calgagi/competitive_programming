/*
ID: calgagi1
LANG: C++
TASK: socdist
*/
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

int n, m;
vector<pair<ll,ll>> intervals;

// try to place d spaces apart
bool success(ll d) {
    ll start = LLONG_MIN, prev = LLONG_MIN;
    ll x = n;
    /* cerr << d << " START" << endl; */
    for (int i = 0; x && i < m; i++) {
        start = max(intervals[i].first, prev);
        while (x && start <= intervals[i].second) {
            /* cerr << start << " "; */
            start += d;
            x--;
        }
        prev = start;
    }
    /* cerr << endl; */
    return x <= 0;
}
        

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("socdist.in", "r", stdin), *OUT = freopen("socdist.out", "w", stdout); 

    cin >> n >> m;
    ll l = LLONG_MAX, r = LLONG_MIN;
    intervals.resize(m);
    for (auto &p : intervals) {
        cin >> p.first >> p.second;
        l = min(p.first, l);
        r = max(p.second, r);
    }

    sort(intervals.begin(), intervals.end());
    ll a = r-l;
    l = 0, r = a;
    // binary search? O(mlogm)
    ll d = 1;
    /* cerr << l << " " << r << endl; */
    while (l <= r) {
        ll t = l + (r - l) / 2LL;
        if (success(t)) {
            d = t;
            l = t+1LL;
        } else {
            r = t-1LL;
        }
    }
    cout << d << endl;

    return 0;
}
