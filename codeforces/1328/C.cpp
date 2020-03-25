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

void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    bool off = 0;
    string ans1 = "", ans2 = "";
    for (int i = 0; i < n; i++) {
        if (x[i] == '0') {
            ans1 += "0";
            ans2 += "0";
        } else if (x[i] == '1') {
            if (!off) {
                ans1 += "1";
                ans2 += "0";
                off = 1;
            } else {
                ans2 += "1";
                ans1 += "0";
            }
        } else if (x[i] == '2') {
            if (!off) {
                ans1 += "1";
                ans2 += "1";
            } else {
                ans2 += "2";
                ans1 += "0";
            }
        }
    }

    cout << ans1 << endl << ans2 << endl;
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
