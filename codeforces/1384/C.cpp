/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define f first
#define s second

vector<int> link(26);

int find(int a) {
    while (a != link[a]) {
        a = link[a];
    }
    return a;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    link[a] = b;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < 26; i++) {
        link[i] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            if (find(a[i] - 'a') != find(b[i] - 'a')) {
                ans++;
                unite(a[i] - 'a', b[i] - 'a');
            }
        } else if (a[i] > b[i]) {
            cout << -1 << endl;
            return;
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
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
