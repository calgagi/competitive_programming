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

const int MAX_N = 1e6;
vector<int> a, k;
int n, q;

bool test(int x) {
    int count = 0;

    for (int& i : a) {
        if (i <= x) {
            count++;
        }
    }

    for (int& i : k) {
        if (i < 0 && -i <= count) {
            count--;
        }
        else if (i > 0 && i <= x) {
            count++;
        }
    }

    return count > 0;
}
    

void solve() {
    cin >> n >> q;
    a.resize(n);
    k.resize(q);
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : k) {
        cin >> x;
    }

    if (!test(MAX_N)) {
        cout << 0 << endl;
        return;
    }

    int l = 1, r = MAX_N, ans = MAX_N;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (test(m)) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        } 
    }

    cout << ans << endl;

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
