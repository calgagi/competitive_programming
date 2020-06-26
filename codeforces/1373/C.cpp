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

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    map<int,int> where;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            cur++;
        } else if (s[i] == '-') {
            cur--;
        }
        if (!where.count(cur)) {
            where[cur] = i;
        }
    }
        
    ll ans = 0;
    int i = 0;
    while (1) {
        if (!where.count(i-1)) {
            ans += n;
            break;
        }
        ans += where[i-1]+1;
        i--;
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
