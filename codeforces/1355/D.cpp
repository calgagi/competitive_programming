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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int n, s;
    cin >> n >> s;

    vector<int> ans(n, 1);
    ans[n-1] = s-(n-1);
    if (ans[n-1] <= n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
        cout << n << endl;
    }

    return 0;
}
