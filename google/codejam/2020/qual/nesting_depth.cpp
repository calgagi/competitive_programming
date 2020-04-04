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
    string in;
    cin >> in;

    int n = in.length();
    int cur = 0;
    string res = "";
    for (int i = 0; i < n; i++) {     
        int a = in[i]-'0';
        while (cur < a) {
            res += '(';
            cur++;
        }
        while (cur > a) {
            res += ')';
            cur--;
        }
        res += in[i];
    }
    while (cur != 0) {
        res += ')';
        cur--;
    }

    cout << res << endl;

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
    }

    return 0;
}
