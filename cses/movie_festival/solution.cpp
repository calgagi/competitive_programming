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
    
    int n;
    cin >> n;
    vector<ii> intervals(n);
    for (auto& interval : intervals) {
        cin >> interval.f >> interval.s;
    }

    sort(intervals.begin(), intervals.end(), [&](const ii& l, const ii& r) {
        return l.s == r.s ? l.f > r.s : l.s < r.s;  
    });

    int ans = 0, end = 0;
    for (int i = 0; i < n; i++) {
        if (end <= intervals[i].f) {
            ans++;
            end = intervals[i].s; 
        }
    }

    cout << ans << endl;

    return 0;
}
