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

struct fenwick {
    map<int,map<int,int>> a;
    ll n = 1e9;
    
    int sum(ll i, int j) {
        int ans = 0;
        for (; i >= 0; i = (i & (i+1))-1) {
            ans += a[i][j];
        }
        return ans;
    }

    void update(ll i, int j, int k) {
        for (; i < n; i = (i | (i+1))) {
            a[i][j] += k;
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;

    fenwick f;

    while (n--) {
        int type, time, val;
        cin >> type >> time >> val;
        time--;
        if (type == 1) {
            f.update(time, val, 1);
        } else if (type == 2) {
            f.update(time, val, -1);
        } else {
            cout << f.sum(time, val) << endl;
        }
    }

    return 0;
}
