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
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (auto& i : p) {
        cin >> i;
    }

    sort(p.begin(), p.end());
    priority_queue<int> q;
    q.push(x-p[n-1]);
    int ans = 1;
    for (int i = n-2; i >= 0; i--) {
        if (p[i] <= q.top()) {
            ll a = q.top();
            q.pop();
            q.push(a-p[i]);
        } else {
            q.push(x-p[i]);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
