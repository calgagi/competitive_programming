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

struct comp {
    bool operator()(const ii& a, const ii& b) {
        int x = abs(a.first - a.second);
        int y = abs(b.first - b.second);
        if (x != y) {
            return x < y;
        }
        return a.first > b.first;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);

    priority_queue<ii, vector<ii>, comp> q;
    q.push({1, n});

    int x = 1;
    while (!q.empty()) {
        ii t = q.top();
        q.pop();
        
        int l = t.first, r = t.second;
        if (l > r) {
            continue;
        }
        if (((r-l+1)&1)) {
            if (a[(l+r)/2]) {
                continue;
            }
            a[(l+r)/2] = x;
            q.push({l, (l+r)/2-1});
            q.push({(l+r)/2+1, r});
        } else {
            if (a[(l+r-1)/2]) {
                continue;
            }
            a[(l+r-1)/2] = x;
            q.push({l, (l+r-1)/2-1});
            q.push({(l+r-1)/2+1, r});
        }
        x++;
    }
        
    for (int i = 1; i < n+1; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
    
int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
