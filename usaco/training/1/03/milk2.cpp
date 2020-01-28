/*
ID: calgagi1
LANG: C++
TASK: milk2
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
    FILE *IN = freopen("milk2.in", "r", stdin), *OUT = freopen("milk2.out", "w", stdout); 

    int n;
    cin >> n;
    vector<ii> intervals(n);
    for (int i = 0; i < n; i++) 
        cin >> intervals[i].first >> intervals[i].second;
    sort(intervals.begin(), intervals.end());

    // Find largest interval of continuous 
    int end = intervals[0].second, cur = 1, start = intervals[0].first;
    int ans_cow = end-start, ans_no = 0;

    while (cur < n) {
        int new_end = end;
        while (cur < n && intervals[cur].first <= end) {
            new_end = max(intervals[cur].second, new_end);
            cur++;
        }
        if (new_end == end) {
            if (cur >= n) continue;
            ans_no = max(ans_no, intervals[cur].first-end);
            start = intervals[cur].first;
            end = intervals[cur].second;
        } else {
            end = new_end;
            ans_cow = max(ans_cow, end-start);
        }
    }
        
    cout << ans_cow << " " << ans_no << endl;

    

    return 0;
}
