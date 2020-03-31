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

int n, q;
const int MAX_N = 2e5+1, MAX = INT_MAX;
vector<int> nums;
vector<int> segment;

void update(int cur, int tl, int tr, int i, int v) {
    if (tl == tr) {
        segment[cur] = v;
        return;
    }
    int tm = tl+(tr-tl)/2;
    if (i <= tm) {
        update(cur*2, tl, tm, i, v);
    } else {
        update(cur*2+1, tm+1, tr, i, v);
    }
    segment[cur] = min(segment[cur*2+1], segment[cur*2]);
    return;
}

int query(int cur, int tl, int tr, int l, int r) {
    if (l > r) {
        return INT_MAX;
    } else if (tl == l && tr == r) {
        return segment[cur];
    }
    int tm = tl+(tr-tl)/2;
    return min(query(cur*2, tl, tm, l, min(r,tm)), query(cur*2+1, tm+1, tr, max(l,tm+1), r));
}
    

void build() {
    segment.assign(4*(n+1), INT_MAX);
    for (int i = 0; i < n; i++) {
        update(1, 0, n-1, i, nums[i]);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    cin >> n >> q;
    nums.resize(n);
    for (auto& i : nums) {
        cin >> i;
    }

    build();

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        if (t == 1) {
            update(1, 0, n-1, a, b+1);
        } else {
            cout << query(1, 0, n-1, a, b) << endl;
        }
    }

    return 0;
}
