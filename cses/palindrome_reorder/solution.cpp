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

    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'A']++;
    }

    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            odd++;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    string ans(n, ' ');
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            ans[n/2] = (char) i + 'A';
            cnt[i]--;
            break;
        }
    }
            
    for (int i = 0, j = 0; i < 26; i++) {
        while (cnt[i]) {
            ans[j] = ans[n-1-j] = (char) i + 'A';
            cnt[i] -= 2;
            j++;
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
