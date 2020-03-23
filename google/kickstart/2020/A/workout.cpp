/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

vector<int> a;

struct compare {
    bool operator()(const ii& p, const ii& q) {
        return (a[p.first+1]-a[p.first]+p.second-1)/p.second <
               (a[q.first+1]-a[q.first]+q.second-1)/q.second;
    }
};
        

void solve() {
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<ii, vector<ii>, compare> pq;
    for (int i = 0; i < n-1; i++) {
        pq.push({i,1});
    }

    for (int i = 0; i < k; i++) {
        ii p = pq.top();
        pq.pop();
        pq.push({p.first, p.second+1});
    }

    ii p = pq.top();
    cout << (a[p.first+1]-a[p.first]+p.second-1)/p.second;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
