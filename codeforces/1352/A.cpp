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
    int n;
    cin >> n;
   
    int d = 1;
    vector<int> ans;
    while (n) {
        int x = n%10;
        if (x) {
            ans.push_back(x*d);
        }
        d *= 10;
        n /= 10;
    }

    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return;
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
