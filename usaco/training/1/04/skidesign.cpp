/*
ID: calgagi1
LANG: C++
TASK: skidesign
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("skidesign.in", "r", stdin), *OUT = freopen("skidesign.out", "w", stdout); 

    int N;    
    cin >> N;
    vector<ll> hills(N);
    ll start = INT_MAX, end = INT_MIN;
    for (auto& h : hills) {
        cin >> h;
        start = min(start, h);
        end = max(end, h);
    }

    ll best = LLONG_MAX;
    for (ll i = start; i <= end; i++) {
        ll tot = 0, range = i + 17;
        for (const auto& h : hills) {
            if (h < i || h > range) {
                tot += pow(min(abs(h-range), abs(h-i)), 2);
            }
        }
        // cerr << i << " " << tot << endl;
        best = min(best, tot);
    }
        
    cout << best << endl;

    return 0;
}
