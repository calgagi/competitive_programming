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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (!s.empty() && s.top() < a[i]) {
            int add = a[i];
            while (!s.empty() && s.top() < a[i]) {
                add = s.top(); 
                s.pop();
            }
            s.push(add);
        } else {
            s.push(a[i]);
        }
    }
        
    cout << (s.size() == 1 ? "YES" : "NO") << endl;

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
