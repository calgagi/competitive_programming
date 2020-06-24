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

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    int ans = INT_MAX;

    vector<int> cnt(3);
    const char bias = '1';
    int counter = 3;

    for (int b = 0, e = 0; e < n; e++) {
        cnt[s[e]-bias]++;
        if (cnt[s[e]-bias] == 1) {
            counter--;
        }

        while (counter == 0) {
            ans = min(ans, e-b+1);
            cnt[s[b]-bias]--;
            if (cnt[s[b]-bias] == 0) {
                counter++;
            }
            b++;
        }
    }

    cout << (ans == INT_MAX ? 0 : ans)  << endl;

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
