// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> pre(n+1, 0);
    vector<pair<int,int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        pre[--queries[i].first]++; pre[--queries[i].second+1]--;
    } 

    vector<pair<int,int>> to_sort(n);
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        tot += pre[i];
        to_sort[i] = {tot, i};
    }
    sort(to_sort.begin(), to_sort.end());
    sort(arr.begin(), arr.end());
    
    vector<long long> re_ordered(n);
    for (int i = 0; i < n; i++)
        re_ordered[to_sort[i].second] = arr[i];

    for (int i = 1; i < n; i++)
        re_ordered[i] += re_ordered[i-1];
    
    long long ans = 0;
    for (auto& p : queries) 
        ans += re_ordered[p.second] - (p.first==0?0:re_ordered[p.first-1]);
    cout << ans << endl;
        

    return 0;
}
