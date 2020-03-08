// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 2e5 + 2;
ll arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll mx = arr[0], res = 0;
    for (int i = 1; i < n; i++) {
        res += max(0LL, mx-arr[i]);
        mx = max(mx, arr[i]);
    }

    cout << res << endl;

    return 0;
}
