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

    multiset<int> open;
    sort(p.begin(), p.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto o = open.lower_bound(p[i]);
        if (o == open.end()) {
            ans++;
            open.insert(x-p[i]);
        } else {
            int a = *o;
            open.erase(o);
        }
    }
            
    cout << ans << endl;

    return 0;
}
